/*
 *      @file       :   PWM.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the GPT driver
 *                      and all definitions and types for their implementation
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

/*****************************  Includes Sections ***************************/
#include "../../TM4C123GH6PM_Registers/tm4c123gh6pm.h"
#include "../../utils/Bit_math.h"
#include "../../utils/Std_types.h"
#include "PWM_Types.h"


/*****************************  Defines Sections ***************************/
#define LOAD_VALUE                  5000
#define MAX_COMPARE_VALUE           4999

#define MAX_DUTY                    100

#define MIN_DUTY                    0

/*********************** Services Prototype ******************************/
/*  @Service name           : PWM_M1_Gen3_Channel6_Init
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel 6 in PWM 1 Generator 3
 *  @Expected Output        : Pin of PWM Module 1 Generator 3 channel 6 is ready to be generate PWM
 * */
void PWM_M1_Gen3_Channel6_Init(void);

/*  @Service name           : PWM_M1_Gen2_Channel4_Init
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel 4 in PWM 1 Generator 2
 *  @Expected Output        : Pin of PWM Module 1 Generator 2 channel 4 is ready to be generate PWM
 * */
void PWM_M1_Gen2_Channel4_Init(void);

/*  @Service name           : PWM_M1_Gen3_Channel6_SetDuty
 *  @Parameters (in)        : Duty -> The Duty cycle of the PWM from the Type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : If the Duty is greater than 100 it will assume it as MAX Duty of 100%
 *  @Brief                  : Function used to Set the Duty cycle of the Generated PWM signal using channel 6 in PWM 1 Generator 3
 *  @Expected Output        : Duty cycle of the generated PWM Signal changed
 * */
void PWM_M1_Gen3_Channel6_SetDuty(u8 Duty);

/*  @Service name           : PWM_M1_Gen2_Channel4_SetDuty
 *  @Parameters (in)        : Duty -> The Duty cycle of the PWM from the Type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : If the Duty is greater than 100 it will assume it as MAX Duty of 100%
 *  @Brief                  : Function used to Set the Duty cycle of the Generated PWM signal using channel 4 in PWM 1 Generator 2
 *  @Expected Output        : Duty cycle of the generated PWM Signal changed
 * */
void PWM_M1_Gen2_Channel4_SetDuty(u8 Duty);

#endif /* MCAL_PWM_PWM_H_ */
