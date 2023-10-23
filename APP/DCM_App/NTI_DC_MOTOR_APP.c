/*
 * NTI_DC_MOTOR_APP.c
 *
 *  Created on  :   Sep 17, 2023
 *      Author  :   AVELABS Group 1
 *      brief   :   This File provides the implementation of main services of DC_MOTOR in the Application
 *
 *
 *                                      Motors in The Project
 *      _________________________________________________________________________________________
 *     |                                                                                         |
 *     |                                                                                         |
 *     |                                                                                         |
 *     |  __________________________                                        ____________________ |
 *     | | DCM_1 "Forward/Backward" |                                      | DCM_2 "Right/Left" ||
 *     | |                          |                                      |                    ||
 *     |  __________________________                                        ____________________||
 *     |                                                                                         |
 *     |_________________________________________________________________________________________|
 */

/************************** Includes Section **********************************/
#include "NTI_DC_MOTOR_APP.h"

/*********************** Global Variables Sections ****************************/
/*
 *   DCM1_PWM         >>    CH_PORTF_PIN2
 *   DCM1_Normal_Pin  >>    CH_PORTE_PIN1
 *   DCM1_Reverse_Pin >>    CH_PORTE_PIN2
 *
 * */
DC_Motor_t DC_Motor_1 = {
                         {(Gpio_ChannelType_t) DCM_1_PWM_PIN , GPIO_OUTPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY   , PORTF_PIN2_M1PWM6 , DEFAULT , OUTPUT} ,    /*PWM_Pin of DC_M1*/
                         {(Gpio_ChannelType_t) DCM_1_FORWARD_PIN , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTE_PIN2_GPIO , DEFAULT , OUTPUT },    /*Normal_Pin of DC_M1*/
                         {(Gpio_ChannelType_t) DCM_1_BACKWARD_PIN , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTE_PIN1_GPIO , DEFAULT , OUTPUT }     /*Reverse_Pin of DC_M1*/
                        };

/*
 *   DCM2_PWM         >>    CH_PORTF_PIN2
 *   DCM2_Normal_Pin  >>    CH_PORTE_PIN1
 *   DCM2_Reverse_Pin >>    CH_PORTE_PIN2
 *
 * */
DC_Motor_t DC_Motor_2 = {
                         {(Gpio_ChannelType_t) DCM_2_PWM_PIN , GPIO_OUTPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY   , PORTF_PIN0_M1PWM4 , DEFAULT , OUTPUT},    /*PWM_Pin of DC_M2*/
                         {(Gpio_ChannelType_t) DCM_2_RIGHT_PIN , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTE_PIN4_GPIO , DEFAULT , OUTPUT },    /*Normal_Pin of DC_M1*/
                         {(Gpio_ChannelType_t) DCM_2_LEFT_PIN , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTE_PIN5_GPIO , DEFAULT , OUTPUT }     /*Reverse_Pin of DC_M1*/
                        };


/*********************** Services Implementation ******************************/
/*  @Service name           : NTI_DCM_InitAll
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize all DC motors of the module and generate the PWM Signals with 0 Duty.
 *  @Expected Output        : All DC Motors initialized if it called.
 * */
void NTI_DCM_InitAll(void)
{
    DCM_Init(&DC_Motor_1);
    DCM_Init(&DC_Motor_2);
}


/*  @Service name           : NTI_DCM_MoveForward
 *  @Parameters (in)        : "MotorSpeed" is percentage of the motor speed -> from the type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : MotorSpeed range [0,100]
 *  @Brief                  : Function used to Move the module in forward direction with specified speed
 *  @Expected Output        : if MotorSpeed in valid range function must move in forward direction.
 *                            if MotorSpeed < 0     --> Module Stop or It will not move.
 *                            if MotorSpeed > 100   --> Module move with the total speed in forward direction.
 * */
void NTI_DCM_MoveForward(u8 MotorSpeed)
{
    DCM_RotatNormalDirection(MotorSpeed , &DC_Motor_1);

    DCM_Stop(&DC_Motor_2);
}

/*  @Service name           : NTI_DCM_MoveBackward
 *  @Parameters (in)        : "MotorSpeed" is percentage of the motor speed -> from the type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : MotorSpeed range [0,100]
 *  @Brief                  : Function used to Move the module in backward direction with specified speed
 *  @Expected Output        : if MotorSpeed in valid range function must move in backward direction.
 *                            if MotorSpeed < 0     --> Module Stop or It will not move.
 *                            if MotorSpeed > 100   --> Module move with the total speed in backward direction.
 * */
void NTI_DCM_MoveBackward(u8 MotorSpeed)
{
    DCM_RotatReverseDirection(MotorSpeed , &DC_Motor_1);

    DCM_Stop(&DC_Motor_2);
}

/*  @Service name           : NTI_DCM_MoveRight
 *  @Parameters (in)        : "MotorSpeed" is percentage of the motor speed -> from the type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : MotorSpeed range [0,100]
 *  @Brief                  : Function used to Move the module in right direction with specified speed
 *  @Expected Output        : if MotorSpeed in valid range function must move in right direction.
 *                            if MotorSpeed < 0     --> Module Stop or It will not move.
 *                            if MotorSpeed > 100   --> Module move with the total speed in right direction.
 * */
void NTI_DCM_MoveRight(u8 MotorSpeed)
{
//    DCM_RotatNormalDirection(MotorSpeed , &DC_Motor_1);

    DCM_RotatNormalDirection( MotorSpeed , &DC_Motor_2);
}

/*  @Service name           : NTI_DCM_MoveLeft
 *  @Parameters (in)        : "MotorSpeed" is percentage of the motor speed -> from the type "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : MotorSpeed range [0,100]
 *  @Brief                  : Function used to Move the module in left direction with specified speed
 *  @Expected Output        : if MotorSpeed in valid range function must move in left direction.
 *                            if MotorSpeed < 0     --> Module Stop or It will not move.
 *                            if MotorSpeed > 100   --> Module move with the total speed in left direction.
 * */
void NTI_DCM_MoveLeft(u8 MotorSpeed)
{
//    DCM_RotatNormalDirection(MotorSpeed , &DC_Motor_1);

    DCM_RotatReverseDirection( MotorSpeed , &DC_Motor_2);
}

/*  @Service name           : NTI_DCM_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the module movement
 *  @Expected Output        : Module Stop if it called.
 * */
void NTI_DCM_Stop(void)
{
    DCM_Stop(&DC_Motor_1);
    DCM_Stop(&DC_Motor_2);
}

/*  @Service name           : NTI_DC_M1_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the module 1 movement
 *  @Expected Output        : Module 1 Stop if it called.
 * */
void NTI_DC_M1_Stop(void)
{
    DCM_Stop(&DC_Motor_1);
}

/*  @Service name           : NTI_DC_M2_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the module 2 movement
 *  @Expected Output        : Module 2 Stop if it called.
 * */
void NTI_DC_M2_Stop(void)
{
    DCM_Stop(&DC_Motor_2);
}

