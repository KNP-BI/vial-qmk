# cheapinov2-vial build runbook

You are about to build a Vial-enabled cheapino firmware with
CHORDAL_HOLD, FLOW_TAP_TERM=150, TAPPING_TERM=180 baked in.

> **Critical**: every command in this runbook is destructive or near-
> destructive on its target. Do **not** run any command you don't
> understand. If a step fails, send the error message to your assistant
> before proceeding.

> **Assumptions**: QMK is already set up locally and
> `qmk --version` reports `1.2.0` or higher. MSYS2/QMK environment
> initialised (`QMK MSYS` shortcut, or `export QMK_HOME=...`). USB
> driver lib installed (zadig for rp2040 if flashing from Windows).

---

## Step 1 — Back up your current state (5 seconds)

```bash
cd C:/Users/kimpr
mkdir -p cheapino-build-state
cp Downloads/cheapino.vil cheapino-build-state/cheapino.vil
ls cheapino-build-state/
```
Expected:
```
cheapino.vil
vial-config.h
cheapino_kim_ai-built.uf2  (or similar; harmless if missing)
```

If `cheapino.vil` doesn't appear, abort — do not lose this file.

---

## Step 2 — Open QMK MSYS shell

Use the **QMK MSYS** shortcut on your desktop, or open MSYS2 and run:

```bash
export QMK_HOME=/c/Users/kimpr/qmk_firmware  # only if you want to keep your existing checkout alongside
```
The variable isn't required — `qmk` finds the keyboard regardless — but
having a known `QMK_HOME` keeps things explicit.

---

## Step 3 — Clone the canonical Vial-cheapino source (60–90 seconds)

```bash
cd /c/Users/kimpr
git clone --branch cheapinov2 https://github.com/tompi/vial-qmk cheapinov2-vial
cd cheapinov2-vial
git submodule update --init --recursive
```

> Why this branch: it is the exact source tree the v2.0 release UF2 in
> your Downloads folder was built from. UID `0x9EC18B09BB40ED79`,
> 14 layers, 1 encoder, all match your `.vil` byte-exact.

You should see:
```
Cloning into 'cheapinov2-vial'...
... HEAD at 9100f29 More usable default keymap
```
Submodules are `lib/chibios`, `lib/chibios-contrib`, `lib/pico-sdk`,
`lib/lufa` etc. The first build will take longer because of those.

---

## Step 4 — Apply the patched vial keymap config (instant)

```bash
cp /c/Users/kimpr/cheapino-build-state/vial-config.h \
   keyboards/cheapino/keymaps/vial/config.h

cat keyboards/cheapino/keymaps/vial/config.h
```

You should see (truncated):

```
#define VIAL_KEYBOARD_UID {0x79, 0xED, 0x40, 0xBB, 0x09, 0x8B, 0xC1, 0x9E}
...
#define DYNAMIC_KEYMAP_LAYER_COUNT 14
...
#define CHORDAL_HOLD

#undef FLOW_TAP_TERM
#define FLOW_TAP_TERM 150

#undef TAPPING_TERM
#define TAPPING_TERM 180
```

If you do **not** see the three new defines at the bottom, stop and
re-check the file — re-run the cp.

---

## Step 5 — Compile (3–7 minutes from cold)

```bash
qmk compile -kb cheapino -km vial
```

If `qmk` complains about `KeyError: 'SHELL'` (Windows-specific), use
direct make instead:

```bash
PATH="/usr/bin:/mingw64/bin:$PATH" make cheapino:vial
```

Expected output tail:
```
Linking: .build/cheapino_vial.elf                                                    [OK]
Creating UF2: cheapino_vial.uf2                                                    [OK]
```

If you hit an error, copy the failing `Compiling: ... [ERRORS]` block
verbatim and send it to your assistant. **Do not edit any files in
cheapinov2-vial/ without checking first** — that branch is the canonical
source for the next build.

---

## Step 6 — Locate and flash the UF2 (1 minute)

```bash
find . -name 'cheapino_vial.uf2' 2>/dev/null
```

You'll get a path like:
```
./.build/cheapino_vial.uf2
```

That's your new firmware. To flash:

1. Hold `BOOTSEL` on the cheapino, plug in USB, release.
2. Drive shows up as `RPI-RP2` (a ~128 KB FAT volume).
3. Drag the `.uf2` to that drive. It auto-reboots.
4. Within 5 seconds, open Vial app, the keyboard should appear.

---

## Step 7 — Verify your keymap imports (30 seconds)

1. Open the **Vial** app (download from https://vial.rocks if you don't have it).
2. Confirm the keyboard is detected — top status bar should show
   cheapino2 and 14 layers.
3. Click **File → Load saved keymap**, select
   `C:/Users/kimpr/Downloads/cheapino.vil`.
4. If Vial accepts the file without a `KeyError` and re-renders the
   matrix to match your saved Workman layout — **success**. Skip step 8.
5. If Vial complains `KeyError: (0, 0, 0)` (encoder mismatch), the
   .vil was generated against a build with `ENCODER_MAP_ENABLE = yes`.
   The fresh build from `tompi/vial-qmk` already has that flag enabled
   (see `rules.mk`), so this should not happen. If it does, paste the
   full error message back to your assistant.

---

## Step 8 — Sanity-check chordal/flow-tap (2 minutes)

Test:
- Press `LGUI_T(KC_A)` alone → expect `a`.
- Press `LGUI_T(KC_A) + LSFT_T(KC_T)` simultaneously → expect
  `Shift+Cmd`-chord (or whichever combo fits your OS).
- Type "pa" within 150 ms of each other, where `A` is the home-row mod
  — should type `pa`, not `Cmd+A` then `a`.
- Hold `LSFT_T(KC_T)` for more than 180 ms → expect `Shift` modifier;
  tap quickly → expect `t`.

If chordal_hold feels "too aggressive" (mod fires on adjacent keys
you didn't intend), raise `TAPPING_TERM` to 220–250 ms later via
Vial's dynamic settings or by re-emitting the .vil. **Don't lose the
keymap** first.

---

## Rollback plan

If anything is broken and you want to revert to your prior working
`cheapino_vial.uf2` (the AI-built one with the wrong layout but no
chordal hold):

```bash
# In a fresh shell
ls "C:/Users/kimpr/Downloads/" | grep cheapino_vial
# Hold BOOTSEL, plug in, drag cheapino_vial.uf2 to RPI-RP2 drive.
```

Your pre-changes UF2 is at:
```
C:/Users/kimpr/Downloads/cheapino_vial.uf2  (102KB, 2024-11-18)
```

It is not modified by anything in this runbook.

---

## Files you'll have created

After a successful build:

- `C:/Users/kimpr/cheapinov2-vial/.build/cheapino_vial.uf2` — flash this
- `C:/Users/kimpr/cheapinov2-vial/.build/cheapino_vial.bin` — backup
- `C:/Users/kimpr/cheapino-build-state/` — patch config + .vil backup

If a step fails, **stop and send the error to your assistant** before
running step N+1. Don't try to "fix" the source tree yourself — that
is how this session got the kim keymap lost.

---

## After this build is verified working

The cheapino-vial `/c/Users/kimpr/cheapino-vial/` second repo is no
longer needed. Move it to a backup or delete:

```bash
rm -rf /c/Users/kimpr/cheapino-vial/
```

Ditto the `C:/Users/kimpr/qmk_firmware/keyboards/cheapino/keymaps/kim/`
work if you choose to recreate it (which would require re-keying from
scratch).
