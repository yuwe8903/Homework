#include "conversion.h"
#include "memory.h"
#include <stdio.h>
#include <math.h>
uint8_t * my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{ 
  int8_t i = 1;
  uint8_t remainder;
  uint8_t sign = 0; 
  printf("sign in= %d \n",sign);
  if(data < 0)
  {
    data = -data;
    sign = 1;
  }
    printf("sign out = %d \t data = %d\n",sign, data);
  *ptr = '\0';
  while(data != 0) 
  {
    remainder = data%base;    /*save the remainder*/
    if(remainder > 9)
    { /*put the remainder to the pointer*/
      *(ptr+i) = (remainder-10)+'a';
    }
    else
    {
      *(ptr+i) = remainder+ '0';
    }
    data = data/base;
    printf("ptr = %s \t", ptr+i);
    i++;
  }
  
  printf("ptri = %s \n", ptr+i);
  if(sign == 1)              /*handles negative sign*/
  {
    *(ptr+i) = '-';
    printf("ptri+1 = %s \n", ptr+i);
    my_reverse(ptr, i+1);    /*call my_reverse function to 
			       reverse pointer string*/
  }
  else if(sign == 0)         /*handles positive sign*/
  {
    my_reverse(ptr, i);
  }
  return ptr;
}

int32_t my_atoi(uint8_t * ptr, int8_t digits, uint32_t base)
{ 
  uint8_t integer = 0;
  uint8_t j;
  if(*ptr != '-')
  {
    digits = 0;
    while(*(ptr+integer) != '\0')
    {
      integer++;
    }
    for(j = 0; j < integer; j++)
    {
      digits = digits + power(base, j) * (*(ptr+integer-1-j) - 48);
    }
    printf("digits_total pos=  %d \n",digits);
  }
  else if(*ptr == '-')
  { 
    digits = 0;
    while(*(ptr+integer) != '\0')
    {
      integer++;
    }
    for(j = 0; j < integer-1; j++)
    {
      digits = digits + power(base, j) * (*(ptr+integer-1-j) - 48);
    }
    digits = -digits;
   printf("digits_total neg = %d \n",digits);
  }
  return digits;
}

int32_t power(uint32_t base1, uint8_t exp)
{ 
  uint32_t result = 1;
  while(exp != 0)
  {
    result = result * base1;
    exp--;
  }
  return result;
}
