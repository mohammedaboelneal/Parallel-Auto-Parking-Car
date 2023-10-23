/*
 *      @file       :   SysTick.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the SysTick driver
 *                      and all definitions and types for their implementation
 */

#ifndef MCAL_SYSTICK_SYSTICK_H_
#define MCAL_SYSTICK_SYSTICK_H_

/*****************************  Includes Sections ***************************/
#include "../../TM4C123GH6PM_Registers/tm4c123gh6pm.h"
#include "../../utils/Bit_math.h"
#include "../../utils/Std_types.h"


/*****************************  Defines Sections ***************************/
#define DUMMY_DATA                  0x000000
#define SYSTICK_MAX                 0xFFFFFF
/*define the control register bits*/
#define SYSTICK_ENABLE_BIT          0
#define SYSTICK_INT_ENABLE_BIT      1
#define SYSTICK_CLK_SOURCE_BIT      2
#define SYSTICK_COUNT_FLAG          16

/*********************** Services Prototype ******************************/
/*  @Service name           : SysTick_Init
 *  @Parameters (in)        : ReloadValue -> the SysTick reload value from the type " u32"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : If the reload Value is greater than 0xFFFFFF, It will be considered as 0xFFFFFF as it is the maximum value
 *  @Brief                  : Function used to initialize SysTick registers and be ready
 *  @Expected Output        : initialize for being counting from RELOAD_VALUE to 0
 * */
void SysTick_Init(u32 ReloadValue);

/*  @Service name           : SysTick_Start
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to start SysTick counting
 *  @Expected Output        : counting start
 * */
void SysTick_Start(void);


/*  @Service name           : SysTick_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop SysTick counting
 *  @Expected Output        : counting stop
 * */
void SysTick_Stop(void);


#endif /* MCAL_SYSTICK_SYSTICK_H_ */
