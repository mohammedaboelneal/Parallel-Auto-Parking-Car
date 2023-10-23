/*
 *      @file       :   GPIO_AlternativeFunctions.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all alternative functions of GPIO pins of TM4C123GH6PM mcu
 */

#ifndef MCAL_GPIO_GPIO_ALTERNATIVEFUNCTIONS_H_
#define MCAL_GPIO_GPIO_ALTERNATIVEFUNCTIONS_H_

/*Pins of Port A */
#define PORTA_PIN0_GPIO                     0
#define PORTA_PIN0_U0RX                     1
#define PORTA_PIN0_CAN1RX                   8

#define PORTA_PIN1_GPIO                     0
#define PORTA_PIN1_T0RX                     1
#define PORTA_PIN1_CAN1TX                   8

#define PORTA_PIN2_GPIO                     0
#define PORTA_PIN2_SSI0CLK                  2

#define PORTA_PIN3_GPIO                     0
#define PORTA_PIN3_SSI0FSS                  2

#define PORTA_PIN4_GPIO                     0
#define PORTA_PIN4_SSI0RX                   2

#define PORTA_PIN5_GPIO                     0
#define PORTA_PIN5_SSI0TX                   2

#define PORTA_PIN6_GPIO                     0
#define PORTA_PIN6_I2C1SCL                  3
#define PORTA_PIN6_M1PWM2                   5

#define PORTA_PIN7_GPIO                     0
#define PORTA_PIN7_I2C1SDA                  3
#define PORTA_PIN7_M1PWM3                   5

/*****************************************************/
/*Pins of Port B*/
#define PORTB_PIN0_GPIO                     0
#define PORTB_PIN0_U1RX                     1
#define PORTB_PIN0_T2CCP0                   7

#define PORTB_PIN1_GPIO                     0
#define PORTB_PIN1_U1TX                     1
#define PORTB_PIN1_T2CCP1                   7

#define PORTB_PIN2_GPIO                     0
#define PORTB_PIN2_I2C0SCL                  3
#define PORTB_PIN2_T3CCP0                   7

#define PORTB_PIN3_GPIO                     0
#define PORTB_PIN3_I2C0SCL                  3
#define PORTB_PIN3_T3CCP1                   7

#define PORTB_PIN4_GPIO                     0
#define PORTB_PIN4_SSI2Clk                  2
#define PORTB_PIN4_M0PWM2                   4
#define PORTB_PIN4_T1CCP0                   7
#define PORTB_PIN4_CAN0RX                   8

#define PORTB_PIN5_GPIO                     0
#define PORTB_PIN5_SSI2FSS                  2
#define PORTB_PIN5_M0PWM3                   4
#define PORTB_PIN5_T1CCP1                   7
#define PORTB_PIN5_CAN0TX                   8

#define PORTB_PIN6_GPIO                     0
#define PORTB_PIN6_SSI2RX                   2
#define PORTB_PIN6_M0PWM0                   4
#define PORTB_PIN6_T0CCP0                   7

#define PORTB_PIN7_GPIO                     0
#define PORTB_PIN7_SSI2TX                   2
#define PORTB_PIN7_M0PWM1                   4
#define PORTB_PIN7_T0CCP1                   7

/*****************************************************/
/*Pins of Port C*/
#define PORTC_PIN0_GPIO                     0
#define PORTC_PIN0_TCK_SWCLK                1
#define PORTC_PIN0_T4CCP0                   7

#define PORTC_PIN1_GPIO                     0
#define PORTC_PIN1_TMS_SWDIO                1
#define PORTC_PIN1_T4CCP1                   7

#define PORTC_PIN2_GPIO                     0
#define PORTC_PIN2_TDI                      1
#define PORTC_PIN2_T5CCP0                   7

#define PORTC_PIN3_GPIO                     0
#define PORTC_PIN3_TDO_SWO                  1
#define PORTC_PIN3_T5CCP1                   7

#define PORTC_PIN4_GPIO                     0
#define PORTC_PIN4_U4RX                     1
#define PORTC_PIN4_U1RX                     2
#define PORTC_PIN4_M0PWM6                   4
#define PORTC_PIN4_IDX1                     6
#define PORTC_PIN4_WT0CCP0                  7
#define PORTC_PIN4_U1RTS                    8

#define PORTC_PIN5_GPIO                     0
#define PORTC_PIN5_U4TX                     1
#define PORTC_PIN5_U1TX                     2
#define PORTC_PIN5_M0PWM7                   4
#define PORTC_PIN5_PHA1                     6
#define PORTC_PIN5_WT0CCP1                  7
#define PORTC_PIN5_U1CTS                    8

#define PORTC_PIN6_GPIO                     0
#define PORTC_PIN6_U3RX                     1
#define PORTC_PIN6_PHB1                     6
#define PORTC_PIN6_WT1CCP0                  7
#define PORTC_PIN6_USB0EPEN                 8

#define PORTC_PIN7_GPIO                     0
#define PORTC_PIN7_U3RX                     1
#define PORTC_PIN7_WT1CCP1                  7
#define PORTC_PIN7_USB0PFLT                 8

