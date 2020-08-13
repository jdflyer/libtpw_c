#include "controller.h"
#include "tp.h"

namespace Controller {
    uint16_t buttons_down() {
        return tp_mPad.buttons;
    }

    uint16_t buttons_pressed() {
        return tp_mPad.buttons_down;
    }

    void set_buttons_down(uint16_t buttons) {
        tp_mPad.buttons = buttons;
    }

    void set_buttons_pressed(uint16_t buttons) {
        tp_mPad.buttons_down = buttons;
    }

    bool is_down(uint16_t buttons) {
        return (tp_mPad.buttons & buttons) == buttons;
    }

    bool is_pressed(uint16_t buttons) {
        return (tp_mPad.buttons_down & buttons) == buttons;
    }
}  // namespace Controller