#pragma once

#include <stdint.h>


typedef struct 
{
    float x;
    float y;
} go2_thumb_t;

typedef enum 
{
    ButtonState_Released = 0,
    ButtonState_Pressed
} go2_button_state_t;


typedef struct 
{
    go2_button_state_t a;
    go2_button_state_t b;
    go2_button_state_t x;
    go2_button_state_t y;

    go2_button_state_t top_left;
    go2_button_state_t top_right;

    go2_button_state_t f1;
    go2_button_state_t f2;
    go2_button_state_t f3;
    go2_button_state_t f4;
    go2_button_state_t f5;
    go2_button_state_t f6;

} go2_gamepad_buttons_t;

typedef struct 
{
    go2_button_state_t up;
    go2_button_state_t down;
    go2_button_state_t left;
    go2_button_state_t right;
} go2_dpad_t;

typedef struct 
{
    go2_thumb_t thumb;
    go2_dpad_t dpad;
    go2_gamepad_buttons_t buttons;
} go2_gamepad_state_t;

typedef struct go2_input go2_input_t;


typedef enum 
{
    Battery_Status_Unknown = 0,
    Battery_Status_Discharging,
    Battery_Status_Charging,

    Battery_Status_MAX = 0x7fffffff
} go2_battery_status_t;

typedef struct
{
    uint32_t level;
    go2_battery_status_t status;
} go2_battery_state_t;


#ifdef __cplusplus
extern "C" {
#endif

go2_input_t* go2_input_create();
void go2_input_destroy(go2_input_t* input);
void go2_input_gamepad_read(go2_input_t* input, go2_gamepad_state_t* outGamepadState);
void go2_input_battery_read(go2_input_t* input, go2_battery_state_t* outBatteryState);

#ifdef __cplusplus
}
#endif
