#pragma once
#include <string>
#include <vector>

struct MemoryStruct {
char *memory;
size_t size;
};

struct UserMessage {
    std::string body;
    bool inbound;
};

void text_account(std::string account_sid, std::string auth_token, std::string message_body);
std::vector<UserMessage> get_messages(std::string account_sid, std::string auth_token);
