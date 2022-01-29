#include <GamerText.hpp>
#include <PhoneMenuLayout.hpp>
#include <MessagingLayout.hpp>
#include <pu/ui/ui_Types.hpp>


void MainApplication::GotoMessaging()
{
    this->LoadLayout(this->messagingLayout);
}

// Implement all the layout/application functions here
void MainApplication::OnLoad() {
    // Create the layout (calling the smart constructor above)
    this->phoneLayout = PhoneMenuLayout::New();
    this->messagingLayout = MessagingLayout::New();

    this->phoneLayout->messageMenuItem->AddOnKey(std::bind(&MainApplication::GotoMessaging, this));

    // Load the layout. In applications layouts are loaded, not added into a container (you don't select an added layout, just load it from this function)
    // Simply explained: loading layout = the application will render that layout in the very next frame
    this->LoadLayout(this->phoneLayout);

    // Set a function when input is caught. This input handling will be the first one to be handled (before Layout or any Elements)
    // Using a lambda function here to simplify things
    // You can use member functions via std::bind() C++ wrapper
}
