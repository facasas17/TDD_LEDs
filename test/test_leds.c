#include "unity.h"
#include "leds.h"

/**
 * Revisar limites de los parametros
 * */

//#include "mock_errores.h"   // Genera una función ficticia del header en errores.h

uint16_t ledsVirtuales;

bool error_informado = false;

void RegistrarError(void){
    error_informado = true;
}

void setUp( void ){
    // Funciones optativas las crea el ceedling si no las defino. Se ejecuta antes de cada test
    error_informado = false;
    Leds_Create(&ledsVirtuales, RegistrarError);
}

void tearDown( void ){
    // Funciones optativas las crea el ceedling si no las defino. . Se ejecuta antes de cada test
}

// Despues de inicializar, los LEDs quedan apagados
void test_LedsOffAfterCreate( void ){
    uint16_t ledsVirtuales = LEDS_ALL_ON;             //Leds en 1

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

// Se pueden apagar todos los LEDs de una vez
void test_All_Leds_Off(void){
    All_Leds_Off();
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

// Se pueden encender todos los LEDs de una vez
void test_All_Leds_On(void){
    All_Leds_On();
    TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_ON, ledsVirtuales);
}

// Se puede consultar el estado de un LED
void test_estado_led( void ){
    bool estado;

    Leds_Off(5);     // Enciendo el LED 5
    estado = get_Led(5);     // Consulto el estado del LED 5
    TEST_ASSERT_EQUAL_HEX16( 0 , estado);  // Chequeo que el estado sea encendido
}