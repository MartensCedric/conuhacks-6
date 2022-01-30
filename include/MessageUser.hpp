#pragma once
#include <pu/Plutonium>
#include <string>

class MessageUser {
    public:
        pu::ui::elm::MenuItem::Ref menuItem;
        std::string name;
        std::string message;
        MessageUser(std::string name, std::string message);
};
