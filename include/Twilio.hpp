#pragma once
#include <string>



namespace Twilio {

    struct MemoryStruct {
    char *memory;
    size_t size;
    };

    void send_message(std::string& message_body) {}

    MemoryStruct get_messages() {}
}