#include "memory.h"

uint8_t * my_memzero(uint8_t * src, size_t length){
  for(uint8_t i = 0; i < length; i++){
    *src = 0;
    src++;
    return *src;
  }
}




