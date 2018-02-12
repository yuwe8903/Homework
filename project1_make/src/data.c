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
  PRINTF("char",temp);
  temp  = sizeof(short);
  PRINTF("short",temp);
  temp  = sizeof(int);
  PRINTF("int",temp);
  temp  = sizeof(long);
  PRINTF("long",temp);
  temp  = sizeof(double);
  PRINTF("double",temp);
  temp  = sizeof(float);
  PRINTF("float",temp);
  temp  = sizeof(unsigned char);
  PRINTF("unsigned char",temp);
  temp  = sizeof(unsigned int);
  PRINTF("unsigned int",temp);
  temp  = sizeof(unsigned long);
  PRINTF("unsigned long",temp);
  temp  = sizeof(signed char);
  PRINTF("signed char",temp);
  temp  = sizeof(signed int);
  PRINTF("signed int",temp);
  temp  = sizeof(signed long);
  PRINTF("signed long",temp);
  return;
}
/*Print standard integer type size*/
void print_stdint_type_sizes()
{
  size_t temp;
  temp  = sizeof(int8_t);
  PRINTF("int8_t",temp);
  temp  = sizeof(uint8_t);
  PRINTF("uint8_t",temp);
  temp  = sizeof(int16_t);
  PRINTF("int16_t",temp);
  temp  = sizeof(uint16_t);
  PRINTF("uint16_t",temp);
  temp  = sizeof(int32_t);
  PRINTF("int32_t",temp);
  temp  = sizeof(uint32_t);
  PRINTF("uint32_t",temp);
  temp  = sizeof(uint_fast8_t);
  PRINTF("uint_fast8_t",temp);
  temp  = sizeof(uint_fast16_t);
  PRINTF("uint_fast16_t",temp);
  temp  = sizeof(uint_fast32_t);
  PRINTF("uint_fast32_t",temp);
  temp  = sizeof(uint_least8_t);
  PRINTF("uint_least8_t",temp);
  temp  = sizeof(uint_least16_t);
  PRINTF("uint_least16_t",temp);
  temp  = sizeof(uint_least32_t);
  PRINTF("uint_least32_t",temp);
  temp  = sizeof(size_t);
  PRINTF("size_t",temp);
  temp  = sizeof(ptrdiff_t);
  PRINTF("ptrdiff_t",temp);
  return;
}
/*Print pointer type size*/
void print_pointer_sizes()
{ 
  size_t temp;
  temp  = sizeof(char*);
  PRINTF("char*",temp);
  temp  = sizeof(short*);
  PRINTF( "short*",temp);
  temp  = sizeof(int*);
  PRINTF("int*",temp);
  temp  = sizeof(long*);
  PRINTF("long*",temp);
  temp  = sizeof(double*);
  PRINTF("double*",temp);
  temp  = sizeof(float*);
  PRINTF("float*",temp);
  temp  = sizeof(void*);
  PRINTF("void*",temp);
  temp  = sizeof(int8_t*);
  PRINTF("int8_t*",temp);
  temp  = sizeof(int16_t*);
  PRINTF("int16_t*",temp);
  temp  = sizeof(int32_t*);
  PRINTF("signed char",temp);
  temp  = sizeof(char**);
  PRINTF("char**",temp);
  temp  = sizeof(int**);
  PRINTF("int**",temp);
  temp  = sizeof(void*);
  PRINTF("void*",temp);
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
