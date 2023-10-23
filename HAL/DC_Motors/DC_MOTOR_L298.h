/*
 * DC_MOTOR_L298.h
 *
 *  Created on  :   Sep 17, 2023
 *      Author  :   AVELABS Group 1
 *      brief   :   This File provides the main services of DC_MOTOR in the HAL Layer
 */

#ifndef NTI_DC_MOTOR_LIB_HAL_DC_MOTOR_L298_H_
#define NTI_DC_MOTOR_LIB_HAL_DC_MOTOR_L298_H_

/************************** Includes Section **********************************/
#include "DC_MOTOR_L298_Types.h"
#include "../../MCAL/GPIO/Gpio.h"
#include "../../MCAL/PWM/PWM.h"
#include "../../MCAL/RCC/RCC.h"
#include "../../MCAL/SysTick/Delay/delay.h"
#include "../../SYS_CTRL/Sys_Ctrl.h"

/*********************** Services Prototypes ******************************/

/*  @Service name           : DCM_Init
 *  @Parameters (in)        : "Motor" a motor configuration from the type -> "DC_Motor_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Function can not change any of the configuration
 *  @Brief                  : Function used to Initialize DC motor pins
 *  @Expected Output        : A DC Motor initialized if it called.
 * */
void DCM_Init( DC_Motor_t *  Motor);

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
void DCM_SpeedControl(u8 MotorSpeed ,  DC_Motor_t *  Motor);

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
void DCM_RotatNormalDirection(u8 MotorSpeed ,  DC_Motor_t *  Motor);

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
void DCM_RotatReverseDirection(u8 MotorSpeed ,  DC_Motor_t *  Motor);

/*  @Service name           : DCM_Stop
 *  @Parameters (in)        : "Motor" a motor configuration from the type -> "DC_Motor_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the DC motor rotation
 *  @Expected Output        : A DC Motor rotation stops by setting the speed to 0
 * */
void DCM_Stop(DC_Motor_t *  Motor);

#endif /* NTI_DC_MOTOR_LIB_HAL_DC_MOTOR_L298_H_ */
