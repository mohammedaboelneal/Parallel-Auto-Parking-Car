/*
 *      @file       :   delay.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the DELAY driver
 *                      and all definitions and types for their implementation
 *      @Note       :   This file use the SysTick Timer to create delays
 */

#ifndef MCAL_GP_TIMERS_DELAY_DELAY_H_
#define MCAL_GP_TIMERS_DELAY_DELAY_H_

/*****************************  Includes Sections ***************************/
#include "../SysTick.h"

/*********************** Services Prototype ******************************/
/*  @Service name           : Delay_US
 *  @Parameters (in)        : delay -> the delay value in micro-seconds from the type " u32"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : This function use CPU_Frequency = 16 MHz
 *  @Brief                  : Function used to create delays
 *  @Expected Output        : a delay with the specified value is done
 * */
void Delay_US(u32 delay);

/*  @Service name           : Delay_MS
 *  @Parameters (in)        : delay -> the delay value in Milli-seconds from the type " u16"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : This function use CPU_Frequency = 16 MHz
 *  @Brief                  : Function used to create delays
 *  @Expected Output        : a delay with the specified value is done
 * */
void Delay_MS(u16 delay);


#endif /* MCAL_GP_TIMERS_DELAY_DELAY_H_ */
