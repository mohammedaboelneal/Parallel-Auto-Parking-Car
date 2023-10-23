/*
 *      @file       :   US_App.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used In The Main Application to use the ultra-sonic module
 */

/************************** Includes Section **********************************/
#include "US_App.h"

/*********************** Global Variables Sections ****************************/
/*
 * US1->Trigger   >> PORTA_PIN4
 * US1->Echo      >> PORTB_PIN6
 * */
Gpio_PinConfig_t US1_TriggerPin = {(Gpio_ChannelType_t) US1_TRIGGER_CHANNEL , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY   , US1_TRIGGER_PIN_FUNCTION  , DEFAULT , OUTPUT };
Gpio_PinConfig_t US1_EchoPin    = {(Gpio_ChannelType_t) US1_ECHO_CHANNEL    , GPIO_INPUT  , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY  , US1_ECHO_PIN_FUNCTION     , DEFAULT , OUTPUT };

/*
 * US2->Trigger   >> PORTA_PIN3
 * US2->Echo      >> PORTB_PIN4
 * */
Gpio_PinConfig_t US2_TriggerPin = {(Gpio_ChannelType_t) US2_TRIGGER_CHANNEL , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY   , US2_TRIGGER_PIN_FUNCTION  , DEFAULT , OUTPUT };
Gpio_PinConfig_t US2_EchoPin    = {(Gpio_ChannelType_t) US2_ECHO_CHANNEL    , GPIO_INPUT  , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY  , US2_ECHO_PIN_FUNCTION     , DEFAULT , OUTPUT };

/*
 * US3->Trigger   >> PORTA_PIN2
 * US3->Echo      >> PORTB_PIN0
 * */
Gpio_PinConfig_t US3_TriggerPin = {(Gpio_ChannelType_t) US3_TRIGGER_CHANNEL , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY   , US3_TRIGGER_PIN_FUNCTION  , DEFAULT , OUTPUT };
Gpio_PinConfig_t US3_EchoPin    = {(Gpio_ChannelType_t) US3_ECHO_CHANNEL    , GPIO_INPUT  , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY  , US3_ECHO_PIN_FUNCTION     , DEFAULT , OUTPUT };

/*
 * US4->Trigger   >> PORTA_PIN1
 * US4->Echo      >> PORTB_PIN2
 * */
Gpio_PinConfig_t US4_TriggerPin = {(Gpio_ChannelType_t) US4_TRIGGER_CHANNEL , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY   , US4_TRIGGER_PIN_FUNCTION  , DEFAULT , OUTPUT };
Gpio_PinConfig_t US4_EchoPin    = {(Gpio_ChannelType_t) US4_ECHO_CHANNEL    , GPIO_INPUT  , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY  , US4_ECHO_PIN_FUNCTION     , DEFAULT , OUTPUT };

/*********************** Services Implementation ******************************/
/*  @Service name           : US_InitAllModules
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize all Ultra-sonic modules in the Project
 *  @Expected Output        : All Modules are ready to be used
 * */
void US_InitAllModules(void)
{
    US_InitConfig(&US1_TriggerPin , &US1_EchoPin);
    US_InitConfig(&US2_TriggerPin , &US2_EchoPin);
    US_InitConfig(&US3_TriggerPin , &US3_EchoPin);
    US_InitConfig(&US4_TriggerPin , &US4_EchoPin);
}

/*  @Service name           : US1_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 1
 *  @Expected Output        : distance of module 1
 * */
u32 US1_GetDistance(void)
{
    u32 distance;

    distance = US_GetDistance(US1_TriggerPin.channelId , US1_EchoPin.channelId);

    return distance;
}

/*  @Service name           : US2_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 2
 *  @Expected Output        : distance of module 2
 * */
u32 US2_GetDistance(void)
{

    u32 distance;

    distance = US_GetDistance(US2_TriggerPin.channelId , US2_EchoPin.channelId);

    return distance;
}

/*  @Service name           : US3_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 3
 *  @Expected Output        : distance of module 3
 * */
u32 US3_GetDistance(void)
{

    u32 distance;

    distance = US_GetDistance(US3_TriggerPin.channelId , US3_EchoPin.channelId);

    return distance;
}

/*  @Service name           : US4_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 4
 *  @Expected Output        : distance of module 4
 * */
u32 US4_GetDistance(void)
{

    u32 distance;

    distance = US_GetDistance(US4_TriggerPin.channelId , US4_EchoPin.channelId);

    return distance;
}
