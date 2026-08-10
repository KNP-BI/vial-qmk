CUSTOM_MATRIX = lite

# VIAL_ENABLE / VIA_ENABLE / KEYBOARD_SHARED_EP / ENCODER_DRIVER are auto-derived from
# keyboard.json (features.via, features.vial, encoder.driver, features.encoder_map).
# Only the explicit in-tree opt-ins stay here.
VIAL_INSECURE = yes

# Override Vial's default FLOW_TAP_TERM=321 with 150ms.
# build_vial.mk passes -DFLOW_TAP_TERM=321 on the command line, which can't be
# overridden by #undef in config.h. This OPT_DEFS line appears AFTER build_vial.mk's
# include in the makefile chain, so it takes precedence.
OPT_DEFS += -DFLOW_TAP_TERM=150

# Cheapino-specific source files (matrix logic, encoder decoder, ghosting fix).
SRC += encoder.c
SRC += ghosting.c
SRC += matrix.c
