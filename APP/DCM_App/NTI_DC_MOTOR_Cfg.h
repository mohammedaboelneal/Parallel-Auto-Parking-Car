/*
 * NTI_DC_MOTOR_Cfg.h
 *
 *  Created on  :   Sep 17, 2023
 *      Author  :   AVELABS Group 1
 *      Brief   :   This File provides all possible DC Motors connection pins to MCU to be Configured
 */

#ifndef NTI_DC_MOTOR_LIB_CFG_NTI_DC_MOTOR_CFG_H_
#define NTI_DC_MOTOR_LIB_CFG_NTI_DC_MOTOR_CFG_H_


/*A define for the number of motors*/
#define DCM_NUMBER_OF_MOTORS                    2

/*A define for the motor used in Forward/Backward Movement */
#define DCM_1_VERTICAL                          1

/*A define for the motor used in Right/Left Movement */
#define DCM_2_HORIZENTAL                        2

/*A define for PWM pin of DC motor 1*/
#define DCM_1_PWM_PIN                           PWM1_GEN3_CHANNEL_6         /*PORTF_PIN2_M1PWM6*/

/*A define for PWM pin of DC motor 1*/
#define DCM_1_BACKWARD_PIN                      CH_PORTE_PIN1

/*A define for PWM pin of DC motor 1*/
#define DCM_1_FORWARD_PIN                       CH_PORTE_PIN2

/*A define for PWM pin of DC motor 2*/
#define DCM_2_PWM_PIN                           PWM1_GEN2_CHANNEL_4         /*PORTF_PIN0_M1PWM4*/

/*A define for PWM pin of DC motor 2*/
#define DCM_2_RIGHT_PIN                         CH_PORTE_PIN4

/*A define for PWM pin of DC motor 2*/
#define DCM_2_LEFT_PIN                          CH_PORTE_PIN5


#endif /* NTI_DC_MOTOR_LIB_CFG_NTI_DC_MOTOR_CFG_H_ */
