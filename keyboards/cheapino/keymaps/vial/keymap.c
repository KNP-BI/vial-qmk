#include QMK_KEYBOARD_H

// Workman layout baked from cheapino.vil (14 layers).
// TAPPING_TERM=180, FLOW_TAP_TERM=150, CHORDAL_HOLD from build_vial.mk + config.h.
// Tap-dance is provided by Vial's dynamic table (restored from .vil);
// this keymap does NOT define tap_dance_actions (vial.c owns it).

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        KC_Q, KC_D, KC_R, KC_W, KC_B,                   // Left top
        KC_J, KC_F, KC_U, KC_P, TD(3),                  // Right top
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_H), LSFT_T(KC_T), KC_G, // Left home
        KC_Y, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_O), RGUI_T(KC_I), // Right home
        KC_Z, KC_X, KC_M, KC_C, KC_V,                   // Left bottom
        KC_K, KC_L, KC_COMMA, KC_DOT, KC_SLASH,         // Right bottom
        LT(1, KC_SPACE), LT(2, KC_TAB), KC_ESCAPE,      // Thumbs
        KC_DELETE, KC_BSPC, LT(3, KC_ENTER),            //
        KC_MPLY                                         // Encoder btn
    ),
    [1] = LAYOUT_split_3x5_3(
        KC_KP_ASTERISK, KC_KP_PLUS, KC_UP, KC_KP_MINUS, KC_KP_SLASH, // Left top
        KC_HOME, KC_7, KC_8, KC_9, TD(0),               // Right top
        KC_LGUI, KC_LEFT, KC_DOWN, KC_RIGHT, KC_KP_DOT, // Left home
        KC_END, KC_4, KC_5, KC_6, TD(1),                // Right home
        TO(0), TG(1), TO(2), TO(3), LSFT(KC_MINUS),     // Left bottom
        KC_0, KC_1, KC_2, KC_3, TD(2),                  // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_MPLY                                         // Encoder btn
    ),
    [2] = LAYOUT_split_3x5_3(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), KC_EQUAL, // Left top
        KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,         // Right top
        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_MINUS), LSFT(KC_EQUAL), // Left home
        KC_F5, KC_F6, KC_F7, KC_F8, KC_PGUP,            // Right home
        LSFT(KC_BSLS), LSFT(KC_5), KC_BSLS, KC_GRAVE, KC_MINUS, // Left bottom
        KC_F1, KC_F2, KC_F3, KC_F4, KC_PGDN,            // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_MPLY                                         // Encoder btn
    ),
    [3] = LAYOUT_split_3x5_3(
        TO(0), KC_NO, KC_NO, KC_NO, KC_NO,              // Left top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right top
        TO(0), KC_NO, RGB_VAI, KC_NO, BL_ON,            // Left home
        BL_TOGG, KC_NO, KC_NO, RGB_TOG, KC_NO,          // Right home
        TO(0), KC_NO, RGB_VAD, KC_NO, RGB_M_P,          // Left bottom
        RM_ON, RGB_M_R, KC_NO, KC_NO, KC_NO,            // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_MPLY                                         // Encoder btn
    ),
    [4] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left bottom
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right bottom
        KC_NO, KC_NO, KC_NO,                            // Thumbs
        KC_NO, KC_NO, KC_NO,                            //
        KC_NO                                           // Encoder btn
    ),
    [5] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left bottom
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right bottom
        KC_NO, KC_NO, KC_NO,                            // Thumbs
        KC_NO, KC_NO, KC_NO,                            //
        KC_NO                                           // Encoder btn
    ),
    [6] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left bottom
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right bottom
        KC_NO, KC_NO, KC_NO,                            // Thumbs
        KC_NO, KC_NO, KC_NO,                            //
        KC_NO                                           // Encoder btn
    ),
    [7] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right top
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right home
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Left bottom
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              // Right bottom
        KC_NO, KC_NO, KC_NO,                            // Thumbs
        KC_NO, KC_NO, KC_NO,                            //
        KC_NO                                           // Encoder btn
    ),
    [8] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_TRNS                                         // Encoder btn
    ),
    [9] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_TRNS                                         // Encoder btn
    ),
    [10] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_TRNS                                         // Encoder btn
    ),
    [11] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_TRNS                                         // Encoder btn
    ),
    [12] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_TRNS                                         // Encoder btn
    ),
    [13] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right top
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right home
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Left bottom
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    // Right bottom
        KC_TRNS, KC_TRNS, KC_TRNS,                      // Thumbs
        KC_TRNS, KC_TRNS, KC_TRNS,                      //
        KC_TRNS                                         // Encoder btn
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [4] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [5] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [6] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [7] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [8] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [9] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [10] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [11] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [12] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [13] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
