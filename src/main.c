/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "usb_device.h"
#include "usbd_customhid.h"

#include "joystick.h"
#include "usbd_custom_hid_if.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define LED_TOGGLE_DELAY_MS 1500

/*****************************************
 * Main Function
 *****************************************/

joystick_report_t joy_report;

int main(void) {
    mcu_init();

    MX_USB_DEVICE_Init();
    joy_report.id = JOY_REPORT_ID;

    joy_report.x_axis = 750;
    joy_report.y_axis = 750;
    joy_report.weapon_slider = 500;

    for (;;) {
        led_toggle();
        mcu_sleep(LED_TOGGLE_DELAY_MS);

        USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &(joy_report.id), sizeof(joy_report));
    }
}
