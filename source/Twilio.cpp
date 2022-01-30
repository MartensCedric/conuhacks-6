#include <curl/curl.h>
#include <sstream>
#include "../include/Twilio.hpp"
#include "../include/json.hpp"
#include <iostream>

size_t _null_write(
        char *ptr, 
        size_t size, 
        size_t nmemb, 
        void *userdata)
{
        return size*nmemb;
}

size_t _stream_write(
        char *ptr,
        size_t size,
        size_t nmemb,
        void *userdata) 
{
        size_t response_size = size * nmemb;
        std::stringstream *ss = (std::stringstream*)userdata;
        ss->write(ptr, response_size);
        return response_size;
}

void send_message(std::string &message_body) 
{
    // Make a POST request to the twilio API. 
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    std::string account_sid("48d506c54c7b41dcb3dfc600384ff842CA");
    std::string auth_token("92a624ff895c02b0d57419106b35fac2");
    std::string from_number = "+18676709701";
    std::string to_number = "+15148257746"; // koa
    std::string temp = "";

        for (int i=account_sid.length()-1; i>=0; i--)
                 temp += account_sid[i];
        account_sid = temp;

        temp = "";
        for (int i=auth_token.length()-1; i>=0; i--)
                temp +=  auth_token[i];
        auth_token = temp;

    std::stringstream url;
    std::string url_string;
    url << "https://api.twilio.com/2010-04-01/Accounts/" << account_sid
            << "/Messages";
    url_string = url.str();

    // Percent encode special characters
    char *message_body_escaped = curl_easy_escape(
            curl, 
            message_body.c_str(), 
            0
    );

    std::stringstream parameters;
    std::string parameter_string;
    parameters << "To=" << to_number << "&From=" << from_number 
            << "&Body=" << message_body_escaped;
    parameter_string = parameters.str();

    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_URL, url_string.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameter_string.c_str());
    curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token.c_str());

    /* always cleanup */
        CURLcode res = curl_easy_perform(curl);
        curl_free(message_body_escaped);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    std::string jsonRaw = get_messages(account_sid, auth_token);
    std::cout << jsonRaw << std::endl;
}

static std::string *DownloadedResponse;

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{

    // Is there anything in the buffer?  
    if (buffer_in != NULL)  
    {
        // Append the data to the buffer    
        buffer_in->append(data, size * nmemb);

        // How much did we write?   
        DownloadedResponse = buffer_in;

        return size * nmemb;  
    }

    return 0;

}   


std::string get_messages(std::string account_sid, std::string auth_token)
{   
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers=NULL; // init to NULL is important 
    std::ostringstream oss;
    headers = curl_slist_append(headers, "Accept: application/json");  
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8"); 
    curl = curl_easy_init();

    if (curl) 
    {
        std::string url_prefix("https://api.twilio.com/2010-04-01/Accounts/");
        std::string url_suffix("/Messages.json?PageSize=100&Page=0"); 
        std::string url = url_prefix + account_sid + url_suffix;
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET,1); 
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writer);
        curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token.c_str());
        res = curl_easy_perform(curl);

        if (CURLE_OK == res) 
        { 
            char *ct;         
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == res) && ct)
            {
                return *DownloadedResponse;
            }
        }
    }

    curl_slist_free_all(headers);
}


// static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
// {
//   size_t realsize = size * nmemb;
//   struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
//   char *ptr = realloc(mem->memory, mem->size + realsize + 1);
//   if(!ptr) {
//     /* out of memory! */
//     printf("not enough memory (realloc returned NULL)\n");
//     return 0;
//   }
 
//   mem->memory = ptr;
//   memcpy(&(mem->memory[mem->size]), contents, realsize);
//   mem->size += realsize;
//   mem->memory[mem->size] = 0;
 
//   return realsize;
// }

// MemoryStruct get_messages() 
// {

//     std::string account_sid("48d506c54c7b41dcb3dfc600384ff842CA");
//     std::string auth_token("92a624ff895c02b0d57419106b35fac2");

//         for (int i=account_sid.length()-1; i>=0; i--)
//                  temp += account_sid[i];
//         account_sid = temp;

//         temp = "";
//         for (int i=auth_token.length()-1; i>=0; i--)
//                 temp +=  auth_token[i];
//         auth_token = temp;
    
//     struct MemoryStruct chunk;
//     chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
//     chunk.size = 0;    /* no data at this point */

//     CURL *curl;
//     curl_global_init(CURL_GLOBAL_ALL);
//     curl = curl_easy_init();

//     std::stringstream url;
//     std::string url_string;

//         for (int i = 0; i < account_sid.size(); i++)
//                 account_sid[i] =  account_sid[i]^'z';

//         for (int i = 0; i < auth_token.size(); i++)
//                 auth_token[i] =  auth_token[i]^'z';



//     url << "https://api.twilio.com/2010-04-01/Accounts/" << account_sid
//             << "/Messages.json";
//     url_string = url.str();

//     curl_easy_setopt(curl, CURLOPT_URL, url_string.c_str());
//     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
//     curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

//     res = curl_easy_perform(curl);
//     /* Check for errors */
//     if(res != CURLE_OK)
//         fprintf(stderr, "curl_easy_perform() failed: %s\n",
//               curl_easy_strerror(res));
//     else {
//         printf("%lu bytes retrieved\n", (unsigned long)chunk.size);
//     }
//     /* always cleanup */
//     curl_easy_cleanup(curl);
//     curl_global_cleanup();
//     free(chunk.memory);
// }

