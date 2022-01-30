#pragma once
#include <pu/Plutonium>

class MessageUser {
    private:
        u32 v_offset;
        u32 h_offset;
        std::string name;
        std::string message;
        pu::ui::elm::Rectangle::Ref rectangle;
        pu::ui::elm::TextBlock::Ref nameTextBlock;
        pu::ui::elm::TextBlock::Ref messageTextBlock;

    public:
        MessageUser(std::string name, std::string message);
        void set_offset(u32 horizontal, u32 vertical);
        void add_to_layout(pu::ui::Layout* layout); 
};
