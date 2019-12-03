/**
 * @file ppm_reader.c
 *
 * @brief PPM readings related.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 12/2019
 */

#include <stdbool.h>

#include "tim.h"
#include "gpio.h"

#include "ppm_reader.h"
#include "mcu.h"

/*****************************************
 * Private Constants
 *****************************************/

#define PPM_CHANNELS 3

/*****************************************
 * Private Funtions Prototypes
 *****************************************/

/**
 * @brief Checks if the channel pin is high.
 *
 * @return True is pin is high, false otherwise.
 */
bool ppm_radio_ch1_is_high();

/**
 * @brief Checks if the channel pin is high.
 *
 * @return True is pin is high, false otherwise.
 */
bool ppm_radio_ch2_is_high();

/**
 * @brief Checks if the channel pin is high.
 *
 * @return True is pin is high, false otherwise.
 */
bool ppm_radio_ch3_is_high();

/*****************************************
 * Private Variables
 *****************************************/

static uint16_t ppm_receiver[PPM_CHANNELS] = {0};

/*****************************************
 * Public Funtions Bodies Definitions
 *****************************************/

void ppm_reader_init() {
    MX_TIM1_Init();

    mcu_sleep(100);

    HAL_TIM_Base_Start(&htim1);

    mcu_sleep(100);

    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_2);
    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_3);
}

uint16_t ppm_reader_get_channel_reading(radio_channel_t ch) {
    return (ppm_receiver[ch]);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim) {
    static uint16_t _tim1_ch1[2] = {0, 0};
    static uint16_t _tim1_ch2[2] = {0, 0};
    static uint16_t _tim1_ch3[2] = {0, 0};

    if (htim->Instance == TIM1) {
        if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
            if (ppm_radio_ch1_is_high()) {
                _tim1_ch1[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            } else {
                _tim1_ch1[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
                ppm_receiver[CH1] = _tim1_ch1[1] - _tim1_ch1[0];
            }
        } else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {
            if (ppm_radio_ch2_is_high()) {
                _tim1_ch2[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
            } else {
                _tim1_ch2[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
                ppm_receiver[CH2] = _tim1_ch2[1] - _tim1_ch2[0];
            }
        } else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {
            if (ppm_radio_ch3_is_high()) {
                _tim1_ch3[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
            } else {
                _tim1_ch3[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
                ppm_receiver[CH3] = _tim1_ch3[1] - _tim1_ch3[0];
            }
        }
    }
}

/*****************************************
 * Private Funtions Bodies Definitions
 *****************************************/

bool ppm_radio_ch1_is_high() {
    return (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
}

bool ppm_radio_ch2_is_high() {
    return (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
}

bool ppm_radio_ch3_is_high() {
    return (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10));
}
