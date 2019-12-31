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

bool spam_enter;
uint16_t spam_timer = false;
uint16_t spam_interval = 100; // (1000ms == 1s)

enum layers {
    _BASE = 0,
    _META,
    _FUNC,
};

enum custom_keycodes {
    RESETSCRIPT = SAFE_RANGE,
    KC_EEEE
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
        case KC_EEEE: // Toggle's if we hit "ENTER" or "BACKSPACE" to input macros
            if (record->event.pressed) { 
                spam_enter ^= 1; 
                spam_timer = timer_read();
            }
            return false;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (spam_enter && timer_elapsed(spam_timer) >= spam_interval) {
        spam_timer = timer_read();
        SEND_STRING(SS_TAP(X_ENTER));
    }
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

int select_random_mode(void) {
    if (rand_min_max(0, 1)) {
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
            rgblight_mode_noeeprom(select_random_mode()); //example selecting random mode
            if (rand_min_max(0,1)){
                rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            } else {
                rgb_matrix_sethsv_noeeprom(HSV_PINK);
            }
            //rgblight_sethsv_at(HSV_MAGENTA, 0);
            break;
    }
    return state;
}
