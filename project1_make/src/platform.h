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
//#pragma GCC poison printf
<<<<<<< HEAD
#define PRINTF(temp, string) ({})//KL25z does not have printf function.
#elif (BBB_PLATFORM) && (! KL25Z_PLATFORM) && (! HOST_PLATFORM)
#define PRINTF(temp, string) ({\
        printf("sizeof(%s) = %d \n", string, temp);\
        })

=======
#undef PRINTF(temp, string) ({\
        printf("sizeof(%s) = %d \n", string, temp);\
        })
#elif (BBB_PLATFORM) && (! KL25Z_PLATFORM) && (! HOST_PLATFORM)
 BBB_initialize();
>>>>>>> 0b736ddb28a3e78c53573fc7e22be219c002724f
#else
#error "Please specify one platform target"
#endif

#endif /*_PLATFORM_H_*/

