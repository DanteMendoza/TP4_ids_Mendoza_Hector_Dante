#include "gpio.h"
#include <stddef.h>

/** @brief Define si se utiliza memoria dinámica para la creación de GPIOs. */
#define USE_DYNAMIC_MEM

#ifndef GPIO_MAX_INSTANCES
/** @brief Número máximo de instancias de GPIO si no se utiliza memoria dinámica. */
#define GPIO_MAX_INSTANCES 10
#endif

/** 
 * @brief Estructura que representa un GPIO.
 */
struct gpio_s {
    uint8_t port;   /**< Puerto al que está conectado el GPIO. */
    uint8_t bit;    /**< Bit específico del puerto. */
    bool output;    /**< Indica si el GPIO está configurado como salida. */
    bool used;      /**< Indica si la instancia está en uso. */
};

/**
 * @brief Asigna una instancia de GPIO utilizando memoria estática.
 *
 * Esta función busca una instancia libre de GPIO en la memoria estática
 * y la marca como utilizada.
 *
 * @return gpio_t Puntero a la instancia de GPIO asignada, o NULL si no hay instancias disponibles.
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

/**
 * @brief Crea una nueva instancia de GPIO.
 *
 * Esta función crea un nuevo GPIO con el puerto y bit especificados.
 * Dependiendo de la configuración, se utiliza memoria dinámica o estática.
 *
 * @param puerto El puerto al que está conectado el GPIO.
 * @param bit El bit específico del puerto.
 * @return gpio_t Puntero a la nueva instancia de GPIO, o NULL si la asignación falla.
 */
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

/**
 * @brief Configura un GPIO como salida.
 *
 * Esta función establece el GPIO especificado como una salida.
 *
 * @param self Puntero a la instancia del GPIO.
 * @param output Valor booleano que indica si el GPIO debe ser una salida.
 */
void gpioSetOutput(gpio_t self, bool output) {
    HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

/**
 * @brief Establece el estado de un GPIO.
 *
 * Esta función cambia el estado (encendido/apagado) de un GPIO.
 *
 * @param self Puntero a la instancia del GPIO.
 * @param state Estado deseado: true para encender, false para apagar.
 */
void gpioSetState(gpio_t self, bool state) {
    HAL_GPIO_SET_STATE(self->port, self->bit);
}

/**
 * @brief Obtiene el estado actual de un GPIO.
 *
 * Esta función devuelve el estado actual del GPIO (encendido/apagado).
 *
 * @param self Puntero a la instancia del GPIO.
 * @return bool Estado actual del GPIO: true si está encendido, false si está apagado.
 */
bool gpioGetState(gpio_t self) {
    return HAL_GPIO_GET_STATE(self->port, self->bit);
}
