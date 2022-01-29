#include <MainApplication.hpp>
#include <pu/ui/ui_Types.hpp>

// Implement all the layout/application functions here

PhoneMenuLayout::PhoneMenuLayout() : Layout::Layout() {
    // Create the TextBlock instance with the text we want
    pu::ui::Color menuItemColor = pu::ui::Color(255, 255, 255, 255);
    pu::ui::Color menuItemSelectionColor = pu::ui::Color(255, 0, 0, 255);

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

void MainApplication::OnLoad() {
    // Create the layout (calling the smart constructor above)
    this->layout = PhoneMenuLayout::New();

    // Load the layout. In applications layouts are loaded, not added into a container (you don't select an added layout, just load it from this function)
    // Simply explained: loading layout = the application will render that layout in the very next frame
    this->LoadLayout(this->layout);

    // Set a function when input is caught. This input handling will be the first one to be handled (before Layout or any Elements)
    // Using a lambda function here to simplify things
    // You can use member functions via std::bind() C++ wrapper
}
