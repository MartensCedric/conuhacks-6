#pragma once
#include <string>


class Twilio {

    public:
        struct MemoryStruct {
            char *memory;
            size_t size;
        };

        Twilio();

        void send_message(std::string message_body);

        MemoryStruct get_messages();
};