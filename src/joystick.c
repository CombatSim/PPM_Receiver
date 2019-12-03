/**
 * @file joysick.c
 *
 * @brief USB joystick related.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 12/2019
 */

#include "joystick.h"

#include "usb_device.h"
#include "usbd_customhid.h"
#include "usbd_custom_hid_if.h"

/*****************************************
 * Private Types
 *****************************************/

typedef struct __attribute__((packed)) joystick_report {
    uint8_t id;
    uint16_t x_axis;
    uint16_t y_axis;
    uint16_t weapon_slider;
} joystick_report_t;

/*****************************************
 * Private Variables
 *****************************************/

joystick_report_t joystick_report;

/*****************************************
 * Public Funtions Bodies Definitions
 *****************************************/

void joystick_init() {
    MX_USB_DEVICE_Init();
    joystick_report.id = JOYSTICK_REPORT_ID;
}

void joystick_send_axes_data(uint16_t x_value, uint16_t y_value, uint16_t weapon_value) {
    joystick_report.x_axis = x_value;
    joystick_report.y_axis = y_value;
    joystick_report.weapon_slider = weapon_value;

    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &(joystick_report.id), sizeof(joystick_report));
}
