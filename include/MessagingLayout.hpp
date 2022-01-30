
#pragma once

// Include Plutonium's main header
#include <pu/Plutonium>
#include <vector>
#include <MessageFrame.hpp>


// Define your main layout as a class inheriting from pu::Layout
class MessagingLayout : public pu::ui::Layout {
    private:
        std::vector<MessageFrame> frames;
        pu::ui::elm::Rectangle::Ref textRectangle;
        pu::ui::elm::TextBlock::Ref textArea;
        pu::ui::elm::Button::Ref sendButton;

    public:
        MessagingLayout();
        void spawn_keyboard();
        void send_message();
        void append_message(std::string message, bool i_am_sender);

        pu::ui::elm::Button::Ref backButton;

        // Have ::Ref alias and ::New() static constructor
        PU_SMART_CTOR(MessagingLayout)
};

