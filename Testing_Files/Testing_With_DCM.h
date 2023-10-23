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
//
//void Delay_ms(u32 time_ms);
//void PWM_init(void);
//void Turn_OtherDirection(void);
//void Turn_oneDirection(void);
//
//void Turn_OtherDirection2(void);
//void Turn_oneDirection2(void);
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
//int duty_cycle = 4999;
//
//
//int main(void)
//{
//    /*1- CLk for GPIO ports A,B,F and Timer 0 , 3*/
////    SysCtrl_EnableClk_GPIO(GPIO_PORTA);
////    SysCtrl_EnableClk_GPIO(GPIO_PORTB);
////    SysCtrl_EnableClk_GPIO(GPIO_PORTF);
////
////    SysCtrl_EnableClk_TIMER(TIMER0);
////    SysCtrl_EnableClk_TIMER(TIMER2);
////    SysCtrl_EnableClk_TIMER(TIMER3);
//
//    PWM_init();
//    Turn_OtherDirection();
//    Turn_OtherDirection2();
//
//    PWM1_3_CMPA_R = 0 ;
//    PWM1_2_CMPA_R = 0 ;
//
//    for(;;)
//    {
//
//        Turn_OtherDirection();
//        Turn_OtherDirection2();
//
//        Delay_ms(3000);
//
//        Turn_oneDirection();
//        Turn_oneDirection2();
//
//        Delay_ms(3000);
//
//        Turn_oneDirection();
//        Turn_OtherDirection2();
//
//        Delay_ms(3000);
//
//        Turn_OtherDirection();
//        Turn_oneDirection2();
//
//        Delay_ms(3000);
////        duty_cycle = duty_cycle - 10;
////
////        if (duty_cycle <= 0)
////                duty_cycle = 5000;
////
////        PWM1_3_CMPA_R = duty_cycle;
////
////        Delay_ms(10);
//    }
//
//
//}
//
//
////Spin motor in one direction by giving IN1 and IN2 signals to L298N
//void Turn_oneDirection(void)
//{
//    SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
//    GPIO_PORTA_DIR_R |= (1<<3)|(1<<2);            /* pin digital */
//    GPIO_PORTA_DEN_R |= (1<<3)|(1<<2);            /* pin digital */
//    GPIO_PORTA_DATA_R |=(1<<2);
//    GPIO_PORTA_DATA_R &=~(1<<3);
//}
//
////Spin motor in other direction by giving IN1 and IN2 signals to L298N
//
//void Turn_OtherDirection(void)
//{
//    SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTA */
//    GPIO_PORTA_DIR_R |= (1<<3)|(1<<2);            /* pin digital */
//    GPIO_PORTA_DEN_R |= (1<<3)|(1<<2);            /* pin digital */
//    GPIO_PORTA_DATA_R |=(1<<3);
//    GPIO_PORTA_DATA_R &=~(1<<2);
//}
//
//void Turn_OtherDirection2(void)
//{
//    SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
//    GPIO_PORTA_DIR_R |= (1<<4)|(1<<5);            /* pin digital */
//    GPIO_PORTA_DEN_R |= (1<<4)|(1<<5);            /* pin digital */
//    GPIO_PORTA_DATA_R |=(1<<4);
//    GPIO_PORTA_DATA_R &=~(1<<5);
//}
//
//void Turn_oneDirection2(void)
//{
//    SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
//    GPIO_PORTA_DIR_R |= (1<<4)|(1<<5);            /* pin digital */
//    GPIO_PORTA_DEN_R |= (1<<4)|(1<<5);            /* pin digital */
//    GPIO_PORTA_DATA_R |=(1<<5);
//    GPIO_PORTA_DATA_R &=~(1<<4);
//}
//
//void PWM_init(void)
//{
//
//     /* Clock setting for PWM and GPIO PORT */
//    SYSCTL_RCGCPWM_R |= 2;       /* Enable clock to PWM1 module */
//    SYSCTL_RCGCGPIO_R |= 0x20;  /* Enable system clock to PORTF */
//
//    SYSCTL_RCC_R |= (1<<20);    /* Enable System Clock Divisor function  */
//    SYSCTL_RCC_R |= 0x000E0000; /* Use pre-divider value of 64 and after that feed clock to PWM1 module*/
//
// /* Setting of PF2,3 pin for M1PWM6 , M1PWM7 channel output pin */
//    GPIO_PORTF_DEN_R |= (1<<2) | (1<<0) ;          /* set PF2,3 as a digital pin */
//    GPIO_PORTF_AFSEL_R |= (1<<2) | (1<<0) ;          /* PF2,3 sets a alternate function */
//    GPIO_PORTF_PCTL_R &= ~0x00000F0F;      /*set PF2,3 as output pin */
//    GPIO_PORTF_PCTL_R |= 0x00000505; /* make PF2,3 PWM output pin */
//
//
//    PWM1_3_CTL_R &= ~(1<<0);   /* Disable Generator 3 counter */
//    PWM1_3_CTL_R &= ~(1<<1);   /* select down count mode of counter 3*/
//    PWM1_3_GENA_R = 0x0000008C;  /* Set PWM output when counter reloaded and clear when matches PWMCMPA */
//    PWM1_3_LOAD_R = 5000;     /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
//    PWM1_3_CMPA_R = 4999;     /* set duty cyle to to minumum value*/
//    PWM1_3_CTL_R = 1;           /* Enable Generator 3 counter */
//    PWM1_ENABLE_R = 0xC0;      /* Enable PWM1 channel 6,7 output */
//
//    PWM1_2_CTL_R &= ~(1<<0);   /* Disable Generator 3 counter */
//    PWM1_2_CTL_R &= ~(1<<1);   /* select down count mode of counter 3*/
//    PWM1_2_GENA_R = 0x0000008C;  /* Set PWM output when counter reloaded and clear when matches PWMCMPA */
//    PWM1_2_LOAD_R = 5000;     /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
//    PWM1_2_CMPA_R = 4999;     /* set duty cyle to to minumum value*/
//    PWM1_2_CTL_R = 1;           /* Enable Generator 3 counter */
//    PWM1_ENABLE_R = 0x60;      /* Enable PWM1 channel 6,7 output */
//}
//
//
///* This function generates delay in ms */
///* calculations are based on 16MHz system clock frequency */
//
//void Delay_ms(u32 time_ms)
//{
//    int i, j;
//    for(i = 0 ; i < time_ms; i++)
//        for(j = 0; j < 3180; j++)
//            {}  /* excute NOP for 1ms */
//}




