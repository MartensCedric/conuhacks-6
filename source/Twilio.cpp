#include <curl/curl.h>
#include <sstream>
#include "../include/Twilio.hpp"
#include <json>



void send_message(std::string &message_body) {

    // Make a POST request to the twilio API. 
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    std::string account_sid = "AC248ff483006cfd3bcd14b7c45c605d84";
    std::string auth_token = "01a23f5251caa94b88c78bc2c1f91d77";
    std::string from_number = "+18676709701";
    std::string to_number = "+15142454864"; // koa
    // std::string to_number = "+14388233551"; // tim
    // std::string to_number = "+15148257746"; // cedric
    // std::string to_number = "+19028059374" // will

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

    return;
}

void get_messages() {


}

