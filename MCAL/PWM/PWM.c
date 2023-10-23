/*
 *      @file       :   PWM.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the PWM driver
 */

/************************** Includes Section **********************************/
#include "PWM.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : PWM_M1_Gen3_Channel6_Init
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel 6 in PWM 1 Generator 3
 *  @Expected Output        : Pin of PWM Module 1 Generator 3 channel 6 is ready to be generate PWM
 * */
void PWM_M1_Gen3_Channel6_Init(void)
{
    /* Disable Generator 3 counter */
    CLEAR_BIT(PWM1_3_CTL_R , 0);

    /* select down count mode of generator 3 counter*/
    CLEAR_BIT(PWM1_3_CTL_R , 1);

    /* Set PWM output when counter reloaded and clear when matches PWMCMPA */
    PWM1_3_GENA_R = 0x0000008C;

    /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
    PWM1_3_LOAD_R = LOAD_VALUE;

    /* set duty cyle to to minumum value*/
    PWM_M1_Gen3_Channel6_SetDuty(MIN_DUTY);

    /* Enable Generator 3 counter */
    PWM1_3_CTL_R = 1;

    /* Enable PWM1 channel 6 output */
    SET_BIT(PWM1_ENABLE_R , 6);
}

/*  @Service name           : PWM_M1_Gen2_Channel4_Init
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel 4 in PWM 1 Generator 2
 *  @Expected Output        : Pin of PWM Module 1 Generator 2 channel 4 is ready to be generate PWM
 * */
void PWM_M1_Gen2_Channel4_Init(void)
{
    /* Disable Generator 2 counter */
    CLEAR_BIT(PWM1_2_CTL_R , 0);

    /* select down count mode of generator 2 counter*/
    CLEAR_BIT(PWM1_2_CTL_R , 1);

    /* Set PWM output when counter reloaded and clear when matches PWMCMPA */
    PWM1_2_GENA_R = 0x0000008C;

    /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
    PWM1_2_LOAD_R = LOAD_VALUE;

    /* set duty cyle to to minumum value*/
    PWM_M1_Gen2_Channel4_SetDuty(MIN_DUTY);

    /* Enable Generator 2 counter */
    PWM1_2_CTL_R = 1;

    /* Enable PWM1 channel 4 output */
    SET_BIT(PWM1_ENABLE_R , 4);
}

/*  @Service name           : PWM_M1_Gen3_Channel6_SetDuty
 *  @Parameters (in)        : Duty -> The Duty cycle of the PWM from the Type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : If the Duty is greater than 100 it will assume it as MAX Duty of 100%
 *  @Brief                  : Function used to Set the Duty cycle of the Generated PWM signal using channel 6 in PWM 1 Generator 3
 *  @Expected Output        : Duty cycle of the generated PWM Signal changed
 * */
void PWM_M1_Gen3_Channel6_SetDuty(u8 Duty)
{
    u32 CompareValue ;

    /*1- calculate the  compare value*/
    CompareValue = (( (100 - Duty) * LOAD_VALUE ) / 100);

    /*2- set the compare value of PWM 1 Generator 3 channel 6*/
    PWM1_3_CMPA_R = CompareValue ;

}

/*  @Service name           : PWM_M1_Gen2_Channel4_SetDuty
 *  @Parameters (in)        : Duty -> The Duty cycle of the PWM from the Type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : If the Duty is greater than 100 it will assume it as MAX Duty of 100%
 *  @Brief                  : Function used to Set the Duty cycle of the Generated PWM signal using channel 4 in PWM 1 Generator 2
 *  @Expected Output        : Duty cycle of the generated PWM Signal changed
 * */
void PWM_M1_Gen2_Channel4_SetDuty(u8 Duty)
{
    u32 CompareValue ;

    /*1- calculate the  compare value*/
    CompareValue = (( (100 - Duty) * LOAD_VALUE ) / 100);

    /*2- set the compare value of PWM 1 Generator 2 channel 4*/
    PWM1_2_CMPA_R = CompareValue ;
}


