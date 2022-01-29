//
// Created by william on 2022-01-29.
//

#include <SystemKeyboard.hpp>

extern ui::MainApplication::Ref g_MainApplication;
extern cfg::Settings g_Settings;

class SystemKeyboard {
    SystemKeyboard() {
        userMessage = "";
    }

    std::string getUserInput(const std::string &guide_text, const std::string &initial_text, int max_len) {
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
}