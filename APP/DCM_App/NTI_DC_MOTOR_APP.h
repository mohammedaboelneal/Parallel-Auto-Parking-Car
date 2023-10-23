/*
 * NTI_DC_MOTOR_APP.h
 *
 *  Created on  :   Sep 17, 2023
 *      Author  :   AVELABS Group 1
 *      brief   :   This File provides the main services of DC_MOTOR in the Application
 */

#ifndef NTI_DC_MOTOR_LIB_APP_NTI_DC_MOTOR_APP_H_
#define NTI_DC_MOTOR_LIB_APP_NTI_DC_MOTOR_APP_H_

/************************** Includes Section **********************************/
#include "../../HAL/DC_Motors/DC_MOTOR_L298.h"
#include "NTI_DC_MOTOR_Cfg.h"

/*********************** Services Prototypes ******************************/
/*  @Service name           : NTI_DCM_InitAll
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize all DC motors of the module
 *  @Expected Output        : All DC Motors initialized if it called.
 * */
void NTI_DCM_InitAll        (void);

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
void NTI_DCM_MoveForward    (u8 MotorSpeed);

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
void NTI_DCM_MoveBackward   (u8 MotorSpeed);

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
void NTI_DCM_MoveRight      (u8 MotorSpeed);

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
void NTI_DCM_MoveLeft       (u8 MotorSpeed);

/*  @Service name           : NTI_DCM_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the module movement
 *  @Expected Output        : Module Stop if it called.
 * */
void NTI_DCM_Stop           (void);

/*  @Service name           : NTI_DC_M1_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the module 1 movement
 *  @Expected Output        : Module 1 Stop if it called.
 * */
void NTI_DC_M1_Stop(void);

/*  @Service name           : NTI_DC_M2_Stop
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to stop the module 2 movement
 *  @Expected Output        : Module 2 Stop if it called.
 * */
void NTI_DC_M2_Stop(void);

#endif /* NTI_DC_MOTOR_LIB_APP_NTI_DC_MOTOR_APP_H_ */
