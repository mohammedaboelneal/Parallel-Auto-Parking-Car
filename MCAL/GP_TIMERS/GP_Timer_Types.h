/*
 *      @file       :   GP_Timer_Types.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all types to be used in building the GPT software driver
 */

#ifndef MCAL_GP_TIMERS_GP_TIMER_TYPES_H_
#define MCAL_GP_TIMERS_GP_TIMER_TYPES_H_

/* This Type define All Timers in the MCU */
typedef enum Timer_Number
{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
}Timer_Number_t;

/*This define the channel numbers of GPT Input capture Input Edge Time modes*/
/*Timer 0 channel A*/
#define T0CCP0_CHANNEL                      14      /*PORTB_PIN6*/
/*Timer 1 channel A*/
#define T1CCP0_CHANNEL                      12      /*PORTB_PIN4*/
/*Timer 2 channel A*/
#define T2CCP0_CHANNEL                      8       /*PORTB_PIN0*/
/*Timer 3 channel A*/
#define T3CCP0_CHANNEL                      10      /*PORTB_PIN2*/

/*Timer 0 channel B*/
#define T0CCP1_CHANNEL                      15      /*PORTB_PIN7*/
/*Timer 1 channel B*/
#define T1CCP1_CHANNEL                      13      /*PORTB_PIN5*/
/*Timer 2 channel B*/
#define T2CCP1_CHANNEL                      9       /*PORTB_PIN1*/
/*Timer 3 channel B*/
#define T3CCP1_CHANNEL                      11      /*PORTB_PIN3*/

/*We should avoid these pin as they reserved*/
/*Timer 4 channel A*/
#define T4CCP0_CHANNEL                      16      /*PORTC_PIN0*/
/*Timer 5 channel A*/
#define T5CCP0_CHANNEL                      18      /*PORTC_PIN2*/

#endif /* MCAL_GP_TIMERS_GP_TIMER_TYPES_H_ */
