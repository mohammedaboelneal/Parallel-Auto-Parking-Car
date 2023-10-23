/*
 *      @file       :   ultrasonic.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the Ultra-sonic "HCR04" driver
 *                      and all definitions and types for their implementation
 */

#ifndef NTI_ULTRASONIC_LIB_HAL_ULTRASONIC_H_
#define NTI_ULTRASONIC_LIB_HAL_ULTRASONIC_H_

/*****************************  Includes Sections ***************************/
#include "../../MCAL/GPIO/Gpio.h"
#include "../../MCAL/GP_TIMERS/GP_Timers.h"
#include "../../MCAL/SysTick/Delay/delay.h"
#include "../../SYS_CTRL/Sys_Ctrl.h"

/*********************** Defines Section ******************************/
#define GET_DISTANCE(time)              ( (time * 10625)/10000000 )

/*********************** Services Prototype ******************************/
/*  @Service name           : US_InitConfig
 *  @Parameters (in)        : 1- TriggerPin -> pointer to ultra-sonic Trigger pin configuration to be used from the type "Gpio_PinConfig_t"
                              2- EchoPin    -> pointer to ultra-sonic Echo pin configuration to be used from the type "Gpio_PinConfig_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize all pins of ultra-sonic to be used
 *  @Expected Output        : GPIO pin and Timer which are used initialized
 * */
void US_InitConfig(Gpio_PinConfig_t * TriggerPin , Gpio_PinConfig_t * EchoPin);


/*  @Service name           : US_GetDistance
 *  @Parameters (in)        : 1- TriggerPin -> ultra-sonic Trigger pin configuration to be used from the type "Gpio_PinConfig_t"
                              2- EchoPin    -> ultra-sonic Echo pin configuration to be used from the type "Gpio_PinConfig_t"
 *  @Parameters (out)       : None
 *  @Return value           : Distance between UltraSonic and Nearest Object from the type "u32"
 *  @Operation Constrains   : from the practical experiment, It needs around 200 ms delay after each reading
 *  @Brief                  : Function used to get the distance between US and Object
 *  @Expected Output        : distance between US and Object in cm with max range 45 cm
 * */
u32 US_GetDistance(Gpio_ChannelType_t TriggerPin , Gpio_ChannelType_t EchoPin );


#endif /* NTI_ULTRASONIC_LIB_HAL_ULTRASONIC_H_ */
