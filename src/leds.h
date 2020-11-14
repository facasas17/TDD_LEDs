#include "stdint.h"
#include "stdbool.h"

#define LEDS_ALL_OFF    0x0000

#define LEDS_ALL_ON    0xFFFF

#define LED_OFFSET      1

#define LSB             1

typedef void (*LedError_t)(void);   // Puntero a una funcion que recibe void y devuelve void

void Leds_Create( uint16_t * puerto, LedError_t handler);

void Leds_On(uint8_t led);

void Leds_Off(uint8_t led);

void All_Leds_Off( void );

void All_Leds_On(void);

bool get_Led(uint8_t led);