/*
 *      @file       :   GP_Timers.c
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains the implementation of all interfaces can be used from the GPT driver
 */

/************************** Includes Section **********************************/
#include "GP_Timers.h"

/*********************** Services Implementation ******************************/

/*  @Service name           : GPT_Timer0A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 0 in Input Edge Time Mode
 *  @Expected Output        : Pin of T0CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer0A_InputCaptureInit(void)
{
    /* disable timer0 channel A during setup */
    TIMER0_CTL_R &= ~1;

    /* configure it as 16-bit timer mode */
    TIMER0_CFG_R = 4;

    /* select Timer mode up-count, edge-time, capture mode */
    TIMER0_TAMR_R = 0x17;

    /* configure capture on both edges */
    TIMER0_CTL_R |= 0x0C;

    /* enable timer0 channel A */
    TIMER0_CTL_R |= (1<<0);
}

/*  @Service name           : GPT_Timer1A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 1 in Input Edge Time Mode
 *  @Expected Output        : Pin of T1CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer1A_InputCaptureInit(void)
{
    /* disable timer1 channel A during setup */
    TIMER1_CTL_R &= ~1;

    /* configure it as 16-bit timer mode */
    TIMER1_CFG_R = 4;

    /* select Timer mode up-count, edge-time, capture mode */
    TIMER1_TAMR_R = 0x17;

    /* configure capture on both edges */
    TIMER1_CTL_R |= 0x0C;

    /* enable timer1 channel A */
    TIMER1_CTL_R |= (1<<0);
}


/*  @Service name           : GPT_Timer2A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 2 in Input Edge Time Mode
 *  @Expected Output        : Pin of T2CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer2A_InputCaptureInit(void)
{
    /* disable timer2 channel A during setup */
    TIMER2_CTL_R &= ~1;

    /* configure it as 16-bit timer mode */
    TIMER2_CFG_R = 4;

    /* select Timer mode up-count, edge-time, capture mode */
    TIMER2_TAMR_R = 0x17;

    /* configure capture on both edges */
    TIMER2_CTL_R |= 0x0C;

    /* enable timer2 channel A */
    TIMER2_CTL_R |= (1<<0);
}

/*  @Service name           : GPT_Timer3A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 3 in Input Edge Time Mode
 *  @Expected Output        : Pin of T3CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer3A_InputCaptureInit(void)
{
    /* disable timer3 channel A during setup */
    TIMER3_CTL_R &= ~1;

    /* configure it as 16-bit timer mode */
    TIMER3_CFG_R = 4;

    /* select Timer mode up-count, edge-time, capture mode */
    TIMER3_TAMR_R = 0x17;

    /* configure capture on both edges */
    TIMER3_CTL_R |= 0x0C;

    /* enable timer3 channel A */
    TIMER3_CTL_R |= (1<<0);
}

/*  @Service name           : GPT_Timer4A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 4 in Input Edge Time Mode
 *  @Expected Output        : Pin of T4CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer4A_InputCaptureInit(void)
{
    /* disable timer4 channel A during setup */
    TIMER4_CTL_R &= ~1;

    /* configure it as 16-bit timer mode */
    TIMER4_CFG_R = 4;

    /* select Timer mode up-count, edge-time, capture mode */
    TIMER4_TAMR_R = 0x17;

    /* configure capture on both edges */
    TIMER4_CTL_R |= 0x0C;

    /* enable timer4 channel A */
    TIMER4_CTL_R |= (1<<0);
}

/*  @Service name           : GPT_Timer5A_InputCaptureInit
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize using channel A in Timer 5 in Input Edge Time Mode
 *  @Expected Output        : Pin of T5CCP0 is ready to be used in Input Edge Time Mode
 * */
void GPT_Timer5A_InputCaptureInit(void)
{
    /* disable timer5 channel A during setup */
    TIMER5_CTL_R &= ~1;

    /* configure it as 16-bit timer mode */
    TIMER5_CFG_R = 4;

    /* select Timer mode up-count, edge-time, capture mode */
    TIMER5_TAMR_R = 0x17;

    /* configure capture on both edges */
    TIMER5_CTL_R |= 0x0C;

    /* enable timer5 channel A */
    TIMER5_CTL_R |= (1<<0);
}

/*  @Service name           : GPT_Timer0A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 0 channel A
 *  @Expected Output        : Pulse width on T0CCP0 Pin
 * */
u32 GPT_Timer0A_GetPulseWidth(void)
{
    u32 lastEdge, thisEdge , TimeDiff;

    while(1)
    {
        /*distance 1*/
        TIMER0_ICR_R = 4;                        /* clear timer0A capture flag */
        while((TIMER0_RIS_R & 4) == 0) ;         /* wait till captured */

        if( Gpio_ReadChannel((Gpio_ChannelType_t)T0CCP0_CHANNEL) )          /*check if rising edge occurs */
        {
            lastEdge = TIMER0_TAR_R;             /* save the timestamp */
            /* detect falling edge */

            TIMER0_ICR_R = 4;                   /* clear timer0A capture flag */
            while((TIMER0_RIS_R & 4) == 0) ;     /* wait till captured */
            thisEdge = TIMER0_TAR_R;             /* save the timestamp */

            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
            break;
        }
    }

    return TimeDiff;
}

