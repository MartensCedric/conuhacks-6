#include <GamerText.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>

#include <SystemKeyboard.hpp>
#include <Twilio.hpp>

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
    this->textArea = pu::ui::elm::TextBlock::New(105, 675, std::string("Hello gamers"));
    this->sendButton = pu::ui::elm::Button::New(1175, 675, 90, 40, std::string("Send"), pu::ui::Color::FromHex("#000000"),
                                                pu::ui::Color::FromHex("#FFFFFF"));
    this->backButton = pu::ui::elm::Button::New(10, 675, 90, 40, std::string("Back"), pu::ui::Color::FromHex("#000000"),
                                                pu::ui::Color::FromHex("#FFFFFF"));

    this->Add(this->textRectangle);
    this->Add(this->textArea);
    this->Add(this->sendButton);
    this->Add(this->backButton);

    this->sendButton->SetOnClick([&]() {
        this->send_message();
    });
}

void MessagingLayout::spawn_keyboard()
{
    SystemKeyboard keyboard;
    this->textArea->SetText(keyboard.getUserInput("", "", 250));
}

void MessagingLayout::send_message()
{
    std::string account_sid("48d506c54c7b41dcb3dfc600384ff842CA");
    std::string auth_token("92a624ff895c02b0d57419106b35fac2");

    text_account(account_sid, auth_token, this->textArea->GetText());

    this->append_message(this->textArea->GetText(), true);

    this->textArea->SetText("");
}

void MessagingLayout::append_message(std::string message, bool i_am_sender) {
    frames.push_back(MessageFrame(message, i_am_sender));
    int frameIndex = frames.size()-1;
    frames[frameIndex].set_offset(15, 100*frameIndex + 15);
    frames[frameIndex].add_to_layout(this);
}