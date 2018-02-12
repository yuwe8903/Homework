/************************************************************
*  @file data.c
*  @description These are function definations for all of the 
*       function declaraion in data.h file 
*  @authour Yue Wei
*  @date Fed 05 2018
*************************************************************/

#include "data.h"
#include <stddef.h>
/*Print c standard type size*/
void print_cstd_type_sizes()
{
  size_t temp;
  temp  = sizeof(char);
  PRINTF(temp,"char");
  temp  = sizeof(short);
  PRINTF(temp,"short");
  temp  = sizeof(int);
  PRINTF(temp,"int");
  temp  = sizeof(long);
  PRINTF(temp,"long");
  temp  = sizeof(double);
  PRINTF(temp,"double");
  temp  = sizeof(float);
  PRINTF(temp,"float");
  temp  = sizeof(unsigned char);
  PRINTF(temp,"unsigned char");
  temp  = sizeof(unsigned int);
  PRINTF(temp,"unsigned int");
  temp  = sizeof(unsigned long);
  PRINTF(temp,"unsigned long");
  temp  = sizeof(signed char);
  PRINTF(temp,"signed char");
  temp  = sizeof(signed int);
  PRINTF(temp,"signed int");
  temp  = sizeof(signed long);
  PRINTF(temp,"signed long");
  return;
}
/*Print standard integer type size*/
void print_stdint_type_sizes()
{
  size_t temp;
  temp  = sizeof(int8_t);
  PRINTF(temp,"int8_t");
  temp  = sizeof(uint8_t);
  PRINTF(temp,"uint8_t");
  temp  = sizeof(int16_t);
  PRINTF(temp,"int16_t");
  temp  = sizeof(uint16_t);
  PRINTF(temp,"uint16_t");
  temp  = sizeof(int32_t);
  PRINTF(temp,"int32_t");
  temp  = sizeof(uint32_t);
  PRINTF(temp,"uint32_t");
  temp  = sizeof(uint_fast8_t);
  PRINTF(temp,"uint_fast8_t");
  temp  = sizeof(uint_fast16_t);
  PRINTF(temp,"uint_fast16_t");
  temp  = sizeof(uint_fast32_t);
  PRINTF(temp,"uint_fast32_t");
  temp  = sizeof(uint_least8_t);
  PRINTF(temp,"uint_least8_t");
  temp  = sizeof(uint_least16_t);
  PRINTF(temp,"uint_least16_t");
  temp  = sizeof(uint_least32_t);
  PRINTF(temp,"uint_least32_t");
  temp  = sizeof(size_t);
  PRINTF(temp,"size_t");
  temp  = sizeof(ptrdiff_t);
  PRINTF(temp,"ptrdiff_t");
  return;
}
/*Print pointer type size*/
void print_pointer_sizes()
{ 
  size_t temp;
  temp  = sizeof(char*);
  PRINTF(temp,"char*");
  temp  = sizeof(short*);
  PRINTF(temp, "short*");
  temp  = sizeof(int*);
  PRINTF(temp,"int*");
  temp  = sizeof(long*);
  PRINTF(temp,"long*");
  temp  = sizeof(double*);
  PRINTF(temp,"double*");
  temp  = sizeof(float*);
  PRINTF(temp,"float*");
  temp  = sizeof(void*);
  PRINTF(temp,"void*");
  temp  = sizeof(int8_t*);
  PRINTF(temp,"int8_t*");
  temp  = sizeof(int16_t*);
  PRINTF(temp,"int16_t*");
  temp  = sizeof(int32_t*);
  PRINTF(temp,"signed char");
  temp  = sizeof(char**);
  PRINTF(temp,"char**");
  temp  = sizeof(int**);
  PRINTF(temp,"int**");
  temp  = sizeof(void*);
  PRINTF(temp,"void*");
  return;
}
/*Swap between little endian and big endian*/
int32_t swap_data_endianness(uint8_t * data, size_t type_length)
{ 
  uint8_t i;
  uint8_t * temp;
  for(i = 0; i < type_length/2; i++)
  {
  temp = data+type_length;
  *temp = *(data+i);
  *(data+i) = *(data+type_length-1-i);
  *(data+type_length-1-i) = *temp;
  }
  /*if data have odd number of hex digits like 0x1234567, show swap error*/
  if((*data & 0xf0) == 0x00 )
  {
    return SWAP_ERROR;
  }
  /*if data have even number of hex digits like 0x12345678, show swap no error*/
  else
  {
    return SWAP_NO_ERROR;
  }
}
/*Determining whether it is little or big endian*/
uint32_t determine_endianness()
{
  uint16_t data = 0x1234;
  uint8_t * ptr = (uint8_t*)&data;
  if(*ptr == 0x34)
  {
    return 0; //LITTLE_ENDIAN;
  }
  else 
  {
    return 1; //BIG_ENDIAN;
  }
}
