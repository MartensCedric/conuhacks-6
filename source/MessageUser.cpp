#include <MessageUser.hpp>
#include <pu/Plutonium>

MessageUser::MessageUser(std::string name, std::string message)
{
    this->name = name;
    this->message = message;
    this->menuItem = pu::ui::elm::MenuItem::New(name + ": " + message);
}