/*  @Service name           : GPT_Timer1A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 1 channel A
 *  @Expected Output        : Pulse width on T1CCP0 Pin
 * */
u32 GPT_Timer1A_GetPulseWidth(void)
{
    u32 lastEdge, thisEdge , TimeDiff;

    while(1)
    {
        /*distance 1*/
        TIMER1_ICR_R = 4;                        /* clear timer1A capture flag */
        while((TIMER1_RIS_R & 4) == 0) ;         /* wait till captured */

        if( Gpio_ReadChannel((Gpio_ChannelType_t)T1CCP0_CHANNEL) )          /*check if rising edge occurs */
        {
            lastEdge = TIMER1_TAR_R;             /* save the timestamp */
            /* detect falling edge */

            TIMER1_ICR_R = 4;                   /* clear timer1A capture flag */
            while((TIMER1_RIS_R & 4) == 0) ;     /* wait till captured */
            thisEdge = TIMER1_TAR_R;             /* save the timestamp */

            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
            break;
        }
    }

    return TimeDiff;
}

/*  @Service name           : GPT_Timer2A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 2 channel A
 *  @Expected Output        : Pulse width on T2CCP0 Pin
 * */
u32 GPT_Timer2A_GetPulseWidth(void)
{
    u32 lastEdge, thisEdge , TimeDiff;

    while(1)
    {
        /*distance 1*/
        TIMER2_ICR_R = 4;                        /* clear timer2A capture flag */
        while((TIMER2_RIS_R & 4) == 0) ;         /* wait till captured */

        if( Gpio_ReadChannel((Gpio_ChannelType_t)T2CCP0_CHANNEL) )          /*check if rising edge occurs */
        {
            lastEdge = TIMER2_TAR_R;             /* save the timestamp */
            /* detect falling edge */

            TIMER2_ICR_R = 4;                   /* clear timer2A capture flag */
            while((TIMER2_RIS_R & 4) == 0) ;     /* wait till captured */
            thisEdge = TIMER2_TAR_R;             /* save the timestamp */

            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
            break;
        }
    }

    return TimeDiff;
}

/*  @Service name           : GPT_Timer3A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 3 channel A
 *  @Expected Output        : Pulse width on T3CCP0 Pin
 * */
u32 GPT_Timer3A_GetPulseWidth(void)
{
    u32 lastEdge, thisEdge , TimeDiff;

    while(1)
    {
        /*distance 1*/
        TIMER3_ICR_R = 4;                        /* clear timer3A capture flag */
        while((TIMER3_RIS_R & 4) == 0) ;         /* wait till captured */

        if( Gpio_ReadChannel((Gpio_ChannelType_t)T3CCP0_CHANNEL) )          /*check if rising edge occurs */
        {
            lastEdge = TIMER3_TAR_R;             /* save the timestamp */
            /* detect falling edge */

            TIMER3_ICR_R = 4;                   /* clear timer3A capture flag */
            while((TIMER3_RIS_R & 4) == 0) ;     /* wait till captured */
            thisEdge = TIMER3_TAR_R;             /* save the timestamp */

            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
            break;
        }
    }

    return TimeDiff;
}

/*  @Service name           : GPT_Timer4A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 4 channel A
 *  @Expected Output        : Pulse width on T4CCP0 Pin
 * */
u32 GPT_Timer4A_GetPulseWidth(void)
{
    u32 lastEdge, thisEdge , TimeDiff;

    while(1)
    {
        /*distance 1*/
        TIMER4_ICR_R = 4;                        /* clear timer4A capture flag */
        while((TIMER4_RIS_R & 4) == 0) ;         /* wait till captured */

        if( Gpio_ReadChannel((Gpio_ChannelType_t)T4CCP0_CHANNEL) )          /*check if rising edge occurs */
        {
            lastEdge = TIMER4_TAR_R;             /* save the timestamp */
            /* detect falling edge */

            TIMER4_ICR_R = 4;                   /* clear timer4A capture flag */
            while((TIMER4_RIS_R & 4) == 0) ;     /* wait till captured */
            thisEdge = TIMER4_TAR_R;             /* save the timestamp */

            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
            break;
        }
    }

    return TimeDiff;
}

/*  @Service name           : GPT_Timer5A_GetPulseWidth
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : The Pulse Width from the type "u32"
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Calculate the pulse width captured by timer 5 channel A
 *  @Expected Output        : Pulse width on T5CCP0 Pin
 * */
u32 GPT_Timer5A_GetPulseWidth(void)
{
    u32 lastEdge, thisEdge , TimeDiff;

    while(1)
    {
        /*distance 1*/
        TIMER5_ICR_R = 4;                        /* clear timer5A capture flag */
        while((TIMER5_RIS_R & 4) == 0) ;         /* wait till captured */

        if( Gpio_ReadChannel((Gpio_ChannelType_t)T5CCP0_CHANNEL) )          /*check if rising edge occurs */
        {
            lastEdge = TIMER5_TAR_R;             /* save the timestamp */
            /* detect falling edge */

            TIMER5_ICR_R = 4;                   /* clear timer5A capture flag */
            while((TIMER5_RIS_R & 4) == 0) ;     /* wait till captured */
            thisEdge = TIMER5_TAR_R;             /* save the timestamp */

            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
            break;
        }
    }

    return TimeDiff;
}
