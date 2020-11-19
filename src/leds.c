#include "leds.h"

static LedError_t RegistrarError;

uint16_t LedToMask(uint8_t led){
    if( led > 16 ){
        RegistrarError();
        return 0;
    }
    return (LSB << (led -LED_OFFSET));  // Se puede usar un inline y dejo la decision al compilador de si es funcion o macro
}    

static uint16_t * direccion;    // Al poner static, no se puede modificar

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

void All_Leds_Off(void){
    *direccion = LEDS_ALL_OFF;
}

void All_Leds_On(void){
    *direccion = LEDS_ALL_ON;
}

bool get_Led(uint8_t led){
    uint16_t estado = * direccion;

    estado &= LedToMask(led);
    return estado;
}