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

INTROSPECTION_KEYMAP_C  = ckaadic.c

ifeq ($(strip $(MCU)), atmega32u4)
	LTO_ENABLE = yes
	BOOTLOADER = atmel-dfu
endif

ifneq ($(strip $(CONVERT_TO)),)
    EEPROM_DRIVER = transient
    override TARGET := $(subst /,_,$(KEYBOARD))_$(strip $(CONVERT_TO))
    ifneq ($(filter left right, $(SPLIT)),)
        MAKECMDGOALS = uf2-split-$(strip $(SPLIT))
        override TARGET := $(TARGET)_$(strip $(SPLIT))
    endif
endif
