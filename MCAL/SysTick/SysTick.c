/*
 *      @file       :   SysTick.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the SysTick driver
 */

/************************** Includes Section **********************************/
#include "SysTick.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : SysTick_Init
 *  @Parameters (in)        : ReloadValue -> the SysTick reload value from the type " u32"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : If the reload Value is greater than 0xFFFFFF, It will be considered as 0xFFFFFF as it is the maximum value
 *  @Brief                  : Function used to initialize SysTick registers and be ready
 *  @Expected Output        : initialize for being counting from RELOAD_VALUE to 0
 * */
void SysTick_Init(u32 ReloadValue)
{
    /*1- disable the SysTick*/
    NVIC_ST_CTRL_R = 0 ;

    /*2- set the reload value*/
    if(ReloadValue > SYSTICK_MAX)
    {
        NVIC_ST_RELOAD_R = SYSTICK_MAX ;
    }
    else
    {
        NVIC_ST_RELOAD_R = ReloadValue ;
    }

    /*3- clear current register and flag*/
    NVIC_ST_CURRENT_R = DUMMY_DATA ;

    /*4- enable the CLK source*/
    SET_BIT(NVIC_ST_CTRL_R , SYSTICK_CLK_SOURCE_BIT);
}

/*  @Service name           : SysTick_Start
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to start SysTick counting
 *  @Expected Output        : counting start
 * */
void SysTick_Start(void)
{
    SET_BIT(NVIC_ST_CTRL_R , SYSTICK_ENABLE_BIT);
}


/*  @Service name           : SysTick_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop SysTick counting
 *  @Expected Output        : counting stop
 * */
void SysTick_Stop(void)
{
    NVIC_ST_CTRL_R = 0 ;
}
