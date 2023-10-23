/*
 * PWM_Types.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Ahmed Saber
 */

#ifndef MCAL_PWM_PWM_TYPES_H_
#define MCAL_PWM_PWM_TYPES_H_

typedef enum PWM_Number
{
    PWM0,
    PWM1
}PWM_Number_t;

/*PWM Module 0*/
#define PWM0_GEN0_CHANNEL_0             /*PORTB_PIN6_M0PWM0*/

#define PWM0_GEN0_CHANNEL_1             /*PORTB_PIN7_M0PWM1*/

#define PWM0_GEN1_CHANNEL_2             /*PORTB_PIN4_M0PWM2*/

#define PWM0_GEN1_CHANNEL_3             /*PORTB_PIN5_M0PWM3*/

#define PWM0_GEN2_CHANNEL_4             /*PORTE_PIN4_M0PWM4*/

#define PWM0_GEN2_CHANNEL_5             /*PORTE_PIN5_M0PWM5*/

#define PWM0_GEN3_CHANNEL_6             /*PORTC_PIN4_M0PWM6*/

#define PWM0_GEN3_CHANNEL_7             /*PORTC_PIN5_M0PWM7*/


/*PWM Module 1*/
#define PWM1_GEN0_CHANNEL_0             /*PORTD_PIN0_M1PWM0*/

#define PWM1_GEN0_CHANNEL_1             /*PORTD_PIN1_M1PWM1*/

#define PWM1_GEN1_CHANNEL_2             /*PORTE_PIN4_M1PWM2*/

#define PWM1_GEN1_CHANNEL_3             /*PORTE_PIN4_M1PWM3*/

#define PWM1_GEN2_CHANNEL_4             CH_PORTF_PIN0               /*PORTF_PIN0_M1PWM4*/

#define PWM1_GEN2_CHANNEL_5             /*PORTF_PIN1_M1PWM5*/

#define PWM1_GEN3_CHANNEL_6             CH_PORTF_PIN2               /*PORTF_PIN2_M1PWM6*/

#define PWM1_GEN3_CHANNEL_7             /*PORTF_PIN3_M1PWM7*/

#endif /* MCAL_PWM_PWM_TYPES_H_ */
