#pragma once
#include <pu/Plutonium>

class MessageFrame {
    private:
        std::string message;
        bool i_am_sender = false;
        u32 v_offset;
        u32 h_offset;
        pu::ui::elm::Rectangle::Ref rectangle;
        pu::ui::elm::TextBlock::Ref textblock;

    public:
        MessageFrame(std::string message, bool i_am_sender);
        void set_offset(u32 horizontal, u32 vertical);
        void add_to_layout(pu::ui::Layout* layout); 
};
