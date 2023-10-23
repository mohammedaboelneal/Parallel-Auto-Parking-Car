/*
 *      @file       :   Bit_Math.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   In this file the implementation of the mostly used operation on the bit level using Read-Modify-Write
 */

#ifndef UTILS_BIT_MATH_H_
#define UTILS_BIT_MATH_H_

/*********************  Macro Functions Section     *********************/
/* Bits math*/

/*set bit in variable/register to high*/
#define SET_BIT(reg,bit)            ( reg |= (1 << bit) )

/*clear bit in variable/register to low*/
#define CLEAR_BIT(reg,bit)          ( reg &= ~(1 << bit) )

/*toggle bit in variable/register*/
#define TOGGLE_BIT(reg,bit)         ( reg ^= (1 << bit) )

/*read bit in variable/register*/
#define READ_BIT(reg,bit)           ( ( reg & (1 << bit ) ) >> bit )


#endif /* UTILS_BIT_MATH_H_ */
