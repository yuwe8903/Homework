/************************************************************
*  @file  debug.c 
*  @description This is the function defination for the 
* 	function declaraion in debug.h file
*  @authour Yue Wei
*  @date Feb 07 2018
*************************************************************/

#include "debug.h"
#include <stdio.h>


void print_array(uint8_t * start, uint32_t length)
{
  #ifdef VERBOSE
  for(uint8_t i = 0; i < length; i++)
  {
    printf("Print_array: %d \n", start+i);
  }
  #endif
  return;
}
