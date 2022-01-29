
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
