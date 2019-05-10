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

enum layers {
    _BASE = 0,
    _META,
    _FUNC,
};

enum custom_keycodes {
    RESETSCRIPT = SAFE_RANGE,
};

uint32_t default_mode = 22; //make some of our own keycodes for cycling default layout

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //tap Enter, then reset the keyboard
        //use with a script on workstation that sleeps before
        //uploading new firmware
        case RESETSCRIPT:
            if (record->event.pressed) {
                tap_code(KC_UP);
                tap_code(KC_ENTER);
                reset_keyboard();
            } else {
            }
            break;
    }
    return true;
}

//default 
void matrix_init_user() {
    rgblight_mode_noeeprom(default_mode);
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
}

//this file provides keymaps, so we can do more complex stuff here
#include "layout.c"

int rand_min_max(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

int select_random_layout(void) {
    int swatch;
    swatch = rand_min_max(0, 1);
    if (swatch) {
        return rand_min_max(21,24);
    } else {
        return rand_min_max(2,5);
    }
}

//int select_random_base_color

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _META:
            //doesn't work..may need MASSDROP_CONFIGURATOR to do this
            //rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);
            rgblight_mode_noeeprom(2);
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            break;
        case _FUNC:
            //doesn't work..may need MASSDROP_CONFIGURATOR to do this
            //rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);
            rgblight_mode_noeeprom(2);
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
        default: //  for any other layers, or the default layer
            //doesn't work..may need MASSDROP_CONFIGURATOR to do this
            //rgb_matrix_set_color(0, 0xFF, 0x00, 0xFF);
            rgblight_mode_noeeprom(select_random_layout()); //example selecting random mode
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
    }
    return state;
}
