#pragma once

#ifdef OLED_ENABLE
    //layer_state_t layer_state_set_kb(layer_state_t state)
    oled_rotation_t oled_init_user(oled_rotation_t rotation);
    bool oled_task_kb(void);
#endif