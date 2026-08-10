# PORT FIXES — re-run the build

Three patches applied to fix the `-Werror redef` errors. The fixes are already on disk; you should just re-run:

```bash
cd C:/Users/kimpr/cheapinov2-port
rm -rf .build/obj_cheapino_vial .build/cheapino_vial.elf .build/cheapino_vial.uf2
qmk compile -kb cheapino -km vial
```

(or `make cheapino:vial`).

## What I changed

### 1. `keyboards/cheapino/keymaps/vial/config.h` — dropped redundant `#define CHORDAL_HOLD`

Modern QMK auto-defines `CHORDAL_HOLD` at the command line (because `features.vial: true` is now set on keyboard.json). My explicit `#define CHORDAL_HOLD` was a duplicate that `-Werror` rejected. Removed the line and updated the comment to explain why.

`FLOW_TAP_TERM=150` and `TAPPING_TERM=180` stay — those `#undef … #define X` pairs are not redef errors.

### 2. `keyboards/cheapino/config.h` — dropped `ENCODERS_PAD_A` / `ENCODERS_PAD_B`

`info_config.h` generates `ENCODER_A_PINS = { GP12 }` and `ENCODER_B_PINS = { GP13 }` directly from `keyboard.json`'s `encoder.rotary[0]`. The QMK encoder.h has this backwards-compat shim:

```c
#ifdef ENCODERS_PAD_A
#    define ENCODER_A_PINS ENCODERS_PAD_A
#endif
```

Which `expanded` the obsolete name into the new define — producing the redef error. Removed my `ENCODERS_PAD_A`/`B` defines; the JSON-generated ones now stand alone. Left in `ENCODER_RESOLUTION` and `ENCODER_MAP_KEY_DELAY` because those don't have JSON equivalents.

### 3. `keyboards/cheapino/keyboard.json` — added `via`, `vial`, `encoder_map` to features

This is the modern-QMK-correct way to enable Vial. Added:
```json
"via": true,
"vial": true,
"encoder_map": true
```

QMK CLI now emits `-DVIAL_ENABLE`, `-DVIA_ENABLE`, `-DKEYBOARD_SHARED_EP`, `-DCHORDAL_HOLD`, `-DFLOW_TAP_TERM` automatically. Then I removed the matching `VIAL_ENABLE = yes` / `VIA_ENABLE = yes` / `KEYBOARD_SHARED_EP = yes` lines from `keyboards/cheapino/rules.mk` to clean up the "no longer a valid option" warnings.

`VIAL_INSECURE = yes` stayed in rules.mk because there is no clean JSON key for it.

## Expected output

After re-running, the build should produce a UF2 with **much fewer warnings** (probably only the Vial-insecure pragma message and a few deprecation notes from `vial/config.h`'s `VIAL_KEYBOARD_UID`). If the build completes with `[OK]` and `Creating UF2 file for deployment: .build/cheapino_vial.uf2 [OK]`, you're done — flash the new UF2 and verify:
- Vial GUI recognises the keyboard.
- `cheapino.vil` imports cleanly.
- Type "pa" — the `A` homerow mod should NOT fire (FLOW_TAP_TERM is now active).
- Hold `LGUI_T(KC_A)` and tap a neighbour → modifier fires (CHORDAL_HOLD active).

## If the build still fails

Send the new error block verbatim. The likely remaining suspects: `encoder_queue_event` linker error if `features.encoder: true` isn't being honoured; or `via:vial: true` in keyboard.json might not be the canonical key name (some Vial forks use `vial.enable` or `vial.enabled` as a sub-object). If that fails, tell me.
