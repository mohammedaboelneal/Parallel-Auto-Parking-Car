///**
// *      @Project    :   This project implement the Parallel Auto-parking feature
// *      @components :   Small Car Kit, Ultra-sonic Sensors "HC-SR04" , DC Motors, H-Bridge "L298n", ....
// *
// *
// *      @file    :   main.c
// *      @Author  :   AVELABS Group 1
// *      @Brief   :   This is the main file of the project
// */
//
/////************************** Includes Section **********************************/
////
/////*********************** Services Prototype ******************************/
////
////
/////************************** Global Variables **********************************/
////
////int main(void)
////{
////
////    while(1)
////    {
////
////    }
////
////  return 0;
////}
//
//#include "MCAL/GPIO/Gpio.h"
//#include "SYS_CTRL/Sys_Ctrl.h"
//
//u32 Measure_distance1(void);
//u32 Measure_distance2(void);
//u32 Measure_distance3(void);
//void Timer0ACapture_init(void);
//void Timer2ACapture_init(void);
//void Timer3ACapture_init(void);
//void Delay_MicroSecond(u32 time);
//void Delay(u32 counter);
//
///* global variables to store and display distance in cm */
//volatile u32 time1; /*stores pulse on time */
//volatile u32 distance1; /* stores measured distance value */
//
//volatile u32 time2; /*stores pulse on time */
//volatile u32 distance2; /* stores measured distance value */
//
//volatile u32 time3; /*stores pulse on time */
//volatile u32 distance3; /* stores measured distance value */
//
//Gpio_PinConfig_t App_Pins[9] = {
//                                 {CH_PORTF_PIN1 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN0_GPIO , DEFAULT , OUTPUT    } ,     /*red led*/
//                                 {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN1_GPIO , DEFAULT , OUTPUT    } ,     /*blue led*/
//                                 {CH_PORTF_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTF_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*green led*/
//
//                                 {CH_PORTA_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN3_GPIO , DEFAULT , OUTPUT    } ,     /*trigger US2*/
//                                 {CH_PORTA_PIN4 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN4_GPIO , DEFAULT , OUTPUT    } ,     /*trigger US1*/
//                                 {CH_PORTA_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*trigger US3*/
//
//                                 {CH_PORTB_PIN0 , GPIO_INPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTB_PIN0_T2CCP0 , DEFAULT , OUTPUT } ,     /*Echo US3*/
//                                 {CH_PORTB_PIN2 , GPIO_INPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTB_PIN2_T3CCP0 , DEFAULT , OUTPUT } ,     /*Echo US2*/
//                                 {CH_PORTB_PIN6 , GPIO_INPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTB_PIN6_T0CCP0 , DEFAULT , OUTPUT }       /*Echo US1*/
//                                };
//
//int main(void)
//{
//    /*1- CLk for GPIO ports A,B,F and Timer 0 , 3*/
//    SysCtrl_EnableClk_GPIO(GPIO_PORTA);
//    SysCtrl_EnableClk_GPIO(GPIO_PORTB);
//    SysCtrl_EnableClk_GPIO(GPIO_PORTF);
//
//    SysCtrl_EnableClk_TIMER(TIMER0);
//    SysCtrl_EnableClk_TIMER(TIMER2);
//    SysCtrl_EnableClk_TIMER(TIMER3);
//
//    /*2- start Configuration of the pins all pin*/
//    Gpio_PinConfigInit(&( App_Pins[0]));
//    Gpio_PinConfigInit(&( App_Pins[1]));
//    Gpio_PinConfigInit(&( App_Pins[2]));
//    Gpio_PinConfigInit(&( App_Pins[3]));
//    Gpio_PinConfigInit(&( App_Pins[4]));
//    Gpio_PinConfigInit(&( App_Pins[5]));
//    Gpio_PinConfigInit(&( App_Pins[6]));
//    Gpio_PinConfigInit(&( App_Pins[7]));
//    Gpio_PinConfigInit(&( App_Pins[8]));
//
//    Timer0ACapture_init();  /*initialize Timer0A in edge edge time */
//    Timer2ACapture_init();  /*initialize Timer3A in edge edge time */
////    Delay(200);
//    Timer3ACapture_init();  /*initialize Timer3A in edge edge time */
//
//
//    while(1)
//    {
//
//        time1 = Measure_distance1(); /* take pulse duration measurement */
//
//        distance1 = (time1 * 10625)/10000000; /* convert pulse duration into distance */
//
//        if(distance1 > 20)
//        {
//            time2 = Measure_distance2();
//            distance2 = (time2 * 10625)/10000000;
//            if(distance2 > 20)
//            {
//                    Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//                    Gpio_WriteChannel(CH_PORTF_PIN2, STD_LOW);
//                    Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//            }
//            else
//            {
//                Gpio_WriteChannel(CH_PORTF_PIN1, STD_LOW);
//                Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//                Gpio_WriteChannel(CH_PORTF_PIN3, STD_LOW);
//            }
//        }
//        else
//        {
//            Gpio_WriteChannel(CH_PORTF_PIN1, STD_HIGH);
//            Gpio_WriteChannel(CH_PORTF_PIN2, STD_HIGH);
//            Gpio_WriteChannel(CH_PORTF_PIN3, STD_HIGH);
//
//        }
//
//        Delay(200);
//    }
//
//}
//
//
///* This function captures consecutive rising and falling edges of a periodic signal */
///* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
//u32 Measure_distance1(void)
//{
//    int lastEdge, thisEdge , TimeDiff;
//
//    /*Timer 0*/
//    /* Given 10us trigger pulse */
//    Gpio_WriteChannel(CH_PORTA_PIN4, STD_LOW);
//    Delay_MicroSecond(10);
//    Gpio_WriteChannel(CH_PORTA_PIN4, STD_HIGH);
//    Delay_MicroSecond(10);
//    Gpio_WriteChannel(CH_PORTA_PIN4, STD_LOW);
//    Delay_MicroSecond(10);
//
//    while(1)
//    {
//        /*distance 1*/
//        TIMER0_ICR_R = 4;                        /* clear timer0A capture flag */
//        while((TIMER0_RIS_R & 4) == 0) ;         /* wait till captured */
//
//        if( Gpio_ReadChannel(CH_PORTB_PIN6) )          /*check if rising edge occurs */
//        {
//            lastEdge = TIMER0_TAR_R;             /* save the timestamp */
//            /* detect falling edge */
//
//            TIMER0_ICR_R = 4;                   /* clear timer0A capture flag */
//            while((TIMER0_RIS_R & 4) == 0) ;     /* wait till captured */
//            thisEdge = TIMER0_TAR_R;             /* save the timestamp */
//
//            TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
//            break;
//        }
//
//    }
//
//    return TimeDiff;
//}
//
//u32 Measure_distance2(void)
//{
//    int lastEdge, thisEdge , TimeDiff;
//
//        /*Timer 3*/
//        /* Given 10us trigger pulse */
//    Gpio_WriteChannel(CH_PORTA_PIN3, STD_LOW);
//    Delay_MicroSecond(10);
//    Gpio_WriteChannel(CH_PORTA_PIN3, STD_HIGH);
//    Delay_MicroSecond(10);
//    Gpio_WriteChannel(CH_PORTA_PIN3, STD_LOW);
//    Delay_MicroSecond(10);
//
//
//        while(1)
//        {
//            TIMER3_ICR_R = 4;                        /* clear timer3A capture flag */
//            while((TIMER3_RIS_R & 4) == 0) ;         /* wait till captured */
//
//            if( Gpio_ReadChannel(CH_PORTB_PIN2) )          /*check if rising edge occurs */
//            {
//                lastEdge = TIMER3_TAR_R;             /* save the timestamp */
//                /* detect falling edge */
//
//                TIMER3_ICR_R = 4;                   /* clear timer1A capture flag */
//                while((TIMER3_RIS_R & 4) == 0) ;     /* wait till captured */
//                thisEdge = TIMER3_TAR_R;             /* save the timestamp */
//
//                TimeDiff = (thisEdge - lastEdge);       /* return the time difference */
//                break;
//            }
//        }
//
//    return TimeDiff;
//}
//
///* Timer0A initialization function */
///* Initialize Timer0A in input-edge time mode with up-count mode */
//void Timer0ACapture_init(void)
//{
//
//    TIMER0_CTL_R &= ~1;          /* disable timer0A during setup */
//    TIMER0_CFG_R = 4;            /* 16-bit timer mode */
//    TIMER0_TAMR_R = 0x17;        /* up-count, edge-time, capture mode */
//    TIMER0_CTL_R |= 0x0C;        /* capture the rising edge */
//    TIMER0_CTL_R |= (1<<0);      /* enable timer0A */
//}
//
///* Timer3A initialization function */
///* Initialize Timer3A in input-edge time mode with up-count mode */
//void Timer3ACapture_init(void)
//{
//
//    TIMER3_CTL_R &= ~1;          /* disable timer2A during setup */
//    TIMER3_CFG_R = 4;            /* 16-bit timer mode */
//    TIMER3_TAMR_R = 0x17;        /* up-count, edge-time, capture mode */
//    TIMER3_CTL_R |= 0x0C;        /* capture the rising edge */
//    TIMER3_CTL_R |= (1<<0);           /* enable timer2A */
//}
//
//
///* Create one microsecond second delay using Timer block 1 and sub timer A */
//void Delay_MicroSecond(u32 time)
//{
//    int i;
//    SYSCTL_RCGCTIMER_R |= 2;         /* enable clock to Timer Block 1 */
//    TIMER1_CTL_R = 0;               /* disable Timer before initialization */
//    TIMER1_CFG_R = 0x04;            /* 16-bit option */
//    TIMER1_TAMR_R = 0x02;           /* periodic mode and down-counter */
//    TIMER1_TAILR_R = 16 - 1;        /* TimerA interval load value reg */
//    TIMER1_ICR_R = 0x1;             /* clear the TimerA timeout flag */
//    TIMER1_CTL_R |= 0x01;           /* enable Timer A after initialization */
//
//    for(i = 0; i < time; i++)
//    {
//        while ((TIMER1_RIS_R & 0x1) == 0) ;         /* wait for TimerA timeout flag */
//        TIMER1_ICR_R = 0x1;                         /* clear the TimerA timeout flag */
//    }
//}
//
//void Delay(u32 counter)
//{
//    unsigned long i = 0;
//
//    for(i=0; i< counter*1000; i++);
//}