/**
 *      @Project    :   This project implement the Parallel Auto-parking feature
 *      @components :   Small Car Kit, Ultra-sonic Sensors "HC-SR04" , DC Motors, H-Bridge "L298n", ....
 *
 *
 *      @file    :   main.c
 *      @Author  :   AVELABS Group 1
 *      @Brief   :   This is the main file of the project
 */

///************************** Includes Section **********************************/
//
///*********************** Services Prototype ******************************/
//
//
///************************** Global Variables **********************************/
//
//int main(void)
//{
//
//    while(1)
//    {
//
//    }
//
//  return 0;
//}

//#include "MCAL/GPIO/Gpio.h"
//#include "SYS_CTRL/Sys_Ctrl.h"
//
//
//void Delay_ms(u32 time_ms);
//void PWM_init(void);
//void Turn_OtherDirection(void);
//void Turn_oneDirection(void);
//
//void Turn_OtherDirection2(void);
//void Turn_oneDirection2(void);
//
//Gpio_PinConfig_t App_Pins[9] = {
//                                 {CH_PORTF_PIN0 , GPIO_OUTPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTF_PIN0_M1PWM4 , DEFAULT , OUTPUT    } ,     /*m2 speed*/
//                                 {CH_PORTF_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , OTHER_FUNCTIONALITY , PORTF_PIN2_M1PWM6 , DEFAULT , OUTPUT    } ,     /*m1 speed*/
//
//                                 {CH_PORTA_PIN2 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*m1 control 1*/
//                                 {CH_PORTA_PIN3 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN3_GPIO , DEFAULT , OUTPUT    } ,     /*m1 control 2*/
//                                 {CH_PORTA_PIN4 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN4_GPIO , DEFAULT , OUTPUT    } ,     /*m2 control 1*/
//                                 {CH_PORTA_PIN5 , GPIO_OUTPUT , DIGITAL_SIGNAL , GPIO_FUNCTIONALITY , PORTA_PIN2_GPIO , DEFAULT , OUTPUT    } ,     /*m1 control 2*/
//                                };
//int duty_cycle = 4999;
//
//
//int main(void)
//{
//    /*1- CLk for GPIO ports A,B,F and Timer 0 , 3*/
//    SysCtrl_EnableClk_GPIO(GPIO_PORTA);
//    SysCtrl_EnableClk_GPIO(GPIO_PORTF);
//
//    SysCtrl_EnableClk_PWM(PWM1);
//
//    Gpio_PinConfigInit(&(App_Pins[0]));
//    Gpio_PinConfigInit(&(App_Pins[1]));
//    Gpio_PinConfigInit(&(App_Pins[2]));
//    Gpio_PinConfigInit(&(App_Pins[3]));
//    Gpio_PinConfigInit(&(App_Pins[4]));
//    Gpio_PinConfigInit(&(App_Pins[5]));
//
//    PWM_init();
//
//    PWM1_3_CMPA_R = 0 ;
//    PWM1_2_CMPA_R = 0 ;
//
//    for(;;)
//    {
//
//        Turn_OtherDirection();
//        Turn_OtherDirection2();
//
//        Delay_ms(3000);
//
//        Turn_oneDirection();
//        Turn_oneDirection2();
//
//        Delay_ms(3000);
//
//        Turn_oneDirection();
//        Turn_OtherDirection2();
//
//        Delay_ms(3000);
//
//        Turn_OtherDirection();
//        Turn_oneDirection2();
//
//        Delay_ms(3000);
//    }
//
//
//}
//
//
////Spin motor in one direction by giving IN1 and IN2 signals to L298N
//void Turn_oneDirection(void)
//{
//    Gpio_WriteChannel(CH_PORTA_PIN2, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTA_PIN3, STD_LOW);
//}
//
////Spin motor in other direction by giving IN1 and IN2 signals to L298N
//
//void Turn_OtherDirection(void)
//{
//    Gpio_WriteChannel(CH_PORTA_PIN3, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTA_PIN2, STD_LOW);
//}
//
//void Turn_OtherDirection2(void)
//{
//    Gpio_WriteChannel(CH_PORTA_PIN4, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTA_PIN5, STD_LOW);
//}
//
//void Turn_oneDirection2(void)
//{
//    Gpio_WriteChannel(CH_PORTA_PIN5, STD_HIGH);
//    Gpio_WriteChannel(CH_PORTA_PIN4, STD_LOW);
//}
//
//void PWM_init(void)
//{
//    SYSCTL_RCC_R |= (1<<20);    /* Enable System Clock Divisor function  */
//    SYSCTL_RCC_R |= 0x000E0000; /* Use pre-divider value of 64 and after that feed clock to PWM1 module*/
//
//    PWM1_3_CTL_R &= ~(1<<0);   /* Disable Generator 3 counter */
//    PWM1_3_CTL_R &= ~(1<<1);   /* select down count mode of counter 3*/
//    PWM1_3_GENA_R = 0x0000008C;  /* Set PWM output when counter reloaded and clear when matches PWMCMPA */
//    PWM1_3_LOAD_R = 5000;     /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
//    PWM1_3_CMPA_R = 4999;     /* set duty cyle to to minumum value*/
//    PWM1_3_CTL_R = 1;           /* Enable Generator 3 counter */
//    PWM1_ENABLE_R |= 0x40;      /* Enable PWM1 channel 6,7 output */
//
//    PWM1_2_CTL_R &= ~(1<<0);   /* Disable Generator 3 counter */
//    PWM1_2_CTL_R &= ~(1<<1);   /* select down count mode of counter 3*/
//    PWM1_2_GENA_R = 0x0000008C;  /* Set PWM output when counter reloaded and clear when matches PWMCMPA */
//    PWM1_2_LOAD_R = 5000;     /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
//    PWM1_2_CMPA_R = 4999;     /* set duty cyle to to minumum value*/
//    PWM1_2_CTL_R = 1;           /* Enable Generator 3 counter */
//    PWM1_ENABLE_R |= 0x60;      /* Enable PWM1 channel 6,7 output */
//}
//
//
///* This function generates delay in ms */
///* calculations are based on 16MHz system clock frequency */
//
//void Delay_ms(u32 time_ms)
//{
//    int i, j;
//    for(i = 0 ; i < time_ms; i++)
//        for(j = 0; j < 3180; j++)
//            {}  /* excute NOP for 1ms */
//}

