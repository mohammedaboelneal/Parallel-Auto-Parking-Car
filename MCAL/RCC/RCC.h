/*
 *      @file       :   RCC.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the RCC driver.
 */

#ifndef MCAL_RCC_RCC_H_
#define MCAL_RCC_RCC_H_

/*****************************  Includes Sections ***************************/
#include "../../TM4C123GH6PM_Registers/tm4c123gh6pm.h"
#include "../../utils/Bit_math.h"
#include "../../utils/Std_types.h"

/*********************** Services Prototype ******************************/
/*  @Service name           : RCC_EnableClkDivisor
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock divisor to be used
 *  @Expected Output        : Clock divisor enabled and CPU frequency can be divided
 * */
void RCC_EnableClkDivisor(void);

/*  @Service name           : RCC_PWM_CLK_Div64
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to divide the PWM CLk divider by 64
 *  @Expected Output        : PWM Clock divisor by 64
 * */
void RCC_PWM_CLK_Div64(void);


#endif /* MCAL_RCC_RCC_H_ */
