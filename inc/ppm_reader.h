/**
 * @file ppm_reader.h
 *
 * @brief PPM readings related.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 12/2019
 */

#ifndef __PPM_READER_H__
#define __PPM_READER_H__

#include "stdint.h"

/*****************************************
 * Public Constant Definitions
 *****************************************/

#define PPM_MIN_VALUE 1000
#define PPM_MAX_VALUE 2000

/*****************************************
 * Public Types
 *****************************************/

typedef enum _radio_channel {
    CH1, /**< Radio Channel 1 */
    CH2, /**< Radio Channel 2 */
    CH3, /**< Radio Channel 3 */
} radio_channel_t;

/*****************************************
 * Public Funtions Prototypes
 *****************************************/

/**
 * @brief Initializes ppm reader.
 */
void ppm_reader_init();

/**
 * @brief Gets channel ppm reading value.
 *
 * @param ch Channel to be read.
 *
 * @return Channel reading.
 */
uint16_t ppm_reader_get_channel_reading(radio_channel_t ch);

#endif // __PPM_READER_H__
