
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

#define JOY_REPORT_ID 1

typedef struct __attribute__((packed)) joystick_report {
    uint8_t  id;
    uint16_t x_axis;
    uint16_t y_axis;
    uint16_t weapon_slider;
} joystick_report_t;

#endif // __JOYSTICK_H__
