/*
 *      @file       :   ultrasonic.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the GPIO driver
 */



/************************** Includes Section **********************************/
#include "ultrasonic.h"

/*********************** Static helpers Prototype ******************************/
/*  @Service name           : US_Trigger
 *  @Parameters (in)        : Ultrasonic_Cfg -> ultra-sonic configuration pins to be used from the type "UltraSonic_Cfg"
 *  @Parameters (out)       : None
 *  @Return value           : Distance between UltraSonic and Nearest Object from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to get the distance between US and Object
 *  @Expected Output        : distance between US and Object in cm with max range 40 cm
 * */
static void US_Trigger(Gpio_ChannelType_t channelId);

/*********************** Services Implementation ******************************/
/*  @Service name           : US_InitConfig
 *  @Parameters (in)        : 1- TriggerPin -> pointer to ultra-sonic Trigger pin configuration to be used from the type "Gpio_PinConfig_t"
                              2- EchoPin    -> pointer to ultra-sonic Echo pin configuration to be used from the type "Gpio_PinConfig_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize all pins (peripherals) of ultra-sonic to be used
 *  @Expected Output        : GPIO pin and Timer which are used initialized
 * */
void US_InitConfig(Gpio_PinConfig_t * TriggerPin , Gpio_PinConfig_t * EchoPin)
{
    u8 TriggerPort = GET_PORT(TriggerPin->channelId);
    u8 EchoPort = GET_PORT(EchoPin->channelId);

    if( (NULL != TriggerPin) && (NULL != EchoPin) )
    {
        /*Enable Clk Source for GPIO and Timers*/

        /*1- GPIO*/
        SysCtrl_EnableClk_GPIO( (Gpio_PortType_t) TriggerPort);
        SysCtrl_EnableClk_GPIO( (Gpio_PortType_t) EchoPort);

        /*2- Timer*/
        switch(EchoPin->channelId)
        {
            case T0CCP0_CHANNEL :
            case T0CCP1_CHANNEL :
                SysCtrl_EnableClk_TIMER(TIMER0);
                break;

            case T1CCP0_CHANNEL :
            case T1CCP1_CHANNEL :
                SysCtrl_EnableClk_TIMER(TIMER1);
                break;

            case T2CCP0_CHANNEL :
            case T2CCP1_CHANNEL :
                SysCtrl_EnableClk_TIMER(TIMER2);
                break;

            case T3CCP0_CHANNEL :
            case T3CCP1_CHANNEL :
                SysCtrl_EnableClk_TIMER(TIMER3);
                break;

            case T4CCP0_CHANNEL :
                SysCtrl_EnableClk_TIMER(TIMER4);
                break;

            case T5CCP0_CHANNEL :
                SysCtrl_EnableClk_TIMER(TIMER5);
                break;

            default :
                /*error*/
                break;
        }

        /*Configure the GPIO pins*/
        Gpio_PinConfigInit(TriggerPin);
        Gpio_PinConfigInit(EchoPin);

        /*Initialize the capture unit*/
        switch(EchoPin->channelId)
        {
            case T0CCP0_CHANNEL :
                GPT_Timer0A_InputCaptureInit();
                break;

            case T1CCP0_CHANNEL :
                GPT_Timer1A_InputCaptureInit();
                break;

            case T2CCP0_CHANNEL :
                GPT_Timer2A_InputCaptureInit();
                break;

            case T3CCP0_CHANNEL :
                GPT_Timer3A_InputCaptureInit();
                break;

            case T4CCP0_CHANNEL :
                GPT_Timer4A_InputCaptureInit();
                break;

            case T5CCP0_CHANNEL :
                GPT_Timer5A_InputCaptureInit();
                break;

            default :
                /*error*/
                break;
        }

    }
    else
    {
        /*error*/
    }
}


/*  @Service name           : US_GetDistance
 *  @Parameters (in)        : 1- TriggerPin -> ultra-sonic Trigger pin configuration to be used from the type "Gpio_PinConfig_t"
                              2- EchoPin    -> ultra-sonic Echo pin configuration to be used from the type "Gpio_PinConfig_t"
 *  @Parameters (out)       : None
 *  @Return value           : Distance between UltraSonic and Nearest Object from the type "u32"
 *  @Operation Constrains   : from the practical experiment, It needs around 200 ms delay after each reading
 *  @Brief                  : Function used to get the distance between US and Object
 *  @Expected Output        : distance between US and Object in cm with max range 45 cm
 * */
u32 US_GetDistance(Gpio_ChannelType_t TriggerPin , Gpio_ChannelType_t EchoPin )
{
    u32 TimeDiff = 0 , Distance = 0;

    /* Give 10us trigger pulse */
    US_Trigger( TriggerPin );

    /* Get Time Difference*/
    switch(EchoPin)
    {
        case T0CCP0_CHANNEL :
            TimeDiff = GPT_Timer0A_GetPulseWidth();
            break;

        case T1CCP0_CHANNEL :
            TimeDiff = GPT_Timer1A_GetPulseWidth();
            break;

        case T2CCP0_CHANNEL :
            TimeDiff = GPT_Timer2A_GetPulseWidth();
            break;

        case T3CCP0_CHANNEL :
            TimeDiff = GPT_Timer3A_GetPulseWidth();
            break;

        case T4CCP0_CHANNEL :
            TimeDiff = GPT_Timer4A_GetPulseWidth();
            break;

        case T5CCP0_CHANNEL :
            TimeDiff = GPT_Timer5A_GetPulseWidth();
            break;

        default :
            /*error*/
            break;
    }

    /*Calculate the distance*/
    Distance = GET_DISTANCE(TimeDiff);

    return Distance;
}


/*  @Service name           : US_Trigger
 *  @Parameters (in)        : Ultrasonic_Cfg -> ultra-sonic configuration pins to be used from the type "UltraSonic_Cfg"
 *  @Parameters (out)       : None
 *  @Return value           : Distance between UltraSonic and Nearest Object from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to get the distance between US and Object
 *  @Expected Output        : distance between US and Object in cm with max range 40 cm
 * */
static void US_Trigger(Gpio_ChannelType_t channelId)
{
    Gpio_WriteChannel(channelId, STD_LOW);
    Delay_US(10);
    Gpio_WriteChannel(channelId, STD_HIGH);
    Delay_US(10);
    Gpio_WriteChannel(channelId, STD_LOW);
    Delay_US(10);
}
