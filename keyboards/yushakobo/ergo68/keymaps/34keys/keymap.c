/* Copyright 2023 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// HOMEROW MODS
#define KC_LC_A LCTL_T(KC_A)
#define KC_LS_S LSFT_T(KC_S)
#define KC_LA_D LALT_T(KC_D)
#define KC_LG_F LGUI_T(KC_F)
#define KC_RC_SCLN RCTL_T(KC_SCLN)
#define KC_RS_L RSFT_T(KC_L)
#define KC_RA_K RALT_T(KC_K)
#define KC_RG_J RGUI_T(KC_J)

enum layers {
    BASE = 0,
    NUM,
    MOUSE,
    NAV,
    SYM,
    MEDIA,
    FUNC
};

// LAYERS
#define TC_1 LT(NUM, KC_ESC)
#define TC_2 LT(MOUSE, KC_SPC)
#define TC_3 LT(NAV, KC_ENT)
#define TC_4 LT(SYM, KC_BSPC)

// MDEIA
#define KC_VOUP KC_KB_VOLUME_UP
#define KC_VODN KC_KB_VOLUME_UP
#define KC_MUTE KC_KB_MUTE


// COMBOS
const uint16_t PROGMEM c_tab[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM c_media[] = {TC_3, TC_4, COMBO_END};
const uint16_t PROGMEM c_func[] = {TC_1, TC_2, COMBO_END};
const uint16_t PROGMEM c_hangul[] = {TC_2, TC_3, COMBO_END};
combo_t key_combos[] = {
    COMBO(c_tab, KC_TAB),
    COMBO(c_media, LT(MEDIA, KC_TRNS)),
    COMBO(c_func, LT(FUNC, KC_TRNS)),
    COMBO(c_hangul, KC_LNG1)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,   KC_NO, KC_NO,   KC_Y,   KC_U,       KC_I,       KC_O,       KC_P,       KC_NO,
        KC_NO,  KC_LC_A,    KC_LS_S,    KC_LA_D,    KC_LG_F,    KC_G,   KC_NO, KC_NO,   KC_H,   KC_RG_J,    KC_RA_K,    KC_RS_L,    KC_RC_SCLN, KC_NO,
        KC_NO,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,   KC_NO, KC_NO,   KC_N,   KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,
        KC_NO,  KC_NO,      KC_NO,      TC_1,       TC_2,       KC_NO,  KC_NO, KC_NO,   KC_NO,  TC_3,       TC_4,       KC_NO,      KC_NO,      KC_NO
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_MINS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_UP,   MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, MS_WHLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLR, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [4] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_MINS, KC_EQL,  KC_BSLS, KC_RPRN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_TRNS, KC_QUOT, KC_GRV,  KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [5] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_VODN, KC_VOUP, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_VALD, RM_VALU, RM_TOGG, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [6] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};


const uint8_t active_indices[] = {
    10,11,12,13,14, 17,18,19,20,21, 24,25,26,27,28, 33,34,
    47,48,49,50,51, 54,55,56,57,58, 61,62,63,64,65, 70,71
};
const uint8_t active_count = sizeof(active_indices) / sizeof(uint8_t);
bool is_active_index(uint8_t idx) {
    for (uint8_t i = 0; i < active_count; i++) {
        if (active_indices[i] == idx) {
            return true;
        }
    }
    return false;
}




bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // caps lock cyan
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 128);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    // num lock cyan
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 128);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 0);
    }

    // scroll lock cyan
    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 128);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 0);
    }

    // layer state
    for (uint8_t i = led_min; i < led_max; i++) {

        if (!is_active_index(i)) {
            rgb_matrix_set_color(i, 0,0,0);
            continue;
        }

        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 6:
                rgb_matrix_set_color(i, 5, 10, 14);
                break;
            case 5:
                rgb_matrix_set_color(i, 14, 9, 9);
                break;
            case 4:
                rgb_matrix_set_color(i, 9, 13, 9);
                break;
            case 3:
                rgb_matrix_set_color(i, 9, 11, 14);
                break;
            case 2:
                rgb_matrix_set_color(i, 11, 9, 13);
                break;
            case 1:
                rgb_matrix_set_color(i, 9, 12, 12);
                break;
            default:
                rgb_matrix_set_color(i, 15, 11, 8);
                break;
        }
    }
    return false;
}
