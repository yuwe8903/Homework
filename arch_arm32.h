/***************************************************************
*  @file arch_arm32.h 
*  @ description declare function to get the endianness setting
*  @authour Yue Wei
*  @date Feb 10 2018
****************************************************************/

#include <stdint.h>
#define __SCB_ADDRESS (0xE000ED00)
#define __AIRCR_ADDRESS_OFFSET (0xE000ED0C)
/*uint32_t points to the address of __AIRCR_ADDRESS, 
**then dereference it using the star in front.*/
#define __AIRCR (*((volatile uint32_t*)__AIRCR_ADDRESS_OFFSET))
#define __AIRCR_ENDIANNESS_OFFSET (15)
#define __AIRCR_ENDIANNESS_MASK (0x00008000)

/*******************************************************
* ARM32_AIRCR_get_endianness_setting() - This function 
* 	reads AIRCR and return endianness value of the 
*  	currently configured ARM processor.
* Inputs: 
* 	Not inputs
* Return:
* 	Return the endianness value
********************************************************/

__attribute__((always_inline)) inline uint32_t ARM32_AIRCR_get_endianness_setting();
