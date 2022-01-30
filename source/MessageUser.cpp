#include <MessageUser.hpp>
#include <pu/Plutonium>

MessageUser::MessageUser(std::string name, std::string message)
{
    this->name = name;
    this->message = message;
}

void MessageUser::set_offset(u32 horizontal, u32 vertical)
{
    this->h_offset = horizontal;
    this->v_offset = vertical;
}

void MessageUser::add_to_layout(pu::ui::Layout* layout)
{
    pu::ui::Color textColor = pu::ui::Color::FromHex("#000000");
    pu::ui::Color bgColor = pu::ui::Color::FromHex("#BBBBBB");

    this->rectangle = pu::ui::elm::Rectangle::New(this->h_offset, this->v_offset, 1000, 150, bgColor);
    this->nameTextBlock = pu::ui::elm::TextBlock::New(this->h_offset + 10, this->v_offset + 10, this->name);
    this->messageTextBlock = pu::ui::elm::TextBlock::New(this->h_offset + 10, this->v_offset + 10, this->message);
    
    layout->Add(this->rectangle);
    layout->Add(this->nameTextBlock);
    layout->Add(this->messageTextBlock);
}
