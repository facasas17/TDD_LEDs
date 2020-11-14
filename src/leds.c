#include "leds.h"
//#include "errores.h"

#define LEDS_ALL_OFF    0x0000

#define LED_OFFSET      1

#define LSB             1

uint16_t LedToMask(led){
    if( led > 16 ){
        RegistrarError();
        return 0;
    }
    return (LSB << (led -LED_OFFSET));  // Se puede usar un inline y dejo la decision al compilador de si es funcion o macro
}    

static uint16_t * direccion;    // Al poner static, no se puede modificar

static LedError_t RegistrarError;

void Leds_Create( uint16_t * puerto, LedError_t handler){
    direccion = puerto;
    RegistrarError = handler;
    *direccion = LEDS_ALL_OFF;
}

void Leds_On(uint8_t led){
    *direccion |= LedToMask(led);    // OR bit a bit
}

void Leds_Off(uint8_t led){
    *direccion &= ~LedToMask(led);  // AND bit a bit
}