/*
 *      @file       :   GP_Timers.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the GPT driver
 *                      and all definitions and types for their implementation
 */

#ifndef MCAL_GP_TIMERS_GP_TIMERS_H_
#define MCAL_GP_TIMERS_GP_TIMERS_H_

/*****************************  Includes Sections ***************************/
#include "../../TM4C123GH6PM_Registers/tm4c123gh6pm.h"
#include "../../utils/Bit_math.h"
#include "../../utils/Std_types.h"
#include "../GPIO/Gpio.h"
#include "GP_Timer_Types.h"

/*********************** Services Prototype ******************************/
/*  @Service name           : GPT_Timer0A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 0 in Input Edge Time Mode
 *  @Expected Output        : Pin of T0CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer0A_InputCaptureInit(void);

/*  @Service name           : GPT_Timer1A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 1 in Input Edge Time Mode
 *  @Expected Output        : Pin of T1CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer1A_InputCaptureInit(void);

/*  @Service name           : GPT_Timer2A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 2 in Input Edge Time Mode
 *  @Expected Output        : Pin of T2CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer2A_InputCaptureInit(void);

/*  @Service name           : GPT_Timer3A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 3 in Input Edge Time Mode
 *  @Expected Output        : Pin of T3CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer3A_InputCaptureInit(void);

/*  @Service name           : GPT_Timer4A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 4 in Input Edge Time Mode
 *  @Expected Output        : Pin of T4CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer4A_InputCaptureInit(void);

/*  @Service name           : GPT_Timer5A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 5 in Input Edge Time Mode
 *  @Expected Output        : Pin of T5CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer5A_InputCaptureInit(void);

/*  @Service name           : GPT_Timer0A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 0 channel A
 *  @Expected Output        : Pulse width on T0CCP0 Pin
 * */
u32 GPT_Timer0A_GetPulseWidth(void);

/*  @Service name           : GPT_Timer1A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 1 channel A
 *  @Expected Output        : Pulse width on T1CCP0 Pin
 * */
u32 GPT_Timer1A_GetPulseWidth(void);

/*  @Service name           : GPT_Timer2A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 2 channel A
 *  @Expected Output        : Pulse width on T2CCP0 Pin
 * */
u32 GPT_Timer2A_GetPulseWidth(void);

/*  @Service name           : GPT_Timer3A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 3 channel A
 *  @Expected Output        : Pulse width on T3CCP0 Pin
 * */
u32 GPT_Timer3A_GetPulseWidth(void);

/*  @Service name           : GPT_Timer4A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 4 channel A
 *  @Expected Output        : Pulse width on T4CCP0 Pin
 * */
u32 GPT_Timer4A_GetPulseWidth(void);

/*  @Service name           : GPT_Timer5A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 5 channel A
 *  @Expected Output        : Pulse width on T5CCP0 Pin
 * */
u32 GPT_Timer5A_GetPulseWidth(void);

#endif /* MCAL_GP_TIMERS_GP_TIMERS_H_ */
