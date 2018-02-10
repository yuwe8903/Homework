#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <stdint.h>
#include <stdlib.h>
#ifdef KL25Z_PLATFORM && ! BBB_PLATFORM 
#include "kl25_uart.h"
#elif BBB_PLATFORM && ! KL25Z_PLATFORM
#include "data.h"
#else
#error 
#endif

#endif /*_PLATFORM_H_*/

