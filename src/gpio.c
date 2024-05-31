#include "gpio.h"
#include <stddef.h>
#include <stdbool.h>

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/**
 * @brief Estructura para alojar el objeto Led
 *
 */

struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool used;
};

/**
 * @brief
 * Allocate a gpio instance
 * @return gpio_t
 */
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index].used;
            result->used = true;
            break;
        }
    }
    return result;
}

// Constructor // instancia de la clase
gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif
    if (self) {
        self->port = puerto;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    // HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        //  HAL_GPIO_SET_STATE(self->port, self->bit);
    }
}

bool gpioGetState(gpio_t self) {
    // return HAL_GPIO_GET_STATE(self->port, self->bit);
}
