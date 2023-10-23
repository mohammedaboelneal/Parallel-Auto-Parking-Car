/*
 * DC_MOTOR_L298_Types.h
 *
 *  Created on  :   Sep 17, 2023
 *      Author  :   AVELABS Group 1
 *      brief   :   This File provides Types of DC_MOTOR in the HAL Layer
 */

#ifndef NTI_DC_MOTOR_LIB_HAL_DC_MOTOR_L298_TYPES_H_
#define NTI_DC_MOTOR_LIB_HAL_DC_MOTOR_L298_TYPES_H_

/************************** Includes Section **********************************/
#include "../../MCAL/GPIO/Gpio.h"

/*This struct all necessary pins for DC Motor in 1 type*/
typedef struct DCM
{
    Gpio_PinConfig_t PWM_Pin      ;
    Gpio_PinConfig_t Normal_Pin   ;       /*Forward or Right*/
    Gpio_PinConfig_t Reverse_Pin  ;       /*Backward or Left*/
}DC_Motor_t;

#endif /* NTI_DC_MOTOR_LIB_HAL_DC_MOTOR_L298_TYPES_H_ */
