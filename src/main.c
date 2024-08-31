/************************************************************************************************
Copyright (c) 2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
INFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file main.c
 * @brief Definición de la función principal del programa
 */

 /* === Inclusión de archivos de cabecera ====================================================== */

#include "main.h"
#include "gpio.h"

/* === Definiciones de macros ================================================================= */

/**
 * @def LED_ROJO_PUERTO
 * @brief Puerto al que está conectado el LED rojo.
 */
#define LED_ROJO_PUERTO 1

/**
 * @def LED_ROJO_BIT
 * @brief Bit al que está conectado el LED rojo.
 */
#define LED_ROJO_BIT    7

/* === Declaraciones de tipos de datos privados ================================================= */

/* === Declaraciones de variables privadas ======================================================= */

/* === Declaraciones de funciones privadas ======================================================= */

/* === Definiciones de variables públicas ========================================================= */

/* === Definiciones de variables privadas ========================================================= */

/* === Implementación de funciones privadas ======================================================= */

/* === Implementación de funciones públicas ======================================================== */

/**
 * @brief Función principal del programa.
 *
 * Configura el GPIO para controlar el LED rojo y enciende el LED.
 *
 * @return int Código de salida del programa.
 */
int main(void) {
    // Configuro como salida
    gpioSetDirection(LED_ROJO_PUERTO, LED_ROJO_BIT, true);
    // Prendo el led
    gpioSetOutput(LED_ROJO_PUERTO, LED_ROJO_BIT, true);

    gpio_t led_rojo = gpioCreate(LED_ROJO_PUERTO, LED_ROJO_BIT);
    gpioSetOutput(led_rojo, true);
    gpioSetState(led_rojo, true);

    led_rojo.gpioSetState(true);
    
    return 0;
}

/* === Fin de la documentación ==================================================================== */
