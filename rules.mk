# Disable unused features
MAGIC_ENABLE = no
UNICODE_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no

# Enable common features
LTO_ENABLE = yes
#CAPS_WORD_ENABLE = yes
#COMBO_ENABLE = yes

VPATH += $(USER_PATH)/features
INTROSPECTION_KEYMAP_C  = ckaadic.c

ifneq ($(strip $(CONVERT_TO)),)
    EEPROM_DRIVER = transient
    override TARGET := $(subst /,_,$(KEYBOARD))_$(strip $(CONVERT_TO))
    ifneq ($(filter left right, $(SPLIT)),)
        MAKECMDGOALS = uf2-split-$(strip $(SPLIT))
        override TARGET := $(TARGET)_$(strip $(SPLIT))
    endif
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled-32.c
endif