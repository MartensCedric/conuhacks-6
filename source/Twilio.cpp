#include <curl/curl.h>
#include <sstream>
#include "../include/Twilio.hpp"
#include "../include/json.hpp"

void send_message(std::string &message_body) 
{
    // Make a POST request to the twilio API. 
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    std::string account_sid = "AC248ff483006cfd3bcd14b7c45c605d84";
    std::string auth_token = "01a23f5251caa94b88c78bc2c1f91d77";
    std::string from_number = "+18676709701";
    std::string to_number = "+15142454864"; // koa

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
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return;
}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(!ptr) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}

MemoryStruct get_messages() 
{
    std::string account_sid = "AC248ff483006cfd3bcd14b7c45c605d84";
    std::string auth_token = "01a23f5251caa94b88c78bc2c1f91d77";
    
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
    chunk.size = 0;    /* no data at this point */

    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    std::stringstream url;
    std::string url_string;
    url << "https://api.twilio.com/2010-04-01/Accounts/" << account_sid
            << "/Messages.json";
    url_string = url.str();

    curl_easy_setopt(curl, CURLOPT_URL, url_string.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    else {
        printf("%lu bytes retrieved\n", (unsigned long)chunk.size);
    }
    /* always cleanup */
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(chunk.memory);
}

