/*
 *      @file       :   Gpio.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the GPIO driver
 */

/************************** Includes Section **********************************/
#include "Gpio.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : Gpio_ReadChannel
 *  @Parameters (in)        : PinConfig -> the GPIO pin configuration from the type " Gpio_PinConfig_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Clock must be enabled to the Port before it used
 *  @Brief                  : Function used to initialize essential configurations for specified channel in GPIO Port to be used
 *  @Expected Output        : pin configuration initialized and ready to be used
 * */
 void Gpio_PinConfigInit( Gpio_PinConfig_t * PinConfig )
 {
     if(NULL != PinConfig)
     {
         /*1- Set Pin direction*/
         Gpio_InitPinDirection(PinConfig->channelId, PinConfig->direction);

         /*2- Select the internal pin connection*/
         Gpio_SetInternalPinConnection(PinConfig->channelId, PinConfig->Connection);

         /*3- Set Pin Signal type*/
         Gpio_SignalTypeEnable(PinConfig->channelId, PinConfig->SignalType);

         /*4- Set the pin functionality*/
         Gpio_AlternativeFunctionStatus(PinConfig->channelId, PinConfig->functionality , PinConfig->Pin_Function);

         /*5- Set the drive current of the pin*/
         Gpio_DriverStrengthSelection(PinConfig->channelId, PinConfig->Current);
     }
     else
     {
         /* error */
     }
 }

/*  @Service name           : Gpio_ReadChannel
 *  @Parameters (in)        : channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : from the type "Gpio_LevelType_t" which is the pin value (HIGH/LOW)
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to read the status on specified channel in GPIO Port
 *  @Expected Output        : GPIO Pin Status (High/Low)
 * */
Gpio_LevelType_t Gpio_ReadChannel( Gpio_ChannelType_t channelId)
{
    Gpio_LevelType_t retValue = -1 ;

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(Port)
    {
        case GPIO_PORTA :
            retValue = READ_BIT(GPIO_PORTA_DATA_R,pin);
            break;

        case GPIO_PORTB :
            retValue = READ_BIT(GPIO_PORTB_DATA_R,pin);
            break;

        case GPIO_PORTC :
            retValue = READ_BIT(GPIO_PORTC_DATA_R,pin);
            break;

        case GPIO_PORTD :
            retValue = READ_BIT(GPIO_PORTD_DATA_R,pin);
            break;

        case GPIO_PORTE :
            retValue = READ_BIT(GPIO_PORTE_DATA_R,pin);
            break;

        case GPIO_PORTF :
            retValue = READ_BIT(GPIO_PORTF_DATA_R,pin);
            break;

        default :
            /*error*/
            break;
    }

    return retValue;
}

/*  @Service name           : Gpio_WriteChannel
 *  @Parameters (in)        : 1. channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. Level     -> the GPIO pin status from the type " Gpio_LevelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to write specified level of specified channel in GPIO Port
 *  @Expected Output        : Changing the pin status by set or clear it.
 * */
void Gpio_WriteChannel( Gpio_ChannelType_t channelId ,  Gpio_LevelType_t Level)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(Port)
    {
        case GPIO_PORTA :
            if(STD_HIGH == Level)
            {
                SET_BIT(GPIO_PORTA_DATA_R,pin);
            }
            else if(STD_LOW == Level)
            {
                CLEAR_BIT(GPIO_PORTA_DATA_R,pin);
            }
            else
            {
                /*error*/
            }
            break;

        case GPIO_PORTB :
            if(STD_HIGH == Level)
            {
                SET_BIT(GPIO_PORTB_DATA_R,pin);
            }
            else if(STD_LOW == Level)
            {
                CLEAR_BIT(GPIO_PORTB_DATA_R,pin);
            }
            else
            {
                /*error*/
            }
            break;

        case GPIO_PORTC :
            if(STD_HIGH == Level)
            {
                SET_BIT(GPIO_PORTC_DATA_R,pin);
            }
            else if(STD_LOW == Level)
            {
                CLEAR_BIT(GPIO_PORTC_DATA_R,pin);
            }
            else
            {
                /*error*/
            }
            break;

        case GPIO_PORTD :
            if(STD_HIGH == Level)
            {
                SET_BIT(GPIO_PORTD_DATA_R,pin);
            }
            else if(STD_LOW == Level)
            {
                CLEAR_BIT(GPIO_PORTD_DATA_R,pin);
            }
            else
            {
                /*error*/
            }
            break;

        case GPIO_PORTE :
            if(STD_HIGH == Level)
            {
                SET_BIT(GPIO_PORTE_DATA_R,pin);
            }
            else if(STD_LOW == Level)
            {
                CLEAR_BIT(GPIO_PORTE_DATA_R,pin);
            }
            else
            {
                /*error*/
            }
            break;

        case GPIO_PORTF :
            if(STD_HIGH == Level)
            {
                SET_BIT(GPIO_PORTF_DATA_R,pin);
            }
            else if(STD_LOW == Level)
            {
                CLEAR_BIT(GPIO_PORTF_DATA_R,pin);
            }
            else
            {
                /*error*/
            }
            break;

        default :
            /*error*/
            break;
    }
}

