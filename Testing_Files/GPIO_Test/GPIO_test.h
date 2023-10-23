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
//
///*********************** Services Prototype ******************************/
//void TestDelay(void);
//
///************************** Global Variables **********************************/
//
///******************************** channelId ****** direction ****** function ****** SignalType ****** Current ** Connection**/
//Gpio_PinConfig_t GPIO_pins[] = { {CH_PORTF_PIN0 , GPIO_INPUT  , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , DEFAULT , PULLED_UP } ,
//                                 {CH_PORTF_PIN4 , GPIO_INPUT  , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , DEFAULT , PULLED_UP } ,
//                                 {CH_PORTF_PIN1 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , DEFAULT , OUTPUT    } ,
//                                 {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , DEFAULT , OUTPUT    } ,
//                                 {CH_PORTF_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , DEFAULT , OUTPUT    } ,
//                               };
//
//int main(void)
//{
//    u32 i ;
//    SYSCTL_RCGCGPIO_R |= 0x20;      /* enable clock to PORTF */
//
//    Gpio_PinConfigInit(&(GPIO_pins[0]));
//    Gpio_PinConfigInit(&(GPIO_pins[1]));
//    Gpio_PinConfigInit(&(GPIO_pins[2]));
//    Gpio_PinConfigInit(&(GPIO_pins[3]));
//    Gpio_PinConfigInit(&(GPIO_pins[4]));

//    /*off*/
//    Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
//    Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_HIGH);
//    Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
//
////    TestDelay();
//
//
//    while(1)
//    {
/////************************** ******************************************************************* **********************************/
//        if(STD_LOW == Gpio_ReadChannel(GPIO_pins[0].channelId) && STD_LOW == Gpio_ReadChannel(GPIO_pins[1].channelId) )
//        {
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
//            /*red*/
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
//        }
//        else if(STD_HIGH == Gpio_ReadChannel(GPIO_pins[0].channelId) && STD_LOW == Gpio_ReadChannel(GPIO_pins[1].channelId))
//        {
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
//            /*blue*/
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_HIGH);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
//        }
//        else if(STD_HIGH == Gpio_ReadChannel(GPIO_pins[1].channelId) && STD_LOW == Gpio_ReadChannel(GPIO_pins[0].channelId))
//        {
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
//            /*yellow*/
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
//        }
//        else if(STD_HIGH == Gpio_ReadChannel(GPIO_pins[1].channelId) && STD_HIGH == Gpio_ReadChannel(GPIO_pins[0].channelId))
//        {
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
//            /*green*/
//            Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
//            Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
//        }
///////************************** ******************************************************************* **********************************/
////        if( STD_LOW == Gpio_ReadChannel(GPIO_pins[0].channelId)  )
////        {
////            Gpio_WriteChannel(GPIO_pins[3].channelId , STD_LOW);
////            while(STD_LOW == Gpio_ReadChannel(GPIO_pins[0].channelId));
////            for( i = 0 ; i < 2000000 ; i++);
////        }
////        else if (STD_LOW == Gpio_ReadChannel(GPIO_pins[1].channelId))
////        {
////            Gpio_WriteChannel(GPIO_pins[4].channelId , STD_LOW);
////            while(STD_LOW == Gpio_ReadChannel(GPIO_pins[1].channelId));
////            for( i = 0 ; i < 2000000 ; i++);
////        }
////        else
////        {
////            Gpio_WriteChannel(GPIO_pins[2].channelId , STD_HIGH);
////            Gpio_WriteChannel(GPIO_pins[3].channelId , STD_HIGH);
////            Gpio_WriteChannel(GPIO_pins[4].channelId , STD_HIGH);
////
////        }
///////************************** ******************************************************************* **********************************/
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_HIGH);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_HIGH);
////
////        TestDelay();
////
////        Gpio_WriteChannel(GPIO_pins[2].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[3].channelId ,STD_LOW);
////        Gpio_WriteChannel(GPIO_pins[4].channelId ,STD_LOW);
////
////        TestDelay();
//    }
///////************************** ******************************************************************* **********************************/
//    return 0;
//}
///////************************** ******************************************************************* **********************************/
//void TestDelay(void)
//{
//    u32 i = 0 ;
//
//    for(i = 0 ; i < 5000000 ; i++ );
//}
//
