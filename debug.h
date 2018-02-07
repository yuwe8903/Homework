/************************************************************
*  @file  debug.h 
*  @authour Yue Wei
*  @date Feb 07 2018
*************************************************************/
#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdint.h>


/************************************************************
*  print_array() - Integer to ASCII needs to convert data from a
*       standard integer type into an ASCII string. 
*  Inputs:
*       uint8_t * start:  
*       uint32_t length: 
*  Return: Return a  
*************************************************************/
void print_array(uint8_t * start, uint32_t length);


#endif /*_DEBUG_H_*/

                        
