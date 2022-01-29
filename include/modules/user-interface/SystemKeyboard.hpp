//
// Created by william on 2022-01-29.
//

#ifndef CONUHACKS_6_SYSTEMKEYBOARD_H
#define CONUHACKS_6_SYSTEMKEYBOARD_H


class SystemKeyboard {
    public:
        SystemKeyboard();

        std::string getUserInput(const std::string &guide_text, const std::string &initial_text, int max_len);

    private:
        std::string userMessage;
};


#endif //CONUHACKS_6_SYSTEMKEYBOARD_H
