
#pragma once

// Include Plutonium's main header
#include <pu/Plutonium>
#include <vector>
#include <MessageUser.hpp>

// Define your main layout as a class inheriting from pu::Layout
class MessageList : public pu::ui::Layout {
    private:
        std::vector<MessageUser> users;
    public:
        pu::ui::elm::Menu::Ref userMenu;
        MessageList();

        // Have ::Ref alias and ::New() static constructor
        PU_SMART_CTOR(MessageList)
};

