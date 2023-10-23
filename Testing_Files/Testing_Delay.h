///**
// *      @Project    :   This project implement the Parallel Auto-parking feature
// *      @components :   Small Car Kit, Ultra-sonic Sensors "HC-SR04" , DC Motors, H-Bridge "L298n", ....
// *
// *
// *      @file    :   main.c
// *      @Author  :   AVELABS Group 1
// *      @Brief   :   This is the main file of the project
// */
//
///************************** Includes Section **********************************/
//#include "MCAL/GPIO/Gpio.h"
//#include "SYS_CTRL/Sys_Ctrl.h"
//#include "MCAL/SysTick/Delay/delay.h"
///*********************** Services Prototype ******************************/
//
//
///************************** Global Variables **********************************/
//Gpio_PinConfig_t App_Pins[3] = {
//                                 {CH_PORTF_PIN1 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN0_GPIO , DEFAULT , OUTPUT    } ,     /*red led*/
//                                 {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN1_GPIO , DEFAULT , OUTPUT    } ,     /*blue led*/
//                                 {CH_PORTF_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*green led*/
//                               };
//
//
//
//int main(void)
//{
//    /*1- CLk for GPIO ports A,B,F and Timer 0 , 3*/
//    SysCtrl_EnableClk_GPIO(GPIO_PORTF);
//
//    /*2- start Configuration of the pins all pin*/
//    Gpio_PinConfigInit(&( App_Pins[0]));
//    Gpio_PinConfigInit(&( App_Pins[1]));
//    Gpio_PinConfigInit(&( App_Pins[2]));
//
//
//    while(1)
//    {
//        Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//        Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//        Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//
//        Delay_MS(1000);
//        Delay_US(1000);
//
//        Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//        Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//        Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//
//        Delay_MS(1000);
//        Delay_US(1000);
//
//        Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//        Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//        Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
//
//        Delay_MS(1000);
//        Delay_US(1000);
//
//        Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//        Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//        Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//
//        Delay_MS(1000);
//        Delay_US(1000);
//
//    }
//
//    return 0;
//}
