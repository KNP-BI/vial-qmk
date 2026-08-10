# Cheapino Firmware - Work Log

Repo: vial-qmk fork (base `vial-kb/vial-qmk@vial`, commit 00fc4627cd, June 2026)
with `keyboards/cheapino/` ported from `tompi/vial-qmk@cheapinov2` (commit 9100f29).

Build target: `qmk compile -kb cheapino -km vial` (or `make cheapino:vial`).

## 2026-07-16 / 07-17 - Firmware port (original work, relocated here 2026-08-10)

- Built Vial-enabled Cheapino v2 firmware with CHORDAL_HOLD, FLOW_TAP_TERM=150,
  TAPPING_TERM=180 baked in. RP2040, software-decoded encoder.
- Port details in `runbooks/PORT-RUNBOOK.md`; three -Werror fixes in
  `runbooks/PORT-FIXES-APPLIED.md`; fork research in `runbooks/FORK-SEARCH-REPORT.md`.
- Current build: `cheapino_vial.uf2` (2026-07-17 16:46, 115,712 B) at repo root.
- Keymap exports: `vils/` (07-17 baseline, 07-22, 08-10 current).
- Original factory rollback UF2: `vils/cheapino_vial.uf2` (102 KB, 2024-11-18).
- Old `kim` keymap (UID 0xC01A, superseded) archived in `archive/kim-keymap/`.

## 2026-08-10 - Relocation

- Moved from `C:\Users\kimpr\cheapinov2-port` to `C:\_git\cheapino`.
- Docs + vils + kim archive consolidated here.
- Deleted `cheapino-vial`, `cheapinov2-vial`, `qmk_firmware`, `cheapino-build-state`
  (rebuildable from upstream; kim keymap preserved in archive/).
