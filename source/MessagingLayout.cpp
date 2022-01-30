#include <GamerText.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>

MessagingLayout::MessagingLayout() : Layout::Layout() {
    pu::ui::Color menuItemColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color menuItemSelectionColor = pu::ui::Color::FromHex("#6AE6FF");

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

    /* this->textRectangle = pu::ui::elm::Rectangle::New(10, 600, 800, 200, pu::ui::Color::FromHex("0xaaaaaa")); */
    /* this->textArea = pu::ui::elm::TextBlock::New(10, 605, std::string("Hello gamers")); */
    /* this->sendButton = pu::ui::elm::Button::New(400, 605, 200, 100, std::string("Send"), pu::ui::Color::FromHex("#000000"), pu::ui::Color::FromHex("#FFFFFF")); */
}
