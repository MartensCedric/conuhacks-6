
#pragma once

// Include Plutonium's main header
#include <pu/Plutonium>
#include <vector>
#include <MessageFrame.hpp>

// Define your main layout as a class inheriting from pu::Layout
class MessagingLayout : public pu::ui::Layout {
    private:
        std::vector<MessageFrame> frames;
    public:
        MessagingLayout();

        // Have ::Ref alias and ::New() static constructor
        PU_SMART_CTOR(MessagingLayout)
};

