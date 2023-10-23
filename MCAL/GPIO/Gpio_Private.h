/*
 *      @file       :   Gpio_Private.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all basic functions can not be changed by the user of the GPIO Driver
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

/*****************************  Defines Sections ***************************/

/*define the port size as being used to determine the pin number and port number*/
#define MCU_GPIO_PORT_SIZE           8

/* macro function to get the pin and port values*/
#define GET_PORT(channel)   ( channel / MCU_GPIO_PORT_SIZE )
#define GET_PIN(channel)    ( channel % MCU_GPIO_PORT_SIZE )

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
