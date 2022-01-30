#include <MessageFrame.hpp>
#include <pu/Plutonium>

MessageFrame::MessageFrame(std::string message, bool i_am_sender)
{
    this->message = message;
    this->i_am_sender = i_am_sender;
}

void MessageFrame::set_offset(u32 vertical, u32 horizontal)
{
    this->v_offset = vertical;
    this->h_offset = horizontal;
}

void MessageFrame::add_to_layout(pu::ui::Layout* layout)
{
        this->rectangle = pu::ui::elm::Rectangle::New(this->h_offset, this->v_offset, 100, 100, pu::ui::Color(0, 0, 255, 255));
        this->textblock = pu::ui::elm::TextBlock::New(this->h_offset, this->v_offset, this->message);
    
    layout->Add(this->rectangle);
    layout->Add(this->textblock);
}
