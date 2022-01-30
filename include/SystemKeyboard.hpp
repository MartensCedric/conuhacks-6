//
// Created by william on 2022-01-29.
//

#ifndef CONUHACKS_6_SYSTEMKEYBOARD_H
#define CONUHACKS_6_SYSTEMKEYBOARD_H

#include <pu/Plutonium>

class SystemKeyboard {
    public:
        SystemKeyboard();

        void attachKeyboard(pu::ui::elm::MenuItem::Ref menuItem, void (*callBackFunction)(std::string));

    private:
        std::string getUserInput(const std::string &guide_text, const std::string &initial_text, int max_len);
        void userInputCallback();
};


#endif //CONUHACKS_6_SYSTEMKEYBOARD_H
