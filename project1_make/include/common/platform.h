/************************************************************
*  @file platform.h 
*  @description This is the compile time switch for running
*      on different platforms
*  @authour Yue Wei
*  @date Feb 09 2018
*************************************************************/

#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <stdio.h>
#ifdef KL25Z_PLATFORM
#define PRINTF(...)  //KL25z does not have printf function.

#elif BBB_PLATFORM
//#define PRINTF(string, temp) ({\
        printf("%s \t %d \n", string, temp);\
        })
#define PRINTF (printf)
#elif HOST_PLATFORM
//#define PRINTF(string, temp) ({\
        printf("%s \t %d \n", string, temp);\
        })
#define PRINTF (printf)
#else
#error "Please specify one platform target"
#endif

#endif /*_PLATFORM_H_*/