/*  @Service name           : Gpio_FlipChannel
 *  @Parameters (in)        : channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to toggle specified gpio pin level
 *  @Expected Output        : Changing the pin status from High to Low or Low to High
 * */
 void Gpio_FlipChannel( Gpio_ChannelType_t channelId)
 {

     /*get Port from the channel id*/
     Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
     /*get pin from the channel id*/
     Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

     switch(Port)
     {
         case GPIO_PORTA :
             TOGGLE_BIT(GPIO_PORTA_DATA_R,pin);
             break;

         case GPIO_PORTB :
             TOGGLE_BIT(GPIO_PORTB_DATA_R,pin);
             break;

         case GPIO_PORTC :
             TOGGLE_BIT(GPIO_PORTC_DATA_R,pin);
             break;

         case GPIO_PORTD :
             TOGGLE_BIT(GPIO_PORTD_DATA_R,pin);
             break;

         case GPIO_PORTE :
             TOGGLE_BIT(GPIO_PORTE_DATA_R,pin);
             break;

         case GPIO_PORTF :
             TOGGLE_BIT(GPIO_PORTF_DATA_R,pin);
             break;

         default :
             /*error*/
             break;
     }

 }


/*  @Service name           : Gpio_InitPinDirection
 *  @Parameters (in)        : 1. channelId -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. Direction -> the GPIO pin direction from the type " Gpio_PinDirection_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Unlocking Port done inside this function if the pin is input
 *  @Brief                  : Function used to set GPIO pin direction to Input or Output
 *  @Expected Output        : setting the pin direction to be used in its functionality
 * */
