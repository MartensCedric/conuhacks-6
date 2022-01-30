//
// Created by william on 2022-01-29.
//

#ifndef CONUHACKS_6_SYSTEMKEYBOARD_H
#define CONUHACKS_6_SYSTEMKEYBOARD_H

#include <pu/Plutonium>
#include <pu/ui/ui_Types.hpp>

#include <MessagingLayout.hpp>

class SystemKeyboard {
    public:
        SystemKeyboard();

        void attachKeyboard();
        std::string getUserInput(const std::string &guide_text, const std::string &initial_text, int max_len);

    private:

        void userInputCallback();
};


#endif //CONUHACKS_6_SYSTEMKEYBOARD_H
