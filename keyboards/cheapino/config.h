// Copyright 2023 Thomas Haukland (@tompi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Most config migrated to keyboard.json. Keep only the bits the JSON
// can't or shouldn't express.

// Cheapino-specific: encoder pipeline resolution is "1 tent per notify".
// (ENCODER_A_PINS, ENCODER_B_PINS, ENCODER_MAP_ENABLE — all auto-generated
//  from keyboard.json's `encoder.rotary` block by QMK info_config.h.
#define ENCODER_RESOLUTION 1

// Honour Vial's encoder-map behaviour for layered actions.
#define ENCODER_MAP_KEY_DELAY 10
