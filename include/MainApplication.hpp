
#pragma once

// Include Plutonium's main header
#include <pu/Plutonium>

// Define your main layout as a class inheriting from pu::Layout
class PhoneMenuLayout : public pu::ui::Layout {
    private:
        pu::ui::elm::Menu::Ref phoneMenu;
        pu::ui::elm::MenuItem::Ref messageMenuItem;
        pu::ui::elm::MenuItem::Ref contactsMenuItem;
        pu::ui::elm::MenuItem::Ref settingsMenuItem;

    public:

        PhoneMenuLayout();

        // Have ::Ref alias and ::New() static constructor
        PU_SMART_CTOR(PhoneMenuLayout)
};

// Define your application (can't instantiate base class, so need to make a derived one)
class MainApplication : public pu::ui::Application {
    private:

        // Layout instance
        PhoneMenuLayout::Ref layout;
    
    public:
        using Application::Application;
        PU_SMART_CTOR(MainApplication)

        // We need to define this, and use it to initialize everything
        void OnLoad() override;
};
