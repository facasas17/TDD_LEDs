#include "stdint.h"

typedef void (*LedError_t)(void);   // Puntero a una funcion que recibe void y devuelve void

void Leds_Create( uint16_t * puerto, LedError_t handler);

void Leds_On(uint8_t led);

void Leds_Off(uint8_t led);
