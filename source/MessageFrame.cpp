#include <MessageFrame.hpp>
#include <pu/Plutonium>

MessageFrame::MessageFrame(std::string message, bool i_am_sender)
{
    this->message = message;
    this->i_am_sender = i_am_sender;
}

void MessageFrame::set_offset(u32 horizontal, u32 vertical)
{
    this->h_offset = horizontal;
    this->v_offset = vertical;
}

void MessageFrame::add_to_layout(pu::ui::Layout* layout)
{
    pu::ui::Color senderColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color fromColor = pu::ui::Color::FromHex("#6AE6FF");

    pu::ui::Color colorToUse;
    u32 h_extra_offset = 0;

    if(i_am_sender)
    {
        colorToUse = senderColor;
        h_extra_offset = 600;
    }
    else
    {
        colorToUse = fromColor;
    }
    this->rectangle = pu::ui::elm::Rectangle::New(this->h_offset + h_extra_offset, this->v_offset, 800, 200, colorToUse);
    this->textblock = pu::ui::elm::TextBlock::New(this->h_offset + h_extra_offset, this->v_offset, this->message);
    
    layout->Add(this->rectangle);
    layout->Add(this->textblock);
}
