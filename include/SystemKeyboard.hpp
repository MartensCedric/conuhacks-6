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
        SystemKeyboard(MessagingLayout::Ref layout, pu::ui::elm::TextBlock::Ref textBlock);

        void attachKeyboard(MessagingLayout::Ref layout, pu::ui::elm::TextBlock::Ref textBlock);

    private:
        std::string getUserInput(const std::string &guide_text, const std::string &initial_text, int max_len);
        void userInputCallback();

        MessagingLayout::Ref layout;
        pu::ui::elm::TextBlock::Ref textBlock;
};


#endif //CONUHACKS_6_SYSTEMKEYBOARD_H
