/*
 *      @file       :   Sys_Ctrl.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used from the System Control driver
 *                      and all definitions and types for their implementation
 */

#ifndef SYS_CTRL_SYS_CTRL_H_
#define SYS_CTRL_SYS_CTRL_H_

/*****************************  Includes Sections ***************************/
#include "../TM4C123GH6PM_Registers/tm4c123gh6pm.h"
#include "../utils/Bit_math.h"
#include "../utils/Std_types.h"
#include "../MCAL/GPIO/Gpio_Types.h"
#include "../MCAL/GP_TIMERS/GP_Timer_Types.h"
#include "../MCAL/PWM/PWM_Types.h"
#include "../MCAL/UART/UART_Types.h"

/*****************************  Defines Sections ***************************/
/*SYSCTL_RCGCGPIO_R bits that control clk of GPIO ports*/
#define SYS_CTRL_GPIO_PORTA_BIT                   0
#define SYS_CTRL_GPIO_PORTB_BIT                   1
#define SYS_CTRL_GPIO_PORTC_BIT                   2
#define SYS_CTRL_GPIO_PORTD_BIT                   3
#define SYS_CTRL_GPIO_PORTE_BIT                   4
#define SYS_CTRL_GPIO_PORTF_BIT                   5

/*SYSCTL_RCGCTIMER_R bits that control clk of Timer Modules*/
#define SYS_CTRL_TIMER0_BIT                       0
#define SYS_CTRL_TIMER1_BIT                       1
#define SYS_CTRL_TIMER2_BIT                       2
#define SYS_CTRL_TIMER3_BIT                       3
#define SYS_CTRL_TIMER4_BIT                       4
#define SYS_CTRL_TIMER5_BIT                       5

/*SYSCTL_RCGCUART_R bits that control clk of UART Modules*/
#define SYS_CTRL_UART0_BIT                        0
#define SYS_CTRL_UART1_BIT                        1
#define SYS_CTRL_UART2_BIT                        2
#define SYS_CTRL_UART3_BIT                        3
#define SYS_CTRL_UART4_BIT                        4
#define SYS_CTRL_UART5_BIT                        5
#define SYS_CTRL_UART6_BIT                        6
#define SYS_CTRL_UART7_BIT                        7

/*SYSCTL_RCGCPWM_R bits that control clk of PWM Modules*/
#define SYS_CTRL_PWM0_BIT                         0
#define SYS_CTRL_PWM1_BIT                         1

/*********************** Services Prototype ******************************/
/*  @Service name           : SysCtrl_EnableClk_GPIO
 *  @Parameters (in)        : Port -> the GPIO port number from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified GPIO port
 *  @Expected Output        : Clock enabled for the specified GPIO port
 * */
void SysCtrl_EnableClk_GPIO(Gpio_PortType_t Port);

/*  @Service name           : SysCtrl_DisableClk_GPIO
 *  @Parameters (in)        : Port -> the GPIO port number from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified GPIO port
 *  @Expected Output        : Clock disabled for the specified GPIO port
 * */
void SysCtrl_DisableClk_GPIO(Gpio_PortType_t Port);

/*  @Service name           : SysCtrl_EnableClk_TIMER
 *  @Parameters (in)        : Timer -> the Timer number from the type " Timer_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified timer module
 *  @Expected Output        : Clock enabled for the specified timer module
 * */
void SysCtrl_EnableClk_TIMER(Timer_Number_t Timer);

/*  @Service name           : SysCtrl_DisableClk_TIMER
 *  @Parameters (in)        : Timer -> the Timer number from the type " Timer_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified timer module
 *  @Expected Output        : Clock disabled for the specified timer module
 * */
void SysCtrl_DisableClk_TIMER(Timer_Number_t Timer);

/*  @Service name           : SysCtrl_EnableClk_PWM
 *  @Parameters (in)        : PWM_Module -> the PWM Module from the type " PWM_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified PWM module
 *  @Expected Output        : Clock enabled for the specified PWM module
 * */
void SysCtrl_EnableClk_PWM(PWM_Number_t PWM_Module);

/*  @Service name           : SysCtrl_DisableClk_PWM
 *  @Parameters (in)        : PWM_Module -> the PWM Module from the type " PWM_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified PWM module
 *  @Expected Output        : Clock disabled for the specified PWM module
 * */
void SysCtrl_DisableClk_PWM(PWM_Number_t PWM_Module);

/*  @Service name           : SysCtrl_EnableClk_UART
 *  @Parameters (in)        : UART_Number -> the UART Module from the type " UART_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified UART module
 *  @Expected Output        : Clock enabled for the specified UART module
 * */
void SysCtrl_EnableClk_UART(UART_Number_t UART_Number);

/*  @Service name           : SysCtrl_DisableClk_UART
 *  @Parameters (in)        : UART_Number -> the UART Module from the type " UART_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified UART module
 *  @Expected Output        : Clock disabled for the specified UART module
 * */
void SysCtrl_DisableClk_UART(UART_Number_t UART_Number);

#endif /* SYS_CTRL_SYS_CONTROL_C_ */
