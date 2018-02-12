/************************************************************
*  @file arch_arm32.c
*  @description This is the function defination for the 
*       function declaraion in arch_arm32.h file
*  @authour Yue Wei
*  @date Feb 10 2018
*************************************************************/
#include "arch_arm32.h"

__attribute__((always_inline)) inline uint32_t ARM32_AIRCR_get_endianness_setting()
{
  return ((__AIRCR & __AIRCR_ENDIANNESS_MASK)>>__AIRCR_ENDIANNESS_OFFSET);
}

