#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Defino el tipo de puntero a una estructura GPIO.
 *
 * Este tipo se usa para manejar instancias de GPIO en el sistema.
 */
typedef struct gpio_s * gpio_t;

/**
 * @brief Creo una nueva instancia de un objeto GPIO.
 *
 * Esta función inicializa un nuevo objeto GPIO en el puerto y bit especificados.
 *
 * @param puerto El número del puerto del GPIO.
 * @param bit El número del bit en el puerto del GPIO.
 * @return Un puntero al nuevo objeto GPIO creado.
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/**
 * @brief Establece el valor de salida del GPIO.
 *
 * Esta función configura el estado de salida del GPIO a verdadero (activo) o falso (inactivo).
 *
 * @param gpio El puntero al objeto GPIO.
 * @param output El estado de salida a configurar (true para activo, false para inactivo).
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Establece el estado del GPIO.
 *
 * Esta función configura el estado del GPIO a verdadero (activo) o falso (inactivo).
 *
 * @param gpio El puntero al objeto GPIO.
 * @param state El estado a configurar (true para activo, false para inactivo).
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Obtiene el estado actual del GPIO.
 *
 * Esta función devuelve el estado actual del GPIO (verdadero para activo, falso para inactivo).
 *
 * @param gpio El puntero al objeto GPIO.
 * @return El estado actual del GPIO (true si está activo, false si está inactivo).
 */
bool gpioGetState(gpio_t gpio);
