/*!
    \file gpio.c
    \brief Implementación de las funciones de control de GPIO.
    \author Hector Dante Mendoza
    \date 2024-08-19
*/

#include "gpio.h"

// Definición interna de la estructura gpio_s
struct gpio_s {
    uint8_t puerto;
    uint8_t bit;
    bool estado;
};

/*!
    \brief Crea un objeto GPIO.
    \param puerto Número de puerto donde se encuentra el GPIO.
    \param bit Número de bit del GPIO.
    \return gpio_t Manejador al objeto GPIO creado.
*/
gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
    gpio_t nuevo_gpio = (gpio_t)malloc(sizeof(struct gpio_s));
    if (nuevo_gpio != NULL) {
        nuevo_gpio->puerto = puerto;
        nuevo_gpio->bit = bit;
        nuevo_gpio->estado = false;
    }
    return nuevo_gpio;
}

/*!
    \brief Configura el GPIO como salida o entrada.
    \param gpio Manejador al objeto GPIO.
    \param output Establecer en true para salida, false para entrada.
*/
void gpioSetOutput(gpio_t gpio, bool output) {
    // Aquí iría el código para configurar el GPIO como entrada o salida
    gpio->estado = output;
}

/*!
    \brief Establece el estado del GPIO.
    \param gpio Manejador al objeto GPIO.
    \param state Establecer en true para poner el GPIO en alto, false para ponerlo en bajo.
*/
void gpioSetState(gpio_t gpio, bool state) {
    // Aquí iría el código para establecer el estado del GPIO
    gpio->estado = state;
}

/*!
    \brief Obtiene el estado actual del GPIO.
    \param gpio Manejador al objeto GPIO.
    \return bool Estado actual del GPIO (true si está en alto, false si está en bajo).
*/
bool gpioGetState(gpio_t gpio) {
    // Aquí iría el código para obtener el estado actual del GPIO
    return gpio->estado;
}
