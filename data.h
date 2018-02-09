/************************************************************
*  @file data.h 
*  @authour Yue Wei
*  @date Fed 08 2018
*************************************************************/
#ifndef _DATA_H_
#define _DATA_H_
#include <stdio.h>
#define PRINTF(temp, string) ({\
	printf("sizeof(%s) = %d \n", string, temp);\
	})
 
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
#endif /*_DATA_H_*/


