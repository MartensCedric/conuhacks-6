#include <GamerText.hpp>
#include <PhoneMenuLayout.hpp>
#include <pu/ui/ui_Types.hpp>

// Implement all the layout/application functions here

PhoneMenuLayout::PhoneMenuLayout() : Layout::Layout() {
    // Create the TextBlock instance with the text we want
    pu::ui::Color menuItemColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color menuItemSelectionColor = pu::ui::Color::FromHex("#6AE6FF");

    this->phoneMenu = pu::ui::elm::Menu::New(0, 160, pu::ui::render::ScreenWidth, menuItemColor, menuItemSelectionColor, 80, 560 / 3);

    this->messageMenuItem = pu::ui::elm::MenuItem::New(std::string("Messages"));

    this->contactsMenuItem = pu::ui::elm::MenuItem::New(std::string("Contacts"));

    this->settingsMenuItem = pu::ui::elm::MenuItem::New(std::string("Settings"));

    this->phoneMenu->AddItem(this->messageMenuItem);
    this->phoneMenu->AddItem(this->contactsMenuItem);
    this->phoneMenu->AddItem(this->settingsMenuItem);
    
    // Add the instance to the layout. IMPORTANT! this MUST be done for them to be used, having them as members is not enough (just a simple way to keep them)
    this->Add(this->phoneMenu);
}

