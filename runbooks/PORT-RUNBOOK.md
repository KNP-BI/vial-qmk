# cheapinov2-port runbook — modern QMK + Vial + chordal_hold + flow_tap

This is the port you asked me to make. Files live in
`C:/Users/kimpr/cheapinov2-port/` (a fresh checkout of
`vial-kb/vial-qmk@vial`, June 2026, with modern QMK chordal/flow-tap
+ Vial support, plus cheapino/ keyboard files overlaid from
`tompi/vial-qmk@cheapinov2`).

## Run it

```bash
cd C:/Users/kimpr/cheapinov2-port
git submodule update --init --recursive     # one-time fetch of chibios, pico-sdk
qmk compile -kb cheapino -km vial           # builds the UF2
```

If `qmk compile` errors with `KeyError: 'SHELL'` (Windows quirk),
use direct `make` instead:

```bash
PATH="/usr/bin:/mingw64/bin:$PATH" make cheapino:vial
```

The new UF2 is at:
```
C:/Users/kimpr/cheapinov2-port/.build/cheapino_vial.uf2
```

## Flash + verify

1. Hold BOOTSEL on cheapino, plug in USB, release.
2. Drive shows up as `RPI-RP2` (~128 KB FAT).
3. Drag `.build/cheapino_vial.uf2` to that drive. Auto-reboots.
4. Open Vial app — keyboard should appear as "Cheapino2".
5. File → Load saved keymap → `C:/Users/kimpr/Downloads/cheapino.vil`. Should import cleanly: 14 layers, Workman layout, TG-FN.
6. Type "pa" — with FLOW_TAP_TERM=150 and a follow-up key within 150 ms, the mod on `A` should NOT fire.
7. Press `LGUI_T(KC_A)` + `KC_R` simultaneously — chordal_hold should fire the GUI modifier (chord-rule resolution, not pure timing).

## What changed

| path | change |
|---|---|
| `keyboards/cheapino/keyboard.json` | NEW — modern QMK format, ports info.json data; declares `tapping.term=230`, `caps_word.both_shifts_turns_on=true`, `rgblight.led_count=1`, `encoder.rotary[0]={GP12,GP13}`, `community_layouts=['split_3x5_3']` |
| `keyboards/cheapino/info.json` | DELETED — superseded by keyboard.json |
| `keyboards/cheapino/halconf.h` | DELETED — modern QMK handles via pico-sdk |
| `keyboards/cheapino/mcuconf.h` | DELETED — same |
| `keyboards/cheapino/config.h` | rewritten to bare-minimum: only `ENCODERS_PAD_A/B`, `ENCODER_RESOLUTION`, `ENCODER_MAP_KEY_DELAY`. Everything else lives in keyboard.json. |
| `keyboards/cheapino/rules.mk` | rewritten: `VIAL_ENABLE`, `VIA_ENABLE`, `VIAL_INSECURE`, `KEYBOARD_SHARED_EP`, `CUSTOM_MATRIX=lite`, plus `SRC += encoder.c ghosting.c matrix.c` |
| `keyboards/cheapino/encoder.c` | `encoder_exec_mapping(0, ...)` → `encoder_queue_event(0, ...)`. Modern QMK renamed the API. |
| `keyboards/cheapino/matrix.c` | `debounce_init(MATRIX_ROWS)` → `debounce_init()`. Modern QMK takes no args. |
| `keyboards/cheapino/keymaps/vial/keymap.c` | NEW — modern keycode names (`UG_HUEU` etc., `MS_WHLU`/`MS_WHLD`). 8 layers, 37 keys each (incl. encoder button at `[3,0]`). Falls back to default QWERTY+homerow-mods layout until you load your `.vil` save. |
| `keyboards/cheapino/keymaps/vial/config.h` | NEW — Vial UID + unlock combo + `DYNAMIC_KEYMAP_LAYER_COUNT=14` + **the three defines**: `#define CHORDAL_HOLD`, `#undef FLOW_TAP_TERM` / `#define FLOW_TAP_TERM 150`, `#undef TAPPING_TERM` / `#define TAPPING_TERM 180`. |

## Why the defines actually work this time

In your previous build on `tompi/vial-qmk@cheapinov2`, I had the same three
defines in `keymaps/vial/config.h`. They were no-ops because that fork's
`quantum/action.c` predates the CHORDAL_HOLD feature and never had
`#ifdef CHORDAL_HOLD` guards. This build on `vial-kb/vial-qmk@vial`
(June 2026) has `quantum/action.c` with those `#ifdef`s in place. QMK's
build system uses `-include` to feed every `config.h` into every
translation unit — so `keymaps/vial/config.h`'s `#define CHORDAL_HOLD`
IS visible to `quantum/action.c` at compile time. Same for `FLOW_TAP_TERM`.

For runtime tuning, Vial's settings panel can override `TAPPING_TERM` without a rebuild. `CHORDAL_HOLD` and `FLOW_TAP_TERM` are compile-time only.

## Things that could go wrong

| symptom | cause | fix |
|---|---|---|
| `error: undefined reference to encoder_queue_event` | `ENCODER_ENABLE` not picked up | rely on `features.encoder=true` in keyboard.json (already there) |
| `error: redefinition of TAPPING_TERM` | config.h and keyboard.json both set | remove from config.h |
| `error: redefinition of WS2812_DRIVER` | same | remove from rules.mk |
| Vial "Invalid keymap" on load | UID mismatch | your .vil is keyed to `0x9EC18B09BB40ED79`; this build uses the same UID. If Vial still complains, paste the error. |
| `undefined reference to fix_ghosting` | ghosting.h not visible to matrix.c | confirm `ghosting.h` is in same dir as matrix.c (it is) |
| QMK build hangs at chibios submodule | slow submodule fetch on first run | let it sit; first build 5–10 min |

## Rollback

Your previous working firmware is still at:
```
C:/Users/kimpr/Downloads/cheapino_vial.uf2  (102 KB, 2024-11-18)
```

If the new build doesn't work, drop that onto a BOOTSEL-flashed keyboard and you're back to the original.

## What's NOT in this port

- The `keymaps/{default,lars,tompi,via}/` directories from `tompi/vial-qmk@cheapinov2` were pulled in with the sparse checkout. They reference deprecated keycodes (RGB_VAD etc.) and will fail to compile on modern QMK. If you only ever build `:vial`, they're harmless. To delete them: `rm -rf keyboards/cheapino/keymaps/{default,lars,tompi,via}`.

## Attribution

Base: `vial-kb/vial-qmk@vial` (commit 00fc4627cd, June 2026), all of upstream QMK's quantum/, plus Vial framework. Cheapino overlay: `tompi/vial-qmk@cheapinov2` (commit 9100f29, April 2025).
