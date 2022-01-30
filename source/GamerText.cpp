#include <GamerText.hpp>
#include <PhoneMenuLayout.hpp>
#include <MessagingLayout.hpp>
#include <MessageList.hpp>
#include <pu/ui/ui_Types.hpp>


void MainApplication::GotoMessaging()
{
    this->LoadLayout(this->messagingLayout);
    this->messagingLayout->spawn_keyboard();
}

void MainApplication::GotoListMessages()
{
    this->LoadLayout(this->messageList);
}

// Implement all the layout/application functions here
void MainApplication::OnLoad() {
    // Create the layout (calling the smart constructor above)
    this->phoneLayout = PhoneMenuLayout::New();
    this->messagingLayout = MessagingLayout::New();
    this->messageList = MessageList::New();

    /* this->messagingLayout->OnInputCallback([&](const u64, const u64, const u64, const TouchPoint)); */

    std::vector<pu::ui::elm::MenuItem::Ref> users = this->messageList->userMenu->GetItems();
    for(auto user : users)
    {
        user->AddOnKey(std::bind(&MainApplication::GotoMessaging, this));
    }

    this->phoneLayout->messageMenuItem->AddOnKey(std::bind(&MainApplication::GotoListMessages, this));

    // Load the layout. In applications layouts are loaded, not added into a container (you don't select an added layout, just load it from this function)
    // Simply explained: loading layout = the application will render that layout in the very next frame
    this->LoadLayout(this->messageList);

    // Set a function when input is caught. This input handling will be the first one to be handled (before Layout or any Elements)
    // Using a lambda function here to simplify things
    // You can use member functions via std::bind() C++ wrapper
}
