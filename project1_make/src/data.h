/************************************************************
*  @file data.h 
*  @desctription declare functions to print sizes of data 
* 	types and to swap and determine endianness
*  @authour Yue Wei
*  @date Fed 05 2018
*************************************************************/
#ifndef _DATA_H_
#define _DATA_H_
#include <stdio.h>
#include <stdint.h>
#include "platform.h"

//#define LITTLE_ENDIAN (0)
//#define BIG_ENDIAN (1)
#define SWAP_NO_ERROR (0) 
#define SWAP_ERROR (-1)

#if defined (__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

/************************************************************
*  print_cstd_type_size() - This function store all returns 
*       from sizeof in a temporary variable of type size_t.
*  No Inputs
*  No Return
*************************************************************/
void print_cstd_type_sizes();


/************************************************************
*  print_stdint_type_size() - This function store all returns 
*       from sizeof in a temporary variable of type size_t.
*  No Inputs
*  No Return
*************************************************************/
void print_stdint_type_sizes();


/************************************************************
*  print_pointer_size() - This function store all returns 
*       from sizeof in a temporary variable of type size_t.
*  No Inputs
*  No Return
*************************************************************/
void print_pointer_sizes();

/************************************************************
*  swap_data_endianness() - This function converts data type
* 	from one endianness to the other. 
*  Inputs:
*       unit8_t data: Pointer to the address
*       size_t type_length : size of the address
*  Return: Return SWAP_ERROR or SWAP_NO_ERROR
*************************************************************/
int32_t swap_data_endianness(uint8_t * data, size_t type_length);


/************************************************************
*  determine_endianness() - This function determines if the 
*  	current endianness is little or big.
*  Inputs:
*       No inputs
*  Return: Return a result
*************************************************************/
uint32_t determine_endianness();

#endif /*_DATA_H_*/


