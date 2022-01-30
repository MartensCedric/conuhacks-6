#include <GamerText.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>

MessagingLayout::MessagingLayout() : Layout::Layout() {
    pu::ui::Color menuItemColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color menuItemSelectionColor = pu::ui::Color::FromHex("#6AE6FF");

    frames.push_back(MessageFrame(std::string("Greetings Gamer"), false));
    frames.push_back(MessageFrame(std::string("Ligma"), true));
    frames.push_back(MessageFrame(std::string("Ligma what?"), false));
    frames.push_back(MessageFrame(std::string("ligma gamers"), true));

    for(auto frame : frames)
    {
        frame.set_offset(0, 0);
        frame.add_to_layout(this);
    }
}
