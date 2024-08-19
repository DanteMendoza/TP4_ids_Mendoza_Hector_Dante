/*!
    \file main.c
    \brief Función principal del programa.
    \author Hector Dante Mendoza
    \date 2024-08-19
*/

/* === Headers files inclusions =============================================================== */

#include "main.h"
#include "gpio.h"

/* === Macros definitions ====================================================================== */

#define LED_ROJO_PUERTO 1
#define LED_ROJO_BIT    7

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/*!
    \brief Función principal del programa.
    \return int Código de retorno del programa.
*/
int main(void) {
    // Configuro como salida
    gpioSetDirection(LED_ROJO_PUERTO, LED_ROJO_BIT, true);
    // Prendo el led
    gpioSetOutput(LED_ROJO_PUERTO, LED_ROJO_BIT, true);

    gpio_t led_rojo = gpioCreate(LED_ROJO_PUERTO, LED_ROJO_BIT);
    gpioSetOutput(led_rojo, true);
    gpioSetState(led_rojo, true);

    led_rojo.gpioSetState(true)
	
	while (1) {
        // Aquí podría ir el código principal que maneja el ciclo de vida del programa
    }

    return 0;
}

/* === End of documentation ==================================================================== */
