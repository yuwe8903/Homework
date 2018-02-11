/************************************************************
*  @file  debug.h 
*  @description declare print array function
*  @authour Yue Wei
*  @date Feb 07 2018
*************************************************************/
#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdint.h>

/************************************************************
*  print_array() - This function prints array if VERBOSE is
*       defined
*  Inputs:
*       uint8_t * start: Point to the first element of array
*       uint32_t length: length of array
*  Return: Return nothing
*************************************************************/
void print_array(uint8_t * start, uint32_t length);

#endif /*_DEBUG_H_*/

                        
