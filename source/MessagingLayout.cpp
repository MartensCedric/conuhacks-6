#include <GamerText.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>

#include <SystemKeyboard.hpp>

MessagingLayout::MessagingLayout() : Layout::Layout() {
    pu::ui::elm::Rectangle::Ref darkscreen = pu::ui::elm::Rectangle::New(0, 0, 1920, 1080, pu::ui::Color::FromHex("#222222"));
    this->Add(darkscreen);

    frames.push_back(MessageFrame(std::string("Greetings Gamer"), false));
    frames.push_back(MessageFrame(std::string("Ligma"), true));
    frames.push_back(MessageFrame(std::string("Ligma what?"), false));
    frames.push_back(MessageFrame(std::string("Ligma gamers"), true));
    frames.push_back(MessageFrame(std::string("Ligma balls"), true));

    for(int i = 0; i < frames.size(); i++)
    {
        frames[i].set_offset(15, 100*i + 15);
        frames[i].add_to_layout(this);
    }

    // Input message to send fields
    this->textRectangle = pu::ui::elm::Rectangle::New(0, 670, 1300, 50, pu::ui::Color::FromHex("#aaaaaa"));
    this->textArea = pu::ui::elm::TextBlock::New(10, 675, std::string("Hello gamers"));
    this->sendButton = pu::ui::elm::Button::New(1175, 675, 90, 40, std::string("Send"), pu::ui::Color::FromHex("#000000"),
                                                pu::ui::Color::FromHex("#FFFFFF"));

    this->Add(this->textRectangle);
//    this->Add(this->textArea);
    this->Add(this->sendButton);

    SystemKeyboard keyboard(this, this->textArea);
    keyboard.attachKeyboard(this, this->textArea);
}
