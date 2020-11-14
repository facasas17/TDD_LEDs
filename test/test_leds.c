#include "unity.h"
#include "leds.h"

/**
 * Se pueden apagar todos los LEDs de una vez
 * Se pueden prender todos los LEDs de una vez
 * Se puede consultar el estado de un LED
 * Revisar limites de los parametros
 * */

//#include "mock_errores.h"   // Genera una función ficticia del header en errores.h

uint16_t ledsVirtuales;

_Bool error_informado = FALSE;

void RegistrarError(void){
    error_informado = TRUE;
}

void setUp( void ){
    // Funciones optativas las crea el ceedling si no las defino. Se ejecuta antes de cada test
    error_informado = FALSE;
    Leds_Create(&ledsVirtuales, RegistrarError);
}

void tearDown( void ){
    // Funciones optativas las crea el ceedling si no las defino. . Se ejecuta antes de cada test
}

// Despues de inicializar, los LEDs quedan apagados
void test_LedsOffAfterCreate( void ){
    uint16_t ledsVirtuales = 0xFFFF;             //Leds en 1

    Leds_Create(&ledsVirtuales, RegistrarError); //Llamo a la funcion
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);  // Comparo el resultado contra 0
}

// Se puede prender un LED individual
void test_prender_led_individual(void){

    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

// Se puede apagar un LED individual
void test_apagar_led_individual(void){

    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LEDs
void test_prender_apagar_multiples(void){
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 3, ledsVirtuales);     // Chequeo que el bit 4 quede encendido
}

// Revisar parametros fuera de los limites
void test_prender_led_invalido(void){
    Leds_On(17);
    TEST_ASSERT_TRUE(error_informado);   
}