/*****************************************************/
/*Pins of Port D*/
#define PORTD_PIN0_GPIO                     0
#define PORTD_PIN0_SSI3CLK                  1
#define PORTD_PIN0_SSI1CLK                  2
#define PORTD_PIN0_I2C3SCL                  3
#define PORTD_PIN0_M0PWM6                   4
#define PORTD_PIN0_M1PWM0                   5
#define PORTD_PIN0_WT2CCP0                  7

#define PORTD_PIN1_GPIO                     0
#define PORTD_PIN1_SSI3FSS                  1
#define PORTD_PIN1_SSI1FSS                  2
#define PORTD_PIN1_I2C3SDA                  3
#define PORTD_PIN1_M0PWM7                   4
#define PORTD_PIN1_M1PWM1                   5
#define PORTD_PIN1_WT2CCP1                  7

#define PORTD_PIN2_GPIO                     0
#define PORTD_PIN2_SSI3RX                   1
#define PORTD_PIN2_SSI1RX                   2
#define PORTD_PIN2_M0FAULT0                 4
#define PORTD_PIN2_WT3CCP0                  7
#define PORTD_PIN2_USB0EPEN                 8

#define PORTD_PIN3_GPIO                     0
#define PORTD_PIN3_SSI3TX                   1
#define PORTD_PIN3_SSI1TX                   2
#define PORTD_PIN3_IDX0                     6
#define PORTD_PIN3_WT3CCP1                  7
#define PORTD_PIN3_USB0PFLT                 8

#define PORTD_PIN4_GPIO                     0
#define PORTD_PIN4_U6RX                     1
#define PORTD_PIN4_WT4CCP0                  7

#define PORTD_PIN5_GPIO                     0
#define PORTD_PIN5_U6TX                     1
#define PORTD_PIN5_WT4CCP1                  7

#define PORTD_PIN6_GPIO                     0
#define PORTD_PIN6_U6RX                     1
#define PORTD_PIN6_M0FAULT0                 4
#define PORTD_PIN6_PHA0                     6
#define PORTD_PIN6_WT5CCP0                  7

#define PORTD_PIN7_GPIO                     0
#define PORTD_PIN7_U6TX                     1
#define PORTD_PIN7_PHB0                     6
#define PORTD_PIN7_WT5CCP1                  7
#define PORTD_PIN7_NMI                      8

/*****************************************************/
/*Pins of Port E*/
#define PORTE_PIN0_GPIO                     0
#define PORTE_PIN0_U7RX                     1

#define PORTE_PIN1_GPIO                     0
#define PORTE_PIN1_U7TX                     1

#define PORTE_PIN2_GPIO                     0

#define PORTE_PIN3_GPIO                     0

#define PORTE_PIN4_GPIO                     0
#define PORTE_PIN4_U5RX                     1
#define PORTE_PIN4_I2C2SCL                  3
#define PORTE_PIN4_M0PWM4                   4
#define PORTE_PIN4_M1PWM2                   5
#define PORTE_PIN4_CAN0RX                   8

#define PORTE_PIN5_GPIO                     0
#define PORTE_PIN5_U5TX                     1
#define PORTE_PIN5_I2C2SDA                  3
#define PORTE_PIN5_M0PWM5                   4
#define PORTE_PIN5_M1PWM3                   5
#define PORTE_PIN5_CAN0TX                   8

/*****************************************************/
/*Pins of Port E*/
#define PORTF_PIN0_GPIO                     0
#define PORTF_PIN0_U1RTS                    1
#define PORTF_PIN0_SSI1RX                   2
#define PORTF_PIN0_CAN0RX                   3
#define PORTF_PIN0_M1PWM4                   5
#define PORTF_PIN0_PHA0                     6
#define PORTF_PIN0_T0CCP0                   7
#define PORTF_PIN0_NMI                      8
#define PORTF_PIN0_C0O                      9

#define PORTF_PIN1_GPIO                     0
#define PORTF_PIN1_U1CTS                    1
#define PORTF_PIN1_SSI1TX                   2
#define PORTF_PIN1_M1PWM5                   5
#define PORTF_PIN1_PHB0                     6
#define PORTF_PIN1_T0CCP1                   7
#define PORTF_PIN1_C1O                      9
#define PORTF_PIN1_TRD1                     14

#define PORTF_PIN2_GPIO                     0
#define PORTF_PIN2_SSI1CLK                  2
#define PORTF_PIN2_M0FAULT0                 4
#define PORTF_PIN2_M1PWM6                   5
#define PORTF_PIN2_T1CCP0                   7
#define PORTF_PIN2_TRD0                     14

#define PORTF_PIN3_GPIO                     0
#define PORTF_PIN3_SSI1FSS                  2
#define PORTF_PIN3_CAN0TX                   3
#define PORTF_PIN3_M1PWM7                   5
#define PORTF_PIN3_T1CCP1                   7
#define PORTF_PIN3_TRCLK                    14

#define PORTF_PIN4_GPIO                     0
#define PORTF_PIN4_M1FAULT0                 5
#define PORTF_PIN4_IDX0                     6
#define PORTF_PIN4_T2CCP0                   7
#define PORTF_PIN4_USB0EPEN                 8


#endif /* MCAL_GPIO_GPIO_ALTERNATIVEFUNCTIONS_H_ */
