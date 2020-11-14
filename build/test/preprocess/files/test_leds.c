#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




uint16_t ledsVirtuales;



_Bool error_informado = FALSE;



void RegistrarError(void){

    error_informado = TRUE;

}



void setUp( void ){



    error_informado = FALSE;

    Leds_Create(&ledsVirtuales, RegistrarError);

}



void tearDown( void ){



}





void test_LedsOffAfterCreate( void ){

    uint16_t ledsVirtuales = 0xFFFF;



    Leds_Create(&ledsVirtuales, RegistrarError);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_individual(void){



    Leds_On(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_led_individual(void){



    Leds_On(1);

    Leds_Off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_apagar_multiples(void){

    Leds_On(3);

    Leds_On(4);

    Leds_Off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 3)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}







void test_prender_led_invalido(void){

    Leds_On(17);

    do {if ((error_informado)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

}
