/**
 *      @Project    :   This project implement the Parallel Auto-parking feature
 *      @components :   Small Car Kit, Ultra-sonic Sensors "HC-SR04" , DC Motors, H-Bridge "L298n", ....
 *
 *
 *      @file    :   main.c
 *      @Author  :   AVELABS Group 1
 *      @Brief   :   This is the main file of the project
 */

/************************** Includes Section **********************************/
#include "MCAL/GPIO/Gpio.h"
#include "SYS_CTRL/Sys_Ctrl.h"
#include "MCAL/SysTick/Delay/delay.h"
#include "MCAL/GP_TIMERS/GP_Timers.h"

#include "APP/US_App/US_App.h"
#include "APP/DCM_App/NTI_DC_MOTOR_APP.h"

/************************** Defines Section **********************************/


/*********************** Services Prototype ******************************/
void leds_off(void);
void red_on(void);
void blue_on(void);
void green_on(void);
void green_blue_on(void);
void green_red_on(void);
void blue_red_on(void);
void white_on(void);

void FindSlotToPark(void);
void DoAutoParking(void);
void autop(void);

/* global variables to store and display distance in cm */

volatile u32 distance1; /* stores measured distance value */

volatile u32 distance2; /* stores measured distance value */

volatile u32 distance3; /* stores measured distance value */

volatile u32 distance4; /* stores measured distance value */


Gpio_PinConfig_t App_Pins[2] = {
                                {CH_PORTF_PIN1 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN1_GPIO , DEFAULT , OUTPUT    } ,     /*red led*/
                                //                                {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*blue led*/
                                {CH_PORTF_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN3_GPIO , DEFAULT , OUTPUT    }      /*green led*/
};


u8 AutoParkFlag = 0 ;

int main(void)
{
    u8 ParkDoneFlag = 0;

    SysCtrl_EnableClk_GPIO(GPIO_PORTF);

    Gpio_PinConfigInit(&( App_Pins[0]));
    Gpio_PinConfigInit(&( App_Pins[1]));

    US_InitAllModules();
    NTI_DCM_InitAll();



    while(1)
    {
//        distance1 = US1_GetDistance();
//        Delay_MS(100);
//        distance2 = US2_GetDistance();
//        if(distance1 < 20 || distance2 < 20)
//        {
//            NTI_DCM_MoveForward(70);
//        }
//        else
//        {
//            NTI_DCM_Stop();
//        }
        distance1 = US1_GetDistance();
        Delay_MS(100);
        distance2 = US2_GetDistance();
        Delay_MS(100);
        distance4 = US4_GetDistance();
        if((distance2 < 12) && (ParkDoneFlag == 0))
        {
            distance1 = US1_GetDistance();
            if(distance1 < 12)
            {
                NTI_DCM_MoveForward(50);
            }
        }
        else if((distance1 > 20) && (distance2 > 20) && (ParkDoneFlag == 0))
        {
            NTI_DCM_MoveForward(40);
            ParkDoneFlag = 1;
        }
        //// finding another car ahead
        else if((distance2 < 15) && (distance1 < 15) && (ParkDoneFlag == 1))
        {
            NTI_DCM_MoveBackward(100);
            NTI_DCM_MoveBackward(100);
            Delay_MS(600);
            NTI_DCM_Stop();
            ParkDoneFlag = 2;
            NTI_DCM_MoveLeft(100);
        }
        // parking
        else if(ParkDoneFlag == 2)
        {
            NTI_DCM_MoveRight(100);
            distance2 = US2_GetDistance();
            Delay_MS(100);
            distance4 = US4_GetDistance();

            while(distance2 > 30 || distance4 > 30)
            {
                Delay_MS(10);
                NTI_DCM_MoveBackward(40);
                Delay_MS(100);
                distance2 = US2_GetDistance();
                Delay_MS(100);
                distance4 = US4_GetDistance();
            }
            ParkDoneFlag = 3 ;
            NTI_DCM_MoveRight(90);
//            NTI_DCM_Stop();
//            Delay_MS(200);

        }
        else if ((ParkDoneFlag == 3))
        {
            Delay_MS(10);
            NTI_DCM_MoveLeft(100);
            NTI_DCM_MoveBackward(70);
            if ((distance4 < 8) || ((distance2 < 12) && (distance1 < 12)))
            {
                NTI_DCM_MoveRight(100);
                NTI_DCM_MoveForward(80);
                Delay_MS(1500);
                NTI_DCM_MoveLeft(100);
                NTI_DCM_MoveBackward(50);
                Delay_MS(1000);
                NTI_DCM_Stop();
                ParkDoneFlag = 4 ;
            }

        }

    }
//
}

void leds_off(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
}

void red_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
}

void blue_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
}

void green_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
}

void green_blue_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
}

void green_red_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
}

void blue_red_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
}

void white_on(void)
{
    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
    //    Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
    Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
}

