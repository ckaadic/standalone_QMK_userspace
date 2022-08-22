SRC += ckaadic.c
VPATH += $(USER_PATH)/oled $(USER_PATH)/features $(USER_PATH)/rgb

# Common feature for all keyboards
BOOTMAGIC_ENABLE = yes
EXTRAKEY_ENABLE = yes
WAIT_FOR_USB = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

# Disable unused features
#VIA_ENABLE = no
#WPM_ENABLE = no
#NKRO_ENABLE = no
#AUDIO_ENABLE = no
#STENO_ENABLE = no
#LEADER_ENABLE = no
#COMMAND_ENABLE = no
#TERMINAL_ENABLE = no
#KEY_LOCK_ENABLE = no
#SLEEP_LED_ENABLE = no
#TAP_DANCE_ENABLE = no
#VELOCIKEY_ENABLE = no
MAGIC_ENABLE = no
CONSOLE_ENABLE = no
UNICODE_ENABLE = no
RGBLIGHT_ENABLE = no
SWAP_HANDS_ENABLE = no
SPACE_CADET_ENABLE = no


# Custom features
OPT_DEFS += -DCAPS_UNLOCK
SRC += caps_unlock.c

ifeq ($(strip $(MCU)), atmega32u4)
	LTO_ENABLE = yes
	BOOTLOADER = atmel-dfu
endif

ifneq ($(strip $(CONVERT_TO)),)
	EEPROM_DRIVER = transient
	OPT_DEFS += -DINIT_EE_HANDS_$(shell echo ${SPLIT}|tr a-z A-Z)
endif

switch($(strip $(KEYBOARD))):
    case crkbd/rev1:
        RGB_MATRIX_ENABLE = yes
	    OLED_ENABLE = yes
	    SRC += autocorrect.c oled-32.c rgb-matrix.c
    case reviung/reviung34:
        RGB_MATRIX_ENABLE = yes
        SRC += autocorrect.c rgb-matrix.c