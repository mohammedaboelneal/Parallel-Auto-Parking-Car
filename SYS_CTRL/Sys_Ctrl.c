/*
 *      @file       :   Sys_Ctrl.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the System Control driver
 */

/************************** Includes Section **********************************/
#include "Sys_Ctrl.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : SysCtrl_EnableClk_GPIO
 *  @Parameters (in)        : Port -> the GPIO port number from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified GPIO port
 *  @Expected Output        : Clock enabled for the specified GPIO port
 * */
void SysCtrl_EnableClk_GPIO(Gpio_PortType_t Port)
{
    switch(Port)
    {
        case GPIO_PORTA:
            SET_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTA_BIT);
            break;

        case GPIO_PORTB:
            SET_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTB_BIT);
            break;

        case GPIO_PORTC:
            SET_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTC_BIT);
            break;

        case GPIO_PORTD:
            SET_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTD_BIT);
            break;

        case GPIO_PORTE:
            SET_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTE_BIT);
            break;

        case GPIO_PORTF:
            SET_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTF_BIT);
            break;

        default :
            /*error*/
            break;
    }
}

/*  @Service name           : SysCtrl_DisableClk_GPIO
 *  @Parameters (in)        : Port -> the GPIO port number from the type " Gpio_PortType_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified GPIO port
 *  @Expected Output        : Clock disabled for the specified GPIO port
 * */
void SysCtrl_DisableClk_GPIO(Gpio_PortType_t Port)
{
    switch(Port)
    {
        case GPIO_PORTA:
            CLEAR_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTA_BIT);
            break;

        case GPIO_PORTB:
            CLEAR_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTB_BIT);
            break;

        case GPIO_PORTC:
            CLEAR_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTC_BIT);
            break;

        case GPIO_PORTD:
            CLEAR_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTD_BIT);
            break;

        case GPIO_PORTE:
            CLEAR_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTE_BIT);
            break;

        case GPIO_PORTF:
            CLEAR_BIT(SYSCTL_RCGCGPIO_R , SYS_CTRL_GPIO_PORTF_BIT);
            break;

        default :
            /*error*/
            break;
    }
}

/*  @Service name           : SysCtrl_EnableClk_TIMER
 *  @Parameters (in)        : Timer -> the Timer number from the type " Timer_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified timer module
 *  @Expected Output        : Clock enabled for the specified timer module
 * */
void SysCtrl_EnableClk_TIMER(Timer_Number_t Timer)
{
    switch(Timer)
    {
        case TIMER0:
            SET_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER0_BIT);
            break;

        case TIMER1:
            SET_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER1_BIT);
            break;

        case TIMER2:
            SET_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER2_BIT);
            break;

        case TIMER3:
            SET_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER3_BIT);
            break;

        case TIMER4:
            SET_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER4_BIT);
            break;

        case TIMER5:
            SET_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER5_BIT);
            break;

        default :
            /*error*/
            break;
    }

}

/*  @Service name           : SysCtrl_DisableClk_TIMER
 *  @Parameters (in)        : Timer -> the Timer number from the type " Timer_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified timer module
 *  @Expected Output        : Clock disabled for the specified timer module
 * */
void SysCtrl_DisableClk_TIMER(Timer_Number_t Timer)
{
    switch(Timer)
    {
        case TIMER0:
            CLEAR_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER0_BIT);
            break;

        case TIMER1:
            CLEAR_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER1_BIT);
            break;

        case TIMER2:
            CLEAR_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER2_BIT);
            break;

        case TIMER3:
            CLEAR_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER3_BIT);
            break;

        case TIMER4:
            CLEAR_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER4_BIT);
            break;

        case TIMER5:
            CLEAR_BIT(SYSCTL_RCGCTIMER_R , SYS_CTRL_TIMER5_BIT);
            break;

        default :
            /*error*/
            break;
    }

}

/*  @Service name           : SysCtrl_EnableClk_PWM
 *  @Parameters (in)        : PWM_Module -> the PWM Module from the type " PWM_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified PWM module
 *  @Expected Output        : Clock enabled for the specified PWM module
 * */
void SysCtrl_EnableClk_PWM(PWM_Number_t PWM_Module)
{
    switch(PWM_Module)
    {
        case PWM0 :
            SET_BIT(SYSCTL_RCGCPWM_R , SYS_CTRL_PWM0_BIT);
            break;

        case PWM1 :
            SET_BIT(SYSCTL_RCGCPWM_R , SYS_CTRL_PWM1_BIT);
            break;

        default :
            /*error*/
            break;
    }
}

/*  @Service name           : SysCtrl_DisableClk_PWM
 *  @Parameters (in)        : PWM_Module -> the PWM Module from the type " PWM_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified PWM module
 *  @Expected Output        : Clock disabled for the specified PWM module
 * */
void SysCtrl_DisableClk_PWM(PWM_Number_t PWM_Module)
{
    switch(PWM_Module)
    {
        case PWM0 :
            CLEAR_BIT(SYSCTL_RCGCPWM_R , SYS_CTRL_PWM0_BIT);
            break;

        case PWM1 :
            CLEAR_BIT(SYSCTL_RCGCPWM_R , SYS_CTRL_PWM1_BIT);
            break;

        default :
            /*error*/
            break;
    }
}

/*  @Service name           : SysCtrl_EnableClk_UART
 *  @Parameters (in)        : UART_Number -> the UART Module from the type " UART_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to enable the clock to the specified UART module
 *  @Expected Output        : Clock enabled for the specified UART module
 * */
void SysCtrl_EnableClk_UART(UART_Number_t UART_Number)
{
    switch(UART_Number)
    {
        case UART0:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART0_BIT);
            break;

        case UART1:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART1_BIT);
            break;

        case UART2:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART2_BIT);
            break;

        case UART3:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART3_BIT);
            break;

        case UART4:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART4_BIT);
            break;

        case UART5:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART5_BIT);
            break;

        case UART6:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART6_BIT);
            break;

        case UART7:
            SET_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART7_BIT);
            break;

        default :
            /*error*/
            break;
    }

}

/*  @Service name           : SysCtrl_DisableClk_UART
 *  @Parameters (in)        : UART_Number -> the UART Module from the type " UART_Number_t"
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to disable the clock to the specified UART module
 *  @Expected Output        : Clock disabled for the specified UART module
 * */
void SysCtrl_DisableClk_UART(UART_Number_t UART_Number)
{
    switch(UART_Number)
    {
        case UART0:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART0_BIT);
            break;

        case UART1:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART1_BIT);
            break;

        case UART2:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART2_BIT);
            break;

        case UART3:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART3_BIT);
            break;

        case UART4:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART4_BIT);
            break;

        case UART5:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART5_BIT);
            break;

        case UART6:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART6_BIT);
            break;

        case UART7:
            CLEAR_BIT(SYSCTL_RCGCUART_R , SYS_CTRL_UART7_BIT);
            break;

        default :
            /*error*/
            break;
    }
}


