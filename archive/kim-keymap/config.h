#pragma once

// CHORDAL_HOLD already set by Vial
// Override Vial's default FLOW_TAP_TERM=321
#undef FLOW_TAP_TERM
#define FLOW_TAP_TERM 150

#undef TAPPING_TERM
#define TAPPING_TERM 180

// Vial unlock combo — both outer thumb keys
#define VIAL_UNLOCK_COMBO_ROWS { 6, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 11, 5 }

#define VIAL_KEYBOARD_UID { 0xC0, 0x1A, 0xE8, 0xA2, 0x77, 0x1E, 0xED, 0xD3 }
