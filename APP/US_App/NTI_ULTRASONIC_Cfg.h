/*
 *      @file       :   NTI_ULTRASONIC_Cfg.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all possible DC Motors connection pins to MCU to be Configured
 */

#ifndef NTI_ULTRASONIC_LIB_CFG_NTI_ULTRASONIC_CFG_H_
#define NTI_ULTRASONIC_LIB_CFG_NTI_ULTRASONIC_CFG_H_

/*This defines shows how the Echo and Trigger Pins are connected to TIVA C MCU*/
/*The Ultra-Sonic 1 "Main Space Detector" */
#define US1_TRIGGER_CHANNEL                 CH_PORTA_PIN4               /*Trigger on GPIO_PIN_A4*/
#define US1_TRIGGER_PIN_FUNCTION            PORTA_PIN4_GPIO
#define US1_ECHO_CHANNEL                    T0CCP0_CHANNEL              /*Echo on Timer0_Channel_A*/
#define US1_ECHO_PIN_FUNCTION               PORTB_PIN6_T0CCP0

/*The Ultra-Sonic 2 "Secondary Space Detector" */
#define US2_TRIGGER_CHANNEL                 CH_PORTA_PIN3               /*Trigger on GPIO_PIN_A3*/
#define US2_TRIGGER_PIN_FUNCTION            PORTA_PIN3_GPIO
#define US2_ECHO_CHANNEL                    T1CCP0_CHANNEL              /*Echo on Timer1_Channel_A*/
#define US2_ECHO_PIN_FUNCTION               PORTB_PIN4_T1CCP0

/*This defines shows how the Echo and Trigger Pins are connected to TIVA C MCU*/
/*The Ultra-Sonic 3 "Front Detector" */
#define US3_TRIGGER_CHANNEL                 CH_PORTA_PIN2               /*Trigger on GPIO_PIN_A2*/
#define US3_TRIGGER_PIN_FUNCTION            PORTA_PIN2_GPIO
#define US3_ECHO_CHANNEL                    T2CCP0_CHANNEL              /*Echo on Timer2_Channel_A*/
#define US3_ECHO_PIN_FUNCTION               PORTB_PIN0_T2CCP0

/*The Ultra-Sonic 4 "Back Detector" */
#define US4_TRIGGER_CHANNEL                 CH_PORTA_PIN5               /*Trigger on GPIO_PIN_A1*/
#define US4_TRIGGER_PIN_FUNCTION            PORTA_PIN5_GPIO
#define US4_ECHO_CHANNEL                    T3CCP0_CHANNEL              /*Echo on Timer3_Channel_A*/
#define US4_ECHO_PIN_FUNCTION               PORTB_PIN2_T3CCP0

#endif /* NTI_ULTRASONIC_LIB_CFG_NTI_ULTRASONIC_CFG_H_ */
