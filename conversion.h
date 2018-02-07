/************************************************************
*  @file conversion.h 
*  @authour Yue Wei
*  @date Feb 04 2018
*************************************************************/
#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#include <stdint.h>
#include <stdlib.h>
/************************************************************
*  my_itoa() - Integer to ASCII needs to convert data from a
*       standard integer type into an ASCII string. 
*  Inputs:
*       int32_t data:  Integer 
*       uint8_t * ptr: Copy the converted character string
*       uint32_t base: Base 2-16
*  Return: Return a pointer to the destination(dst)  
*************************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/************************************************************
*  my_atoi() - ASCII to Integer needs to convert data back
*       from an ASCII represented string into an integer type.
*  Inputs:
*       uint8_t * ptr:  Charactor string
*       uint8_t digits: Used for integer that converted
*       uint32_t base:  Number of bytes to move
*  Return: Return a pointer to the destination(dst)  
*************************************************************/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/************************************************************
*  my_atoi() - ASCII to Integer needs to convert data back
*       from an ASCII represented string into an integer type.
*  Inputs:
*       uint8_t * ptr:  Charactor string
*       uint8_t digits: 
*       uint32_t base:  Number of bytes to move
*  Return: Return a pointer to the destination(dst)  
*************************************************************/
int32_t power(uint32_t base1, uint8_t exp);

#endif /*_CONVERSION_H_*/