void Gpio_InitPinDirection( Gpio_ChannelType_t channelId ,  Gpio_PinDirection_t Direction)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(Port)
    {
        case GPIO_PORTA :
            if(GPIO_INPUT == Direction)
            {
                CLEAR_BIT(GPIO_PORTA_DIR_R,pin);
                Gpio_UnlockPort(Port);
                Gpio_UnlockPin(channelId);
            }
            else if (GPIO_OUTPUT == Direction)
            {
                SET_BIT(GPIO_PORTA_DIR_R,pin);
            }
            else
            {
             /*error handling*/
            }
            break;

        case GPIO_PORTB :
            if(GPIO_INPUT == Direction)
            {
                CLEAR_BIT(GPIO_PORTB_DIR_R,pin);
                Gpio_UnlockPort(Port);
                Gpio_UnlockPin(channelId);
            }
            else if (GPIO_OUTPUT == Direction)
            {
                SET_BIT(GPIO_PORTB_DIR_R,pin);
            }
            else
            {
                /*error handling*/
            }
            break;

        case GPIO_PORTC :
            if(GPIO_INPUT == Direction)
            {
                CLEAR_BIT(GPIO_PORTC_DIR_R,pin);
                Gpio_UnlockPort(Port);
                Gpio_UnlockPin(channelId);
            }
            else if (GPIO_OUTPUT == Direction)
            {
                SET_BIT(GPIO_PORTC_DIR_R,pin);
            }
            else
            {
                /*error handling*/
            }
            break;

        case GPIO_PORTD :
            if(GPIO_INPUT == Direction)
            {
                CLEAR_BIT(GPIO_PORTD_DIR_R,pin);
                Gpio_UnlockPort(Port);
                Gpio_UnlockPin(channelId);
            }
            else if (GPIO_OUTPUT == Direction)
            {
                SET_BIT(GPIO_PORTD_DIR_R,pin);
            }
            else
            {
                /*error handling*/
            }
            break;

        case GPIO_PORTE :
            if(GPIO_INPUT == Direction)
            {
                CLEAR_BIT(GPIO_PORTE_DIR_R,pin);
                Gpio_UnlockPort(Port);
                Gpio_UnlockPin(channelId);
            }
            else if (GPIO_OUTPUT == Direction)
            {
                SET_BIT(GPIO_PORTE_DIR_R,pin);
            }
            else
            {
                /*error handling*/
            }
            break;

        case GPIO_PORTF :
            if(GPIO_INPUT == Direction)
            {
                CLEAR_BIT(GPIO_PORTF_DIR_R,pin);
                Gpio_UnlockPort(Port);
                Gpio_UnlockPin(channelId);
            }
            else if (GPIO_OUTPUT == Direction)
            {
                SET_BIT(GPIO_PORTF_DIR_R,pin);
            }
            else
            {
                /*error handling*/
            }
            break;

        default :
            /*error*/
            break;
    }
}

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
void Gpio_AlternativeFunctionStatus(  Gpio_ChannelType_t channelId ,  Gpio_Functionality_t functionality , u8 Pin_Function)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(functionality)
    {
    case  GPIO_FUNCTIONALITY :
        switch(Port)
        {
            case GPIO_PORTA :
                CLEAR_BIT(GPIO_PORTA_AFSEL_R,pin);
                break;

            case GPIO_PORTB :
                CLEAR_BIT(GPIO_PORTB_AFSEL_R,pin);
                break;

            case GPIO_PORTC :
                CLEAR_BIT(GPIO_PORTC_AFSEL_R,pin);
                break;

            case GPIO_PORTD :
                CLEAR_BIT(GPIO_PORTD_AFSEL_R,pin);
                break;

            case GPIO_PORTE :
                CLEAR_BIT(GPIO_PORTE_AFSEL_R,pin);
                break;

            case GPIO_PORTF :
                CLEAR_BIT(GPIO_PORTF_AFSEL_R,pin);
                break;

            default :
                /*error handling*/
                break;
        }
        break;

    case OTHER_FUNCTIONALITY :
        switch(Port)
        {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_AFSEL_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_AFSEL_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_AFSEL_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_AFSEL_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_AFSEL_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_AFSEL_R,pin);
                break;

            default :
                /*error handling*/
                break;
        }
        break;

    default :
        /*error handling*/
        break;
    }


    switch(Port)
    {
        case GPIO_PORTA :
            GPIO_PORTA_PCTL_R &= ~( 0xF << (pin*4)  );
            GPIO_PORTA_PCTL_R |= (Pin_Function << (pin*4) );
            break;

        case GPIO_PORTB :
            GPIO_PORTB_PCTL_R &= ~( 0xF << (pin*4) );
            GPIO_PORTB_PCTL_R |= (Pin_Function << (pin*4) );
            break;

        case GPIO_PORTC :
            GPIO_PORTC_PCTL_R &= ~( 0xF << (pin*4) );
            GPIO_PORTC_PCTL_R |= (Pin_Function << (pin*4) );
            break;

        case GPIO_PORTD :
            GPIO_PORTD_PCTL_R &= ~( 0xF << ((pin*4) - 1) );
            GPIO_PORTD_PCTL_R |= (Pin_Function << (pin*4) );
            break;

        case GPIO_PORTE :
            GPIO_PORTE_PCTL_R &= ~( 0xF << (pin*4) );
            GPIO_PORTE_PCTL_R |= (Pin_Function << (pin*4) );
            break;

        case GPIO_PORTF :
            GPIO_PORTF_PCTL_R &= ~( 0xF << (pin*4) );
            GPIO_PORTF_PCTL_R |= (Pin_Function << (pin*4) );
            break;

        default :
            /*error handling*/
            break;
    }

}

/*  @Service name           : Gpio_DriverStrengthSelection
 *  @Parameters (in)        : 1. channelId    -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. driveCurrent -> the GPIO pin driven current from the type " Gpio_DriveStrength_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to set GPIO pin driven current option
 *  @Expected Output        : setting the pin current strength
 * */
