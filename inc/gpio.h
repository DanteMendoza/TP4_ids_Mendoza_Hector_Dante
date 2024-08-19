/*!
    \file gpio.h
    \brief Archivo de cabecera para las funciones de control de GPIO.
    \author Hector Dante Mendoza
    \date 2024-08-19
*/

#include <stdint.h>
#include <stdbool.h>

/*!
    \brief Definición del tipo de manejador para GPIO.
*/
typedef struct gpio_s * gpio_t;

/*!
    \brief Crea un objeto GPIO.
    \param puerto Número de puerto donde se encuentra el GPIO.
    \param bit Número de bit del GPIO.
    \return gpio_t Manejador al objeto GPIO creado.
*/
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/*!
    \brief Configura el GPIO como salida o entrada.
    \param gpio Manejador al objeto GPIO.
    \param output Establecer en true para salida, false para entrada.
*/
void gpioSetOutput(gpio_t gpio, bool output);

/*!
    \brief Establece el estado del GPIO.
    \param gpio Manejador al objeto GPIO.
    \param state Establecer en true para poner el GPIO en alto, false para ponerlo en bajo.
*/
void gpioSetState(gpio_t gpio, bool state);

/*!
    \brief Obtiene el estado actual del GPIO.
    \param gpio Manejador al objeto GPIO.
    \return bool Estado actual del GPIO (true si está en alto, false si está en bajo).
*/
bool gpioGetState(gpio_t gpio);

