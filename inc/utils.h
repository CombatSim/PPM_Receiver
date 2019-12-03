/**
 * @file utils.h
 *
 * @brief Mathematic utilitary functions globally available.
 */

#ifndef __UTILS_H__
#define __UTILS_H__

/*****************************************
 * Public Macros
 *****************************************/

/**
 * @brief Returns x absolute value.
 */
#define abs(x) ((x) > 0 ? (x) : -(x))

/**
 * @brief Returns maximum value between x and y.
 */
#define max(x, y) ((x) > (y) ? (x) : (y))

/**
 * @brief Returns minimum value between x and y.
 */
#define min(x, y) ((x) < (y) ? (x) : (y))

/**
 * @brief Constrains v between x and y, returning at least x and at most y.
 */
#define constrain(v, x, y) ((v) < (x) ? (x) : ((v) > (y) ? (y) : (v)))

/**
 * @brief Returns the length of statically defined arrays.
 */
#define len(arr) (sizeof(arr) / sizeof(arr[0]))

/**
 * @brief Maps an integer value from one scale to another.
 *
 * @param former_value Value in former scale.
 * @param former_min   Former scale minimum value.
 * @param former_max   Former scale maximum value.
 * @param new_min      New scale minimum value.
 * @param new_max      New scale maximum value.
 *
 * @return Value in new scale
 */
inline float map(float former_value, float former_min, float former_max, float new_min, float new_max) {
    double new_value;

    new_value = (double) (former_value - former_min) * (new_max - new_min);
    new_value /= (former_max - former_min);
    new_value += new_min;

    return (float) new_value;
}

#endif // __UTILS_H__
