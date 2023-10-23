/*
 *      @file       :   Std_Types.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   In this file a new naming for the data types to be used
 */

#ifndef UTILS_STD_TYPES_H_
#define UTILS_STD_TYPES_H_

/* Definition of the Null value*/
#define NULL                    ((void*) 0)

/* Definition of the TRUE/FALSE value*/
#define TRUE                    (1)
#define FALSE                   (0)

/* High/Low standard status*/
#define STD_HIGH                (1)
#define STD_LOW                 (0)

/* Active/Idle standard status*/
#define STD_ACTIVE              (1)
#define STD_IDLE                (0)

/* Enable/Disable type status */
#define STD_ENABLE              (1)
#define STD_DISABLE             (0)

/********************************* STD DataTypes ****************************/

/* 1-bit boolean data type */
typedef unsigned char           boolean ;

/* 8-bit "1 byte" char or integral data type */
typedef unsigned char           u8 ;
typedef signed char             s8 ;

/* 16-bit "2 byte" integral data type */
typedef unsigned short int      u16 ;
typedef signed short int        s16 ;

/* 32-bit "4 byte" integral data type */
typedef unsigned long int       u32 ;
typedef signed long int         s32 ;

/* 64-bit "8 byte" integral data type */
typedef unsigned long long int  u64 ;
typedef signed long long int    s64 ;

/* 32-bit "4 byte" floating point data type */
typedef float                   f32 ;
/* 64-bit "8 byte" floating point data type */
typedef double                  f64 ;

#endif /* UTILS_STD_TYPES_H_ */
