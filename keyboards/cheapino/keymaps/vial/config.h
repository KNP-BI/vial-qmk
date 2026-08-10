#pragma once

// Vial unlock combo + identity + layer capacity
#define VIAL_KEYBOARD_UID {0x79, 0xED, 0x40, 0xBB, 0x09, 0x8B, 0xC1, 0x9E}
#define VIAL_UNLOCK_COMBO_ROWS { 6, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 11, 5 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 14

// === Hold-tap behaviour ===
// CHORDAL_HOLD and FLOW_TAP_TERM are enabled in builddefs/build_vial.mk
// (Vial's QMK_SETTINGS block: -DCHORDAL_HOLD -DFLOW_TAP_TERM=150).
// FLOW_TAP_TERM is also overridden there to 150 (was hard-coded 321).
// This header re-defines TAPPING_TERM=180 and re-asserts FLOW_TAP_TERM=150
// for safety; both survive the -Werror build because info_config.h wraps
// its generated TAPPING_TERM in #ifndef.
#undef FLOW_TAP_TERM
#define FLOW_TAP_TERM 150

// TAPPING_TERM governs hold-tap resolution timing. Vial's settings panel can
// override this at runtime; this is the compile-time default.
#undef TAPPING_TERM
#define TAPPING_TERM 180