void Gpio_DriverStrengthSelection(  Gpio_ChannelType_t channelId ,  Gpio_DriveStrength_t driveCurrent)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(driveCurrent)
    {
        case  GPIO_R2R :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_DR2R_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_DR2R_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_DR2R_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_DR2R_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_DR2R_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_DR2R_R,pin);
                break;
            }
            break;

        case GPIO_R4R :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_DR4R_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_DR4R_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_DR4R_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_DR4R_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_DR4R_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_DR4R_R,pin);
                break;
            }
            break;

        case GPIO_R8R :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_DR8R_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_DR8R_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_DR8R_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_DR8R_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_DR8R_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_DR8R_R,pin);
                break;
            }
            break;

        default :
            /*error handling*/
            break;
    }
}

/*  @Service name           : Gpio_SetInternalPinConnection
 *  @Parameters (in)        : 1. channelId  -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. connection -> the GPIO pin internal connection from the type "Gpio_InternalPinConnection_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to set GPIO pin internal connection options "Pull up/down"
 *  @Expected Output        : setting the internal pin connection
 * */
void Gpio_SetInternalPinConnection(  Gpio_ChannelType_t channelId ,  Gpio_InternalPinConnection_t connection)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(connection)
    {
        case OUTPUT :
            switch(Port)
            {
            case GPIO_PORTA :
                CLEAR_BIT(GPIO_PORTA_PUR_R,pin);
                CLEAR_BIT(GPIO_PORTA_PDR_R,pin);
                break;

            case GPIO_PORTB :
                CLEAR_BIT(GPIO_PORTB_PUR_R,pin);
                CLEAR_BIT(GPIO_PORTB_PDR_R,pin);
                break;

            case GPIO_PORTC :
                CLEAR_BIT(GPIO_PORTC_PUR_R,pin);
                CLEAR_BIT(GPIO_PORTC_PDR_R,pin);
                break;

            case GPIO_PORTD :
                CLEAR_BIT(GPIO_PORTD_PUR_R,pin);
                CLEAR_BIT(GPIO_PORTD_PDR_R,pin);
                break;

            case GPIO_PORTE :
                CLEAR_BIT(GPIO_PORTE_PUR_R,pin);
                CLEAR_BIT(GPIO_PORTE_PDR_R,pin);
                break;

            case GPIO_PORTF :
                CLEAR_BIT(GPIO_PORTF_PUR_R,pin);
                CLEAR_BIT(GPIO_PORTF_PDR_R,pin);
                break;
            }
            break;

        case PULLED_DOWN :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_PDR_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_PDR_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_PDR_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_PDR_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_PDR_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_PDR_R,pin);
                break;
            }
            break;

        case PULLED_UP :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_PUR_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_PUR_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_PUR_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_PUR_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_PUR_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_PUR_R,pin);
                break;
            }
            break;

        case OPEN_DRAIN :
            Gpio_OpenDrainSelection(channelId , STD_ENABLE);
            break;

        default:
            /*error handling*/
            break;
    }
}

/*  @Service name           : Gpio_OpenDrainSelection
 *  @Parameters (in)        : 1. channelId       -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. OperDrainStatus -> the GPIO pin internally connected to open drain or not from the type "boolean"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable/disable GPIO pin internal connection with open drain circuit
 *  @Expected Output        : setting the internal pin connection t open drain or not
 * */
void Gpio_OpenDrainSelection(  Gpio_ChannelType_t channelId ,  boolean OperDrainStatus)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(OperDrainStatus)
    {
        case STD_ENABLE :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_ODR_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_ODR_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_ODR_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_ODR_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_ODR_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_ODR_R,pin);
                break;
            }
            break;

        case STD_DISABLE :
            switch(Port)
            {
            case GPIO_PORTA :
                CLEAR_BIT(GPIO_PORTA_ODR_R,pin);
                break;

            case GPIO_PORTB :
                CLEAR_BIT(GPIO_PORTB_ODR_R,pin);
                break;

            case GPIO_PORTC :
                CLEAR_BIT(GPIO_PORTC_ODR_R,pin);
                break;

            case GPIO_PORTD :
                CLEAR_BIT(GPIO_PORTD_ODR_R,pin);
                break;

            case GPIO_PORTE :
                CLEAR_BIT(GPIO_PORTE_ODR_R,pin);
                break;

            case GPIO_PORTF :
                CLEAR_BIT(GPIO_PORTF_ODR_R,pin);
                break;
            }
            break;

        default:
            /*error handling*/
            break;

    }
}

