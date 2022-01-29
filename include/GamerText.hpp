#include <pu/Plutonium>
#include <PhoneMenuLayout.hpp>
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
