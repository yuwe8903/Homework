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
