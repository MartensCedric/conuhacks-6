#pragma once
#include <string>


struct MemoryStruct {
char *memory;
size_t size;
};


void send_message(std::string &message_body);
std::string get_messages(std::string account_sid, std::string auth_token);