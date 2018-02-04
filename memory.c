#include "memory.h"
#include <stdio.h>
int8_t i;

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{ 
  if(dst >=  src)
  {
    for(i = 0; i < length; i++)
    {
      *(dst+length-1-i) = *(src+length-1-i);
    }
  }
  else
  {
    for(i = 0; i < length; i++)
    {
      *(dst+i) = *(src+i);
    }
  }
  return dst;
}

/*
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
  for(i = 0; i < length; i++)
  {
    *(dst+i)= *(src+i);
  }
  return dst;
}
*/
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

uint8_t * my_reverse(uint8_t * src, size_t length)
{ 
  uint8_t temp_reverse;
  if(length%2 == 0)
  {
    for(i = 0; i < length/2; i++)
    {  
      temp_reverse = *(src+i);
      *(src+i) = *(src+length-1-i);
      *(src+length-1-i) = temp_reverse;
    }
  }
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


/*
void * reverse_words(size_t length)
{

}

void free_words(uint32_t * src)


}
*/
