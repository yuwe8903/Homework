/************************************************************
*  @file platform.h 
*  @description This is the compile time switch for running
*      on different platforms
*  @authour Yue Wei
*  @date Feb 09 2018
*************************************************************/

#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <stdint.h>
#include <stdlib.h>
#ifdef (KL25Z_PLATFORM) && (! BBB_PLATFORM) && (! HOST_PLATFORM) 
#define PRINTF(string, temp) ({}) /*KL25z does not have printf function.*/

#elif (BBB_PLATFORM) && (! KL25Z_PLATFORM) && (! HOST_PLATFORM)
#define PRINTF(string, temp) ({\
        printf("%s \t %d \n", string, temp);\
        })

#elif (HOST_PLATFORM) && (! KL25Z_PLATFORM) && (! BBB_PLATFORM)
#define PRINTF(string, temp) ({\
        printf("%s \t %d \n", string, temp);\
        })
#else
#error "Please specify one platform target"
#endif

#endif /*_PLATFORM_H_*/

