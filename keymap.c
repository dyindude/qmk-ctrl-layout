#include QMK_KEYBOARD_H

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient
#define _BASE 0
#define _META 1

uint32_t default_mode = 22;

//default 
void matrix_init_user() {
    rgblight_mode_noeeprom(default_mode);
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
}

//this file provides keymaps, so we can do more complex stuff here
#include "layout.c"

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _META:
            rgblight_mode_noeeprom(3);
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
        default: //  for any other layers, or the default layer
            rgblight_mode_noeeprom(default_mode);
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
    }
    return state;
}
