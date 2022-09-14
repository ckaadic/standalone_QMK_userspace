SRC += ckaadic.c
VPATH += $(USER_PATH)/oled $(USER_PATH)/features $(USER_PATH)/rgb

# Common feature for all keyboards
BOOTMAGIC_ENABLE = yes
EXTRAKEY_ENABLE = yes
WAIT_FOR_USB = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes
MACROS_ENABLED = yes

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


ifeq ($(strip $(MCU)), atmega32u4)
	LTO_ENABLE = yes
	BOOTLOADER = atmel-dfu
endif

ifneq ($(strip $(CONVERT_TO)),)
	EEPROM_DRIVER = transient
	OPT_DEFS += -DINIT_EE_HANDS_$(shell echo ${SPLIT}|tr a-z A-Z)
endif

ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
    RGB_MATRIX_ENABLE = yes
	OLED_ENABLE = yes
	SRC += oled-32.c rgb-matrix.c
else ifeq ($(strip $(KEYBOARD)), reviung/reviung34)
    RGBLIGHT_ENABLE = yes
    RGB_MATRIX_DRIVER = WS2812
    #SRC += rgb-matrix.c
else ifeq ($(strip $(KEYBOARD)), eternal_keypad)
	RGBLIGHT_ENABLE = yes
endif