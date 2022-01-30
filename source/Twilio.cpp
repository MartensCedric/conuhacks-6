#include <curl/curl.h>
#include <sstream>
#include "../include/Twilio.hpp"
#include "../include/json.hpp"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <vector>

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

void send_message(std::string account_sid, std::string auth_token, std::string &message_body) 
{
    // Make a POST request to the twilio API. 
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    std::string from_number = "+18676709701";
    std::string to_number = "+15148257746"; // koa

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

    get_messages(account_sid, auth_token);
}

 std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }

std::vector<UserMessage> get_messages(std::string account_sid, std::string auth_token)
{   
    std::vector<UserMessage> userMessages;
    const std::string url_prefix("https://api.twilio.com/2010-04-01/Accounts/");
    const std::string url_suffix("/Messages.json");
    const std::string url = url_prefix + account_sid + url_suffix;

    CURL* curl = curl_easy_init();

    // Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token.c_str());

    // Don't wait forever, time out after 10 seconds.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200)
    {
        std::cout << "\nGot successful response from " << url << std::endl;

        // Response looks good - done using Curl now.  Try to parse the results
        // and print them out.
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            std::cout << "Successfully parsed JSON data" << std::endl;
            std::cout << "\nJSON data received:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;

            auto messages = jsonData["messages"];
            
            for(auto message : messages)
            {
                UserMessage userMsg;

                std::string body = message["body"].asString();
                std::string direction = message["direction"].asString();
                bool inbound = direction.compare("outbound-api") != 0;

                userMsg.body = body;
                userMsg.inbound = inbound;

                std::cout << body << std::endl;

                if(inbound)
                    std::cout << "true" << std::endl;
                else
                    std::cout << "false" << std::endl;

                userMessages.push_back(userMsg);
            }


            /* const std::string dateString(jsonData["date"].asString()); */
            /* const std::size_t unixTimeMs( */
            /*         jsonData["milliseconds_since_epoch"].asUInt64()); */
            /* const std::string timeString(jsonData["time"].asString()); */

            /* std::cout << "Natively parsed:" << std::endl; */
            /* std::cout << "\tDate string: " << dateString << std::endl; */
            /* std::cout << "\tUnix timeMs: " << unixTimeMs << std::endl; */
            /* std::cout << "\tTime string: " << timeString << std::endl; */
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Could not parse HTTP data as JSON" << std::endl;
            std::cout << "HTTP data was:\n" << *httpData.get() << std::endl;
        }
    }
    else
    {
        std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
    }

    return userMessages;
}

