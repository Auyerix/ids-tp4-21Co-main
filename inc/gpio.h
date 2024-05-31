#include <stdint.h>
#include <stdbool.h>

typedef struct gpio_s * gpio_t;

/**
 * @brief
 * Create an instance of a gpio
 * @param puerto
 * @param bit
 * @return gpio_t
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/**
 * @brief
 * Set the gpio direction (input or output)
 * @param gpio
 * @param output
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief
 * Set the output to the desire state
 * @param gpio
 * @param state
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief
 * Get the actual output state of the gpio
 * @param gpio
 * @return bool
 */
bool gpioGetState(gpio_t gpio);
