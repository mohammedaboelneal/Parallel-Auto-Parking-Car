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
///*********************** Services Prototype ******************************/
//
//
///************************** Global Variables **********************************/
//Gpio_PinConfig_t GPIO_pins[] = {
//                                 {CH_PORTF_PIN1 , GPIO_OUTPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTF_PIN1_T0CCP1 , DEFAULT , OUTPUT    } ,
//                                 {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN2_GPIO , DEFAULT , OUTPUT    } ,
//                                 {CH_PORTF_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTF_PIN3_T1CCP1 , DEFAULT , OUTPUT    }
//                                };
//
//int main(void)
//{
//    SysCtrl_EnableClk_GPIO(GPIO_PORTF);      /* enable clock to PORTF */
//
//    Gpio_PinConfigInit(&(GPIO_pins[0]));
//    Gpio_PinConfigInit(&(GPIO_pins[1]));
//    Gpio_PinConfigInit(&(GPIO_pins[2]));
//    Gpio_WriteChannel(GPIO_pins[0].channelId ,STD_HIGH);
//    Gpio_WriteChannel(GPIO_pins[1].channelId ,STD_HIGH);
//    Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
//
//
//    while(1)
//    {
//
//    }
//
//    return 0;
//}
