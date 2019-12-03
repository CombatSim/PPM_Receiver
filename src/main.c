/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"

#include "joystick.h"
#include "ppm_reader.h"
#include "utils.h"

/*****************************************
 * Private Variables
 *****************************************/

static uint16_t x_axis = 0;
static uint16_t y_axis = 0;
static uint16_t weapon_slider = 0;

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_init();
    joystick_init();
    ppm_reader_init();

    mcu_sleep(200);

    uint16_t joystick_min_value = JOYSTICK_LOGICAL_MINIMUM;
    uint16_t joystick_max_value = (JOYSTICK_LOGICAL_MAXIMUM_MS_BYTE << 8) & JOYSTICK_LOGICAL_MAXIMUM_LS_BYTE;

    for (;;) {
        x_axis = map(ppm_reader_get_channel_reading(
                         CH1), PPM_MIN_VALUE, PPM_MAX_VALUE, joystick_min_value, joystick_max_value);
        y_axis = map(ppm_reader_get_channel_reading(
                         CH2), PPM_MIN_VALUE, PPM_MAX_VALUE, joystick_min_value, joystick_max_value);
        weapon_slider = map(ppm_reader_get_channel_reading(
                                CH3), PPM_MIN_VALUE, PPM_MAX_VALUE, joystick_min_value, joystick_max_value);

        joystick_send_axes_data(x_axis, y_axis, weapon_slider);
    }
}
