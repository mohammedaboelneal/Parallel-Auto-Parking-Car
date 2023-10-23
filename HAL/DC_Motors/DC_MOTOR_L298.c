/*
 * DC_MOTOR_L298.c
 *
 *  Created on  :   Sep 17, 2023
 *      Author  :   AVELABS Group 1
 *      brief   :   This File provides implementation of the main services of DC_MOTOR in the HAL Layer
 *
 *
 *      Motors in The Project
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
#include "DC_MOTOR_L298.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : DCM_Init
 *  @Parameters (in)        : "Motor" a motor configuration from the type -> "DC_Motor_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Function can not change any of the configuration
 *  @Brief                  : Function used to Initialize DC motor pins
 *  @Expected Output        : A DC Motor initialized if it called.
 * */
void DCM_Init( DC_Motor_t *  Motor)
{
    /*1- Get the port of pins*/
    u8 PWM_Port = GET_PORT(Motor->PWM_Pin.channelId);
    u8 Reverse_Port = GET_PORT(Motor->Normal_Pin.channelId);
    u8 Forward_Port = GET_PORT(Motor->Reverse_Pin.channelId);

    /*2- Initialize The clock of the GPIO Pins*/
    SysCtrl_EnableClk_GPIO( (Gpio_PortType_t) PWM_Port);
    SysCtrl_EnableClk_GPIO( (Gpio_PortType_t) Reverse_Port);
    SysCtrl_EnableClk_GPIO( (Gpio_PortType_t) Forward_Port);

    /*3- Initialize PWM Module 1 Clock */
    SysCtrl_EnableClk_PWM(PWM1);

    /*4- Initialize the GPIO Configuration*/
    Gpio_PinConfigInit(&(Motor->PWM_Pin));
    Gpio_PinConfigInit(&(Motor->Normal_Pin));
    Gpio_PinConfigInit(&(Motor->Reverse_Pin));

    /*5- Set The RCC Settings*/
    RCC_EnableClkDivisor();
    RCC_PWM_CLK_Div64();


    /*6- Initialize the PWM module*/
    if(PWM1_GEN2_CHANNEL_4 == Motor->PWM_Pin.channelId )
    {
        PWM_M1_Gen2_Channel4_Init();
    }
    else if(PWM1_GEN3_CHANNEL_6 == Motor->PWM_Pin.channelId)
    {
        PWM_M1_Gen3_Channel6_Init();
    }
    else
    {
        /*error*/
    }


}

/*  @Service name           : DCM_SpeedControl
 *  @Parameters (in)        : 1- "Motor" a motor configuration from the type -> "DC_Motor_t"
 *                            2- "MotorSpeed" a percentage of motor speed from the type -> "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : MotorSpeed range [0,100]
 *  @Brief                  : Function used to control the speed of DC motor
 *  @Expected Output        : Speed of DC Motor changed by changing the PWM Signal.
 *                            if MotorSpeed in valid range function must rotate or stop.
 *                            if MotorSpeed < 0     --> Module Stop or It will not rotate.
 *                            if MotorSpeed > 100   --> Module rotate with the max speed
 * */
void DCM_SpeedControl(u8 MotorSpeed ,  DC_Motor_t *  Motor)
{
    if(PWM1_GEN2_CHANNEL_4 == Motor->PWM_Pin.channelId )
    {
        PWM_M1_Gen2_Channel4_SetDuty( MotorSpeed );
    }
    else if(PWM1_GEN3_CHANNEL_6 == Motor->PWM_Pin.channelId)
    {
        PWM_M1_Gen3_Channel6_SetDuty( MotorSpeed );
    }
    else
    {
        /*error*/
    }
}

/*  @Service name           : DCM_RotatNormalDirection
 *  @Parameters (in)        : 1- "Motor" a motor configuration from the type -> "DC_Motor_t"
 *                            2- "MotorSpeed" a percentage of motor speed from the type -> "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Function can not change any of the configuration
 *  @Brief                  : Function used to Rotate the motor in the normal direction
 *  @Expected Output        : A DC Motor rotation in normal direction.
 *                            if MotorSpeed in valid range function must rotate or stop.
 *                            if MotorSpeed < 0     --> Module Stop or It will not rotate.
 *                            if MotorSpeed > 100   --> Module rotate with the max speed
 * */
void DCM_RotatNormalDirection(u8 MotorSpeed ,  DC_Motor_t *  Motor)
{
    /*1- Control The Direction*/
    Gpio_WriteChannel(Motor->Normal_Pin.channelId , STD_HIGH);
    Gpio_WriteChannel(Motor->Reverse_Pin.channelId, STD_LOW );

    /*2- Control The Speed*/
    DCM_SpeedControl(MotorSpeed , Motor);

}

/*  @Service name           : DCM_RotatReverseDirection
 *  @Parameters (in)        : 1- "Motor" a motor configuration from the type -> "DC_Motor_t"
 *                            2- "MotorSpeed" a percentage of motor speed from the type -> "u8"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Function can not change any of the configuration
 *  @Brief                  : Function used to Rotate the motor in the reverse direction
 *  @Expected Output        : A DC Motor rotation in reverse direction.
 *                            if MotorSpeed in valid range function must rotate or stop.
 *                            if MotorSpeed < 0     --> Module Stop or It will not rotate.
 *                            if MotorSpeed > 100   --> Module rotate with the max speed
 * */
void DCM_RotatReverseDirection(u8 MotorSpeed ,  DC_Motor_t *  Motor)
{
    /*1- Control The Direction*/
    Gpio_WriteChannel(Motor->Normal_Pin.channelId  , STD_LOW );
    Gpio_WriteChannel(Motor->Reverse_Pin.channelId , STD_HIGH);

    /*2- Control The Speed*/
    DCM_SpeedControl(MotorSpeed , Motor);

}

/*  @Service name           : DCM_Stop
 *  @Parameters (in)        : "Motor" a motor configuration from the type -> "DC_Motor_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the DC motor rotation
 *  @Expected Output        : A DC Motor rotation stops by setting the speed to 0
 * */
void DCM_Stop(DC_Motor_t *  Motor)
{
    /*set both pins to lo to stop the motor*/
    Gpio_WriteChannel(Motor->Normal_Pin.channelId  , STD_LOW );
    Gpio_WriteChannel(Motor->Reverse_Pin.channelId , STD_LOW);
    /*Control The Speed*/
    DCM_SpeedControl(0 , Motor);

}


