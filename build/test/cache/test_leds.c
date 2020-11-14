#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"














uint16_t ledsVirtuales;





_Bool 

    error_informado = 

                      0

                           ;



void RegistrarError(void){

    error_informado = 

                     1

                         ;

}



void setUp( void ){



    error_informado = 

                     0

                          ;

    Leds_Create(&ledsVirtuales, RegistrarError);

}



void tearDown( void ){



}





void test_LedsOffAfterCreate( void ){

    uint16_t ledsVirtuales = 0xFFFF;



    Leds_Create(&ledsVirtuales, RegistrarError);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_individual(void){



    Leds_On(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_led_individual(void){



    Leds_On(1);

    Leds_Off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_apagar_multiples(void){

    Leds_On(3);

    Leds_On(4);

    Leds_Off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 3)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_invalido(void){

    Leds_On(17);

    do {if ((error_informado)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(62)));}} while(0);

}





void test_All_Leds_Off(void){

    All_Leds_Off();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

}





void test_All_Leds_On(void){

    All_Leds_On();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_HEX16);

}





void test_estado_led( void ){

    Leds_On(5);

    get_Led(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX16);

}
