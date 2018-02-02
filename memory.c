#include "memory.h"

uint8_t i;

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{  
  if(&dst <=  &src)
  {
    for(i = 0; i < length; i++)
    {
      *(dst+i) = *(src+i);
    }
  }
  else
  {
    for(i = 0; i < length; i++)
    {
      *(dst+length-1-i) = *(src+lenth-1-i);
    }
  }
  return dst;
}


uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
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
{
  for(i = 0; i < length; i++)
  {
    *src = 0;  /* zero out the first location */
    src++;     
  }
  return src;
}
/*
nt8_t * my_reverse(uint8_t * src, size_t length)
{

}


uint32_t * reverse_words(size_t length)
{

}

void free_words(uint32_t * src)
{

}
*/
