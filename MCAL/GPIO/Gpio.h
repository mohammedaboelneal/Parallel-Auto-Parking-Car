/*
 *      @file       :   Gpio.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the GPIO driver
 *                      and all definitions and types for their implementation
 */

#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

/*****************************  Includes Sections ***************************/
#include "../../TM4C123GH6PM_Registers/tm4c123gh6pm.h"
#include "../../TM4C123GH6PM_Registers/GPIO_AlternativeFunctions.h"
#include "../../utils/Bit_math.h"
#include "../../utils/Std_types.h"
#include "Gpio_Types.h"
#include "Gpio_Private.h"

/*****************************  Defines Sections ***************************/
#define NUMBER_OF_PORTS             6

/*****************************  Definitions Sections ***************************/
/* A structure contain all info needed to initialize the DIO only once */
typedef struct pinConfig
{
    Gpio_ChannelType_t              channelId;
    Gpio_PinDirection_t             direction;
    Gpio_PinSignalType_t            SignalType;
    Gpio_Functionality_t            functionality;
    u8                              Pin_Function;
    Gpio_DriveStrength_t            Current;
    Gpio_InternalPinConnection_t    Connection;
}Gpio_PinConfig_t;

/*********************** Services Prototype ******************************/
/*  @Service name           : Gpio_ReadChannel
 *  @Parameters (in)        : PinConfig -> the GPIO pin configuration from the type " Gpio_PinConfig_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to initialize essential configurations for specified channel in GPIO port to be used
 *  @Expected Output        : pin configuration initialized and ready to be used
 * */
void Gpio_PinConfigInit( Gpio_PinConfig_t * PinConfig );

/*  @Service name           : Gpio_ReadChannel
 *  @Parameters (in)        : channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : from the type "Gpio_LevelType_t" which is the pin value (HIGH/LOW)
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to read the status on specified channel in GPIO port
 *  @Expected Output        : GPIO Pin Status (High/Low)
 * */
Gpio_LevelType_t Gpio_ReadChannel( Gpio_ChannelType_t channelId);

/*  @Service name           : Gpio_WriteChannel
 *  @Parameters (in)        : 1. channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. Level     -> the GPIO pin status from the type " Gpio_LevelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to write specified level of specified channel in GPIO port
 *  @Expected Output        : Changing the pin status by set or clear it.
 * */
void Gpio_WriteChannel( Gpio_ChannelType_t channelId ,  Gpio_LevelType_t Level);

/*  @Service name           : Gpio_FlipChannel
 *  @Parameters (in)        : channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to toggle specified gpio pin level
 *  @Expected Output        : Changing the pin status from High to Low or Low to High
 * */
 void Gpio_FlipChannel( Gpio_ChannelType_t channelId);


/*  @Service name           : Gpio_InitPinDirection
 *  @Parameters (in)        : 1. channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. Direction -> the GPIO pin direction from the type " Gpio_PinDirection_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Unlocking port done inside this function if the pin is input
 *  @Brief                  : Function used to set GPIO pin direction to Input or Output
 *  @Expected Output        : setting the pin direction to be used in its functionality
 * */
void Gpio_InitPinDirection( Gpio_ChannelType_t channelId ,  Gpio_PinDirection_t Direction);

/*  @Service name           : Gpio_AlternativeFunctionStatus
 *  @Parameters (in)        : 1. channelId      -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. functionality  -> the GPIO pin functionality from the type " Gpio_Functionality_t"
 *                            3. Pin_Function   -> the GPIO pin function from the type "u8" <See the alternative functions file >
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to set GPIO pin functionality to GPIO or other
 *  @Expected Output        : setting the pin functionality to be properly used
 * */
void Gpio_AlternativeFunctionStatus(  Gpio_ChannelType_t channelId ,  Gpio_Functionality_t functionality , u8 Pin_Function);

/*  @Service name           : Gpio_DriverStrengthSelection
 *  @Parameters (in)        : 1. channelId    -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. driveCurrent -> the GPIO pin driven current from the type " Gpio_DriveStrength_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to set GPIO pin driven current option
 *  @Expected Output        : setting the pin current strength
 * */
void Gpio_DriverStrengthSelection(  Gpio_ChannelType_t channelId ,  Gpio_DriveStrength_t driveCurrent);

/*  @Service name           : Gpio_SetInternalPinConnection
 *  @Parameters (in)        : 1. channelId  -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. connection -> the GPIO pin internal connection from the type "Gpio_InternalPinConnection_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to set GPIO pin internal connection options "Pull up/down"
 *  @Expected Output        : setting the internal pin connection
 * */
void Gpio_SetInternalPinConnection(  Gpio_ChannelType_t channelId ,  Gpio_InternalPinConnection_t connection);

/*  @Service name           : Gpio_OpenDrainSelection
 *  @Parameters (in)        : 1. channelId       -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. OperDrainStatus -> the GPIO pin internally connected to open drain or not from the type "boolean"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable/disable GPIO pin internal connection with open drain circuit
 *  @Expected Output        : setting the internal pin connection t open drain or not
 * */
void Gpio_OpenDrainSelection(  Gpio_ChannelType_t channelId ,  boolean OperDrainStatus);

/*  @Service name           : Gpio_SlewRateSelection
 *  @Parameters (in)        : 1. channelId       -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. SlewRateStatus  -> the GPIO pin use the slew rate or not from the type "boolean"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable/disable GPIO pin internal slew rate
 *  @Expected Output        : setting the internal pin slew rate or not
 * */
void Gpio_SlewRateSelection(  Gpio_ChannelType_t channelId ,  boolean SlewRateStatus);

/*  @Service name           : Gpio_SignalTypeEnable
 *  @Parameters (in)        : 1. channelId   -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. signalType  -> the GPIO pin signal type from the type "Gpio_PinSignalType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to select GPIO pin signal type "Analog/Digital"
 *  @Expected Output        : setting the internal pin slew rate or not
 * */
void Gpio_SignalTypeEnable(  Gpio_ChannelType_t channelId ,  Gpio_PinSignalType_t signalType);

/*  @Service name           : Gpio_UnlockPort
 *  @Parameters (in)        : PortId   -> the GPIO port from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to unlock port registers
 *  @Expected Output        : unlock port registers to be used
 * */
void Gpio_UnlockPort( Gpio_PortType_t PortId);

/*  @Service name           : Gpio_LockPort
 *  @Parameters (in)        : PortId   -> the GPIO port from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to lock port registers
 *  @Expected Output        : lock port registers and it can not be used
 * */
void Gpio_LockPort( Gpio_PortType_t PortId);

/*  @Service name           : Gpio_UnlockPin
 *  @Parameters (in)        : channelId   -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to unlock pin registers
 *  @Expected Output        : unlock port registers and it can not be used
 * */
void Gpio_UnlockPin( Gpio_ChannelType_t channelId );

/*  @Service name           : Gpio_UnlockPin
 *  @Parameters (in)        : channelId   -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to lock pin registers
 *  @Expected Output        : lock port registers and it can not be used
 * */
void Gpio_LockPin( Gpio_ChannelType_t channelId );

#endif /* MCAL_GPIO_GPIO_H_ */
