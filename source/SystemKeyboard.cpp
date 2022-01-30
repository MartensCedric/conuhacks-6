//
// Created by william on 2022-01-29.
//

#include <SystemKeyboard.hpp>

SystemKeyboard::SystemKeyboard(MessagingLayout::Ref layout, pu::ui::elm::TextBlock::Ref textBlock) {
    this->layout = layout;
    this->textBlock = textBlock;
}

std::string SystemKeyboard::getUserInput(const std::string &guide_text, const std::string &initial_text, int max_len) {
    SwkbdConfig kbd;
    auto rc = swkbdCreate(&kbd, 0);
    if(R_SUCCEEDED(rc)) {
        swkbdConfigMakePresetDefault(&kbd);
        if(max_len > 0) {
            swkbdConfigSetStringLenMax(&kbd, static_cast<u32>(max_len));
        }

        if(!guide_text.empty()) {
            swkbdConfigSetGuideText(&kbd, guide_text.c_str());
        }

        if(!initial_text.empty()) {
            swkbdConfigSetInitialText(&kbd, initial_text.c_str());
        }

        char out_text[FS_MAX_PATH] = {};
        rc = swkbdShow(&kbd, out_text, sizeof(out_text));
        if(R_SUCCEEDED(rc)) {
            return out_text;
        }
        swkbdClose(&kbd);
    }

    return "";
}

void SystemKeyboard::attachKeyboard(MessagingLayout::Ref layout, pu::ui::elm::TextBlock::Ref textBlock) {
    this->layout->SetOnInput([&](const u64 down, const u64 up, const u64 held, pu::ui::TouchPoint touchPoint) {
        if(down & HidNpadButton_A) {
            layout->Add(textBlock);
            textBlock->SetText(this->getUserInput("", "", 250));
            layout->Add(textBlock);
        }
    });
}