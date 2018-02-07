#include "memory.h"
#include <stdio.h>
int8_t i;

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{ /*Backward copying*/
  if(dst >=  src)
  {
    for(i = 0; i < length; i++)
    {
      *(dst+length-1-i) = *(src+length-1-i);
    }
  }
  /*Forward copying*/
  else
  {
    for(i = 0; i < length; i++)
    {
      *(dst+i) = *(src+i);
    }
  }
  return dst;
}


uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{ /*Forward copying*/
  for(i = 0; i < length; i++)
  {
    *(dst+i)= *(src+i);
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
  for(i = 0; i < length; i++)
  {
    *src = value;
    src++;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{ // if(src == NULL){}
  for(i = 0; i < length; i++)
  {
    *src = 0;  /* zero out the first location */
    src++;     
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{ 
  uint8_t temp_reverse;
  /*Reverse the even number of src string*/
  if(length%2 == 0)
  { 
    for(i = 0; i < length/2; i++)
    {  
      temp_reverse = *(src+i);
      *(src+i) = *(src+length-1-i);
      *(src+length-1-i) = temp_reverse;
    }
  }
  /*Reverse the odd number of src string*/
  else
  {
    for(i = 0; i < (length-1)/2; i++)
    { 
      temp_reverse = *(src+length-1-i);
      *(src+length-1-i) = *(src+i);
      *(src+i) = temp_reverse;
    }
  }
  return src;
}


int32_t * reverse_words(size_t length)
{
  int32_t * p;
  p = (int32_t *)malloc(length * sizeof(int8_t));
  return p; 
}

void free_words(uint32_t * src)
{
  free(src);
  return;
}