/*  @Service name           : Gpio_SlewRateSelection
 *  @Parameters (in)        : 1. channelId       -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. SlewRateStatus  -> the GPIO pin use the slew rate or not from the type "boolean"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable/disable GPIO pin internal slew rate
 *  @Expected Output        : setting the internal pin slew rate or not
 * */
void Gpio_SlewRateSelection(  Gpio_ChannelType_t channelId ,  boolean SlewRateStatus)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(SlewRateStatus)
    {
        case STD_ENABLE :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_SLR_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_SLR_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_SLR_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_SLR_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_SLR_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_SLR_R,pin);
                break;
            }
            break;

        case STD_DISABLE :
            switch(Port)
            {
            case GPIO_PORTA :
                CLEAR_BIT(GPIO_PORTA_SLR_R,pin);
                break;

            case GPIO_PORTB :
                CLEAR_BIT(GPIO_PORTB_SLR_R,pin);
                break;

            case GPIO_PORTC :
                CLEAR_BIT(GPIO_PORTC_SLR_R,pin);
                break;

            case GPIO_PORTD :
                CLEAR_BIT(GPIO_PORTD_SLR_R,pin);
                break;

            case GPIO_PORTE :
                CLEAR_BIT(GPIO_PORTE_SLR_R,pin);
                break;

            case GPIO_PORTF :
                CLEAR_BIT(GPIO_PORTF_SLR_R,pin);
                break;
            }
            break;

        default:
            /*error handling*/
            break;
    }
}

/*  @Service name           : Gpio_SignalTypeEnable
 *  @Parameters (in)        : 1. channelId   -> the GPIO pin from the type " Gpio_ChannelType_t"
 *                            2. signalType  -> the GPIO pin signal type from the type "Gpio_PinSignalType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to select GPIO pin signal type "Analog/Digital"
 *  @Expected Output        : setting the internal pin slew rate or not
 * */
void Gpio_SignalTypeEnable(  Gpio_ChannelType_t channelId ,  Gpio_PinSignalType_t signalType)
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(signalType)
    {
        case DIGITAL_SIGNAL :
            switch(Port)
            {
            case GPIO_PORTA :
                SET_BIT(GPIO_PORTA_DEN_R,pin);
                break;

            case GPIO_PORTB :
                SET_BIT(GPIO_PORTB_DEN_R,pin);
                break;

            case GPIO_PORTC :
                SET_BIT(GPIO_PORTC_DEN_R,pin);
                break;

            case GPIO_PORTD :
                SET_BIT(GPIO_PORTD_DEN_R,pin);
                break;

            case GPIO_PORTE :
                SET_BIT(GPIO_PORTE_DEN_R,pin);
                break;

            case GPIO_PORTF :
                SET_BIT(GPIO_PORTF_DEN_R,pin);
                break;
            }
            break;

        case ANALOG_SIGNAL :
            switch(Port)
            {
            case GPIO_PORTA :
                CLEAR_BIT(GPIO_PORTA_DEN_R,pin);
                break;

            case GPIO_PORTB :
                CLEAR_BIT(GPIO_PORTB_DEN_R,pin);
                break;

            case GPIO_PORTC :
                CLEAR_BIT(GPIO_PORTC_DEN_R,pin);
                break;

            case GPIO_PORTD :
                CLEAR_BIT(GPIO_PORTD_DEN_R,pin);
                break;

            case GPIO_PORTE :
                CLEAR_BIT(GPIO_PORTE_DEN_R,pin);
                break;

            case GPIO_PORTF :
                CLEAR_BIT(GPIO_PORTF_DEN_R,pin);
                break;
            }
            break;

        default:
            /*error handling*/
            break;
    }
}

/*  @Service name           : Gpio_UnlockPort
 *  @Parameters (in)        : PortId   -> the GPIO Port from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to unlock Port registers
 *  @Expected Output        : unlock Port registers to be used
 * */
