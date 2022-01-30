#include <pu/Plutonium>
#include <vector>
#include <MessageList.hpp>
#include <MessageUser.hpp>

MessageList::MessageList()
{
    pu::ui::elm::Rectangle::Ref darkscreen = pu::ui::elm::Rectangle::New(0, 0, 1920, 1080, pu::ui::Color::FromHex("#222222"));
    this->Add(darkscreen);

    pu::ui::Color itemColor = pu::ui::Color::FromHex("#29BAE8");
    pu::ui::Color selectColor = pu::ui::Color::FromHex("#6AE6FF");


    users.push_back(MessageUser(std::string("Dad"), std::string("Are you winning son?")));
    users.push_back(MessageUser(std::string("Gamer Bill"), std::string("1v1 me when?")));
    users.push_back(MessageUser(std::string("Mom"), std::string("Love you <3 <3")));
    users.push_back(MessageUser(std::string("Girlfriend"), std::string("When are we smashing? (smash ultimate)")));
    users.push_back(MessageUser(std::string("Nik D"), std::string("Want to trade my Alakazam for your Golem?")));
    users.push_back(MessageUser(std::string("Peter G"), std::string("LGTM")));
    users.push_back(MessageUser(std::string("Mike LK"), std::string("Need help for COMP442!")));
    users.push_back(MessageUser(std::string("Ke'Koa"), std::string("top kek m8")));

    this->userMenu = pu::ui::elm::Menu::New(0,0, pu::ui::render::ScreenWidth, itemColor, selectColor, 100, users.size());

    for(int i = 0; i < users.size(); i++)
    {
        this->userMenu->AddItem(users[i].menuItem);
    }
    this->Add(this->userMenu);
}
