/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "usb_device.h"
#include "usbd_customhid.h"

#include "common_types.h"
#include "usbd_custom_hid_if.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define LED_TOGGLE_DELAY_MS 1500

/*****************************************
 * Main Function
 *****************************************/

joy_report_t joy_report;

int main(void) {
    mcu_init();

    MX_USB_DEVICE_Init();
    joy_report.id = JOY_REPORT_ID;

    for (;;) {
        led_toggle();
        mcu_sleep(LED_TOGGLE_DELAY_MS);

        USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &(joy_report.id),
                                   sizeof(joy_report) - sizeof(joy_report.dummy));
    }
}
