#include <GamerText.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>

// Implement all the layout/application functions here

MessagingLayout::MessagingLayout() : Layout::Layout() {
    pu::ui::Color menuItemColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color menuItemSelectionColor = pu::ui::Color::FromHex("#6AE6FF");

    messages.push_back(pu::ui::elm::TextBlock::New(0, 0, std::string("Greetings Gamer")));
    messages.push_back(pu::ui::elm::TextBlock::New(0, 0, std::string("Ligma")));
    messages.push_back(pu::ui::elm::TextBlock::New(0, 0, std::string("What is ligma?")));

    for(auto message : messages)
    {
        this->Add(message);
    }
}