void Gpio_UnlockPort( Gpio_PortType_t PortId)
{
     switch(PortId)
     {
         case GPIO_PORTA :
             GPIO_PORTA_LOCK_R = 0x4C4F434B;
             break;

         case GPIO_PORTB :
             GPIO_PORTB_LOCK_R = 0x4C4F434B;
             break;

         case GPIO_PORTC :
             GPIO_PORTC_LOCK_R = 0x4C4F434B;
             break;

         case GPIO_PORTD :
             GPIO_PORTD_LOCK_R = 0x4C4F434B;
             break;

         case GPIO_PORTE :
             GPIO_PORTE_LOCK_R = 0x4C4F434B;
             break;

         case GPIO_PORTF :
             GPIO_PORTF_LOCK_R = 0x4C4F434B;
             break;
     }
}

/*  @Service name           : Gpio_LockPort
 *  @Parameters (in)        : PortId   -> the GPIO Port from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to lock Port registers
 *  @Expected Output        : lock Port registers and it can not be used
 * */
void Gpio_LockPort( Gpio_PortType_t PortId)
{
     switch(PortId)
     {
         case GPIO_PORTA :
             GPIO_PORTA_LOCK_R = 0x00000000;
             break;

         case GPIO_PORTB :
             GPIO_PORTB_LOCK_R = 0x00000000;
             break;

         case GPIO_PORTC :
             GPIO_PORTC_LOCK_R = 0x00000000;
             break;

         case GPIO_PORTD :
             GPIO_PORTD_LOCK_R = 0x00000000;
             break;

         case GPIO_PORTE :
             GPIO_PORTE_LOCK_R = 0x00000000;
             break;

         case GPIO_PORTF :
             GPIO_PORTF_LOCK_R = 0x00000000;
             break;
     }

}

/*  @Service name           : Gpio_UnlockPin
 *  @Parameters (in)        : channelId   -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to unlock pin registers
 *  @Expected Output        : unlock Port registers and it can not be used
 * */
void Gpio_UnlockPin( Gpio_ChannelType_t channelId )
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(Port)
    {
        case GPIO_PORTA :
            SET_BIT(GPIO_PORTA_CR_R,pin);
            break;

        case GPIO_PORTB :
            SET_BIT(GPIO_PORTB_CR_R,pin);
            break;

        case GPIO_PORTC :
            SET_BIT(GPIO_PORTC_CR_R,pin);
            break;

        case GPIO_PORTD :
            SET_BIT(GPIO_PORTD_CR_R,pin);
            break;

        case GPIO_PORTE :
            SET_BIT(GPIO_PORTE_CR_R,pin);
            break;

        case GPIO_PORTF :
            SET_BIT(GPIO_PORTF_CR_R,pin);
            break;

        default :
            /*error*/
            break;
    }
}

/*  @Service name           : Gpio_UnlockPin
 *  @Parameters (in)        : channelId   -> the GPIO pin from the type " Gpio_ChannelType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : Usually used with input pins
 *  @Brief                  : Function used to lock pin registers
 *  @Expected Output        : lock Port registers and it can not be used
 * */
void Gpio_LockPin( Gpio_ChannelType_t channelId )
{

    /*get Port from the channel id*/
    Gpio_PortType_t Port = (Gpio_PortType_t) GET_PORT(channelId);
    /*get pin from the channel id*/
    Gpio_PinNumber_t pin = (Gpio_PinNumber_t) GET_PIN(channelId);

    switch(Port)
    {
        case GPIO_PORTA :
            CLEAR_BIT(GPIO_PORTA_CR_R,pin);
            break;

        case GPIO_PORTB :
            CLEAR_BIT(GPIO_PORTB_CR_R,pin);
            break;

        case GPIO_PORTC :
            CLEAR_BIT(GPIO_PORTC_CR_R,pin);
            break;

        case GPIO_PORTD :
            CLEAR_BIT(GPIO_PORTD_CR_R,pin);
            break;

        case GPIO_PORTE :
            CLEAR_BIT(GPIO_PORTE_CR_R,pin);
            break;

        case GPIO_PORTF :
            CLEAR_BIT(GPIO_PORTF_CR_R,pin);
            break;

        default :
            /*error*/
            break;
    }
}



