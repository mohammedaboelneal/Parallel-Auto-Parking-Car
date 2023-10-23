/*
 *      @file       :   Gpio_Types.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all types to be used in building the GPIO software driver
 */

#ifndef MCAL_GPIO_GPIO_TYPES_H_
#define MCAL_GPIO_GPIO_TYPES_H_

/*****************************  Includes Sections ***************************/
#include "../../utils/Std_types.h"

/*****************************  Defines Sections ***************************/

/*Define pin control status*/
#define    PIN_LOCKED               0
#define    PIN_UNLOCKED             1

/*****************************  Definitions Sections ***************************/
/* This type defines the Gpio pins level "STD_HIGH/STD_LOW" */
typedef s8 Gpio_LevelType_t;

/*
 * This type covers all ports available in the MCU
 *
 * This type based on the Tiva C "TM4C123GH6PM" MCU and can be changed based on the MCU
 * */
typedef enum Gpio_portType
{
    GPIO_PORTA ,
    GPIO_PORTB ,
    GPIO_PORTC ,
    GPIO_PORTD ,
    GPIO_PORTE ,
    GPIO_PORTF
}Gpio_PortType_t;

/*
 * type of the group of all Gpio channels available in MCU
 *
 * this type based on the Tiva C "TM4C123GH6PM" MCU and can be changed based on the MCU
 * channel_num / MCU_Gpio_PORT_SIZE = port_number
 * channel_num % MCU_Gpio_PORT_SIZE = pin_number
 */
typedef enum Gpio_ChannelType
{
    /*Port A pins "channels" */
    CH_PORTA_PIN0,
    CH_PORTA_PIN1,
    CH_PORTA_PIN2,
    CH_PORTA_PIN3,
    CH_PORTA_PIN4,
    CH_PORTA_PIN5,
    CH_PORTA_PIN6,
    CH_PORTA_PIN7,

    /*Port D pins "channels" */
    CH_PORTB_PIN0,
    CH_PORTB_PIN1,
    CH_PORTB_PIN2,
    CH_PORTB_PIN3,
    CH_PORTB_PIN4,
    CH_PORTB_PIN5,
    CH_PORTB_PIN6,
    CH_PORTB_PIN7,

    /*Port C pins "channels" */
    CH_PORTC_PIN0,
    CH_PORTC_PIN1,
    CH_PORTC_PIN2,
    CH_PORTC_PIN3,
    CH_PORTC_PIN4,
    CH_PORTC_PIN5,
    CH_PORTC_PIN6,
    CH_PORTC_PIN7,

    /*Port D pins "channels" */
    CH_PORTD_PIN0,
    CH_PORTD_PIN1,
    CH_PORTD_PIN2,
    CH_PORTD_PIN3,
    CH_PORTD_PIN4,
    CH_PORTD_PIN5,
    CH_PORTD_PIN6,
    CH_PORTD_PIN7,

    /*Port E pins "channels" */
    CH_PORTE_PIN0,
    CH_PORTE_PIN1,
    CH_PORTE_PIN2,
    CH_PORTE_PIN3,
    CH_PORTE_PIN4,
    CH_PORTE_PIN5,
    CH_PORTE_PIN6_RESERVED,
    CH_PORTE_PIN7_RESERVED,


    /*Port F pins "channels" */
    CH_PORTF_PIN0,
    CH_PORTF_PIN1,
    CH_PORTF_PIN2,
    CH_PORTF_PIN3,
    CH_PORTF_PIN4,
    CH_PORTF_PIN5_RESERVED,
    CH_PORTF_PIN6_RESERVED,
    CH_PORTF_PIN7_RESERVED,

}Gpio_ChannelType_t;

/* This type defines the pin use type "In/Out"*/
typedef enum Gpio_pinDirection
{
    GPIO_INPUT  ,
    GPIO_OUTPUT
}Gpio_PinDirection_t;

/* This type defines pin naming for each port's pin*/
typedef enum Gpio_pinNumber
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}Gpio_PinNumber_t;


/******************************************************/
/********************* ARM Settings *******************/
/******************************************************/

/*This Type defines all possible functionalities of each GPIO Pins*/
typedef enum Functionality{
    GPIO_FUNCTIONALITY,
    OTHER_FUNCTIONALITY
}Gpio_Functionality_t;

/*This Type defines all possible Driving Strength of GPIO pins*/
typedef enum DriveStrength{
    DEFAULT,
    GPIO_R2R,
    GPIO_R4R,
    GPIO_R8R
}Gpio_DriveStrength_t;

/*This Type defines all possible internal GPIO pin connections*/
typedef enum InternalPinConnection_t{
    OUTPUT,
    PULLED_UP,
    PULLED_DOWN,
    OPEN_DRAIN
}Gpio_InternalPinConnection_t;

/*This Type defines possible signals of GPIO pins*/
typedef enum PinSignalType{
    DIGITAL_SIGNAL,
    ANALOG_SIGNAL
}Gpio_PinSignalType_t;

#endif /* MCAL_GPIO_GPIO_TYPES_H_ */
