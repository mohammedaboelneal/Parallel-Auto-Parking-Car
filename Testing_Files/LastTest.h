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
//#include "MCAL/GP_TIMERS/GP_Timers.h"
///************************** Defines Section **********************************/
//
//
///*********************** Services Prototype ******************************/
//void leds_off(void);
//void red_on(void);
//void blue_on(void);
//void green_on(void);
//void green_blue_on(void);
//void green_red_on(void);
//void blue_red_on(void);
//void white_on(void);
//u32 Measure_distance1(void);
//u32 Measure_distance2(void);
//void Timer0ACapture_init(void);
//void Timer2ACapture_init(void);
//void Timer3ACapture_init(void);
//void Delay(u32 counter);
//void TriggerUltraSonic(Gpio_ChannelType_t channel);
//
///* global variables to store and display distance in cm */
//volatile u32 time1; /*stores pulse on time */
//volatile u32 distance1; /* stores measured distance value */
//
//volatile u32 time2; /*stores pulse on time */
//volatile u32 distance2; /* stores measured distance value */
//
//volatile u32 time3; /*stores pulse on time */
//volatile u32 distance3; /* stores measured distance value */
//
//Gpio_PinConfig_t App_Pins[9] = {
//                                 {CH_PORTF_PIN1 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN0_GPIO , DEFAULT , OUTPUT    } ,     /*red led*/
//                                 {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN1_GPIO , DEFAULT , OUTPUT    } ,     /*blue led*/
//                                 {CH_PORTF_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*green led*/
//
//                                 {CH_PORTA_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN3_GPIO , DEFAULT , OUTPUT    } ,     /*trigger US2*/
//                                 {CH_PORTA_PIN4 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN4_GPIO , DEFAULT , OUTPUT    } ,     /*trigger US1*/
//                                 {CH_PORTA_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*trigger US3*/
//
//                                 {CH_PORTC_PIN0 , GPIO_INPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTC_PIN0_T4CCP0 , DEFAULT , OUTPUT    } ,     /*green led*/
//                                 {CH_PORTB_PIN7 , GPIO_INPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTB_PIN7_T0CCP1 , DEFAULT , OUTPUT } ,     /*Echo US2*/
//                                 {CH_PORTB_PIN6 , GPIO_INPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTB_PIN6_T0CCP0 , DEFAULT , OUTPUT }       /*Echo US1*/
//                                };
//
//int main(void)
//{
//    /*1- CLk for GPIO ports A,B,F and Timer 0 , 3*/
//    SysCtrl_EnableClk_GPIO(GPIO_PORTA);
//    SysCtrl_EnableClk_GPIO(GPIO_PORTB);
//    SysCtrl_EnableClk_GPIO(GPIO_PORTC);
//    SysCtrl_EnableClk_GPIO(GPIO_PORTF);
//
//    SysCtrl_EnableClk_TIMER(TIMER0);
//
//    /*2- start Configuration of the pins all pin*/
//    Gpio_PinConfigInit(&( App_Pins[0]));
//    Gpio_PinConfigInit(&( App_Pins[1]));
//    Gpio_PinConfigInit(&( App_Pins[2]));
//    Gpio_PinConfigInit(&( App_Pins[3]));
//    Gpio_PinConfigInit(&( App_Pins[4]));
//    Gpio_PinConfigInit(&( App_Pins[5]));
//    Gpio_PinConfigInit(&( App_Pins[6]));
//    Gpio_PinConfigInit(&( App_Pins[7]));
//    Gpio_PinConfigInit(&( App_Pins[8]));
//
//    GPT_Timer1A_InputCaptureInit();  /*initialize Timer0A in edge edge time */
//    GPT_Timer0A_InputCaptureInit();  /*initialize Timer3A in edge edge time */
//
//
//    while(1)
//    {
//
//        time1 = Measure_distance1(); /* take pulse duration measurement */
//
//        distance1 = (time1 * 10625)/10000000; /* convert pulse duration into distance */
//
//        if(distance1 > 20)
//        {
//            time2 = Measure_distance2();
//            distance2 = (time2 * 10625)/10000000;
//
//            if(distance2 > 20)
//            {
//                /*delay 5ms*/
//
//                /*read 1 , 2 */
//
//                /* if 1and2 > 20*/
//                    /*auto park*/
//                /* else*/
//                    /*move forward*/
//
//                red_on();
//            }
//            else
//            {
//                /*Keep forword*/
//                blue_on();
//            }
//        }
//        else
//        {
//            white_on();
//
//            /*Keep going*/
//            /*M1 forward , m2 disabled*/
//        }
//
//        /*210 ms delay*/
//        Delay_US(210000);
//    }
//
//}
//
//
///* This function captures consecutive rising and falling edges of a periodic signal */
///* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
//u32 Measure_distance1(void)
//{
//    /*Timer 0*/
//    /* Given 10us trigger pulse */
//    TriggerUltraSonic(CH_PORTA_PIN4);
//
//    return GPT_Timer1A_GetPulseWidth();
//}
//
//u32 Measure_distance2(void)
//{
//    /*Timer 3*/
//
//    TriggerUltraSonic(CH_PORTA_PIN3);
//
//    return GPT_Timer0A_GetPulseWidth();
//}
//
//
//void TriggerUltraSonic(Gpio_ChannelType_t channel)
//{
//    Gpio_WriteChannel(channel, STD_LOW);
//    Delay_US(10);
//    Gpio_WriteChannel(channel, STD_HIGH);
//    Delay_US(10);
//    Gpio_WriteChannel(channel, STD_LOW);
//    Delay_US(10);
//}
//
//void leds_off(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//}
//
//void red_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//}
//
//void blue_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//}
//
//void green_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
//}
//
//void green_blue_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
//}
//
//void green_red_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
//}
//
//void blue_red_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//}
//
//void white_on(void)
//{
//    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
//}
