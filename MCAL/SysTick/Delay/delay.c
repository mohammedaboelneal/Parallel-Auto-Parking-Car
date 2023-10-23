/*
 *      @file       :   delay.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the DELAY driver
 *      @Note       :   This file use the SysTick Timer to create delays
 */

/************************** Includes Section **********************************/
#include "delay.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : Delay_US
 *  @Parameters (in)        : delay -> the delay value in micro-seconds from the type " u32 "
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : This function use CPU_Frequency = 16 MHz, Max Delay = 1048575 us "1.048757 S", otherwise max delay only done
 *  @Brief                  : Function used to create delays
 *  @Expected Output        : a delay with the specified value is done
 * */
void Delay_US(u32 delay)
{
    /*1- calc. the reload value */
    u32 ReloadValue = (delay * 16) ;

    /*2- Init the sysTick Peripherals*/
    SysTick_Init(ReloadValue);

    /*3- Start Counting*/
    SysTick_Start();

    /*4- Wait  till flag is raised*/
    while( READ_BIT(NVIC_ST_CTRL_R , SYSTICK_COUNT_FLAG) == STD_LOW );

    /*5- stop counting*/
    SysTick_Stop();
}

/*  @Service name           : Delay_MS
 *  @Parameters (in)        : delay -> the delay value in Milli-seconds from the type " u16"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : This function use CPU_Frequency = 16 MHz, Max Delay = 1048.575 ms "1.048757 S", otherwise max delay only done
 *  @Brief                  : Function used to create delays
 *  @Expected Output        : a delay with the specified value is done
 * */
void Delay_MS(u16 delay)
{
    /*Convert it into us*/
    u32 delay_Us = delay * 1000;

    /*call the us delay function*/
    Delay_US( delay_Us );
}
