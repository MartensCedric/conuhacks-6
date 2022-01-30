#include <pu/Plutonium>
#include <vector>
#include <MessageList.hpp>
#include <MessageUser.hpp>

MessageList::MessageList()
{
    pu::ui::elm::Rectangle::Ref darkscreen = pu::ui::elm::Rectangle::New(0, 0, 1920, 1080, pu::ui::Color::FromHex("#222222"));
    this->Add(darkscreen);

    frames.push_back(MessageUser(std::string("Dad"), std::string("Are you winning son?")));
    frames.push_back(MessageUser(std::string("Gamer Bill"), std::string("1v1 me when?")));
    frames.push_back(MessageUser(std::string("Mom"), std::string("Love you <3 <3")));
    frames.push_back(MessageUser(std::string("Girlfriend"), std::string("When are we smashing? (smash ultimate)")));

    for(int i = 0; i < frames.size(); i++)
    {
        frames[i].set_offset(15, 100*i + 15);
        frames[i].add_to_layout(this);
    }
}
