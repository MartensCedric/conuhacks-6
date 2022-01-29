#include <GamerText.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>

// Implement all the layout/application functions here

MessagingLayout::MessagingLayout() : Layout::Layout() {
    // Create the TextBlock instance with the text we want
    pu::ui::Color menuItemColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color menuItemSelectionColor = pu::ui::Color::FromHex("#6AE6FF");
}
