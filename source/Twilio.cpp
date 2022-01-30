#include <curl/curl.h>
#include <sstream>
#include <Twilio.hpp>
#include <json.hpp>
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

Twilio::Twilio() {

}

void Twilio::send_message(std::string message_body)
{
    // Make a POST request to the twilio API. 
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    std::string account_sid("48d506c54c7b41dcb3dfc600384ff842CA");
    std::string auth_token("92a624ff895c02b0d57419106b35fac2");
    std::string from_number = "+18676709701";
    std::string to_number = "+19028059374"; // Will
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

