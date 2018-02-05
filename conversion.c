#include "conversion.h"
#include "memory.h"
#include <stdio.h>
#include <math.h>
uint8_t * my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{ 
  int8_t i = 1;
  uint8_t remainder;
  uint8_t sign = 0; 
  /*considering the sign of input data*/
  if(data < 0)
  {
    data = -data;
    sign = 1;
  }
  *ptr = '\0';
  /*Do the data to ASCII conversion*/
  while(data != 0) 
  {
    remainder = data%base; 
    if(remainder > 9)
    { /*put the remainder to the pointer*/
      *(ptr+i) = (remainder-10)+'a';
    }
    else
    {
      *(ptr+i) = remainder+ '0';
    }
    data = data/base;
    i++;
  }
  /*Taken care of the sign, wether it's a positive or a negative sign*/
  if(sign == 1)              
  {
    *(ptr+i) = '-';
    my_reverse(ptr, i+1);    
  }
  else if(sign == 0)  
  {
    my_reverse(ptr, i);
  }
  return ptr;
}

int32_t my_atoi(uint8_t * ptr, int8_t digits, uint32_t base)
{ 
  uint8_t integer = 0;
  uint8_t j;
  digits = 0;
  /*If there is no negative sign at the ptr string*/
  if(*ptr != '-')
  {
    /*Do the conversion from ASCII to integer*/
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
  /*if there is a negative sign at the ptr string*/
  else if(*ptr == '-')
  { 
    /*Do the conversion from ASCII to integer*/
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
/*This power function does the exponential calculation base1^exp */
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
