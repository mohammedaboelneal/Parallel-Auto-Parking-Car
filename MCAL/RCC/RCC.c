/*
 *      @file       :   RCC.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains implementation of all interfaces can be used from the RCC driver.
 */
/************************** Includes Section **********************************/
#include "RCC.h"

/*********************** Services Implementation ******************************/
/*  @Service name           : RCC_EnableClkDivisor
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock divisor to be used
 *  @Expected Output        : Clock divisor enabled and CPU frequency can be divided
 * */
void RCC_EnableClkDivisor(void)
{
    /* Enable System Clock Divisor function  */
    SYSCTL_RCC_R |= (1<<20);
}

/*  @Service name           : RCC_PWM_CLK_Div64
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to divide the PWM CLk divider by 64
 *  @Expected Output        : PWM Clock divisor by 64
 * */
void RCC_PWM_CLK_Div64(void)
{
    /* Use pre-divider value of 64 and after that feed clock to PWM1 module*/
    SYSCTL_RCC_R |= 0x000E0000;
}

