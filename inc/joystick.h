/**
 * @file joysick.h
 *
 * @brief USB joystick related.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 12/2019
 */

#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "stdint.h"

/*****************************************
 * Public Constants
 *****************************************/

#define JOYSTICK_REPORT_ID 0x01

#define JOYSTICK_REPORT_NUM_OF_AXES 0x03

#define JOYSTICK_LOGICAL_MINIMUM 0x00

/* Maximum value is 1000 */
#define JOYSTICK_LOGICAL_MAXIMUM_MS_BYTE 0x03 /* Most significant byte */
#define JOYSTICK_LOGICAL_MAXIMUM_LS_BYTE 0xE8 /* Least significant byte */

/*****************************************
 * Public Funtions Prototypes
 *****************************************/

/**
 * @brief Initializes joystick.
 */
void joystick_init();

/**
 * @brief Sends joystick data.
 *
 * @param x_value      x axis value.
 * @param y_value      y axis value.
 * @param weapon_value weapon slider value.
 */
void joystick_send_axes_data(uint16_t x_value, uint16_t y_value, uint16_t weapon_value);

#endif // __JOYSTICK_H__
