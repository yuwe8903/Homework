#include <stdio.h>
#include "memory.h"
#include "conversion.h"
#include "data.h"
#define SIZE 6

int8_t main(void){
  //const uint8_t size = 6;
  //int8_t * pri0[] = {"hahaha"};
  /*move "know how" to the destination pointer1, 2, 3*/
  uint8_t arry[3][32] = {"I don't know how to code in C.",
			 "I don't know how to code in C.",
			 "I don't know how to code in C."};
  uint8_t move_length = 8;            /*"know how" takes 8 spaces*/ 
  uint8_t * src_prt1 = arry[0] + 8;   /*source pointer*/
  uint8_t * dst_prt1 = arry[0] + 17;  /*destination pointer1 no overlap   */
  uint8_t * dst_prt2 = arry[1] + 13;  /*destination pointer2 overlap start
				      of destination and the end of source*/
  uint8_t * dst_prt3 = arry[2] + 2;   /*destination pointer3 overlap the end 
				      of destination and start of source  */
  /*testing my_memmove function*/
  printf("Before my_memove1 \t %s \n", arry[0]);
  my_memmove(src_prt1, dst_prt1, move_length);
  printf("After my_memmove1 \t %s \n \n", arry[0]);
  
  src_prt1 = arry[1] + 8;
  printf("Before my_memove2 \t %s \n", arry[1]);
  my_memmove(src_prt1, dst_prt2, move_length);
  printf("After my_memmove2 \t %s \n \n", arry[1]);
  
  src_prt1 = arry[2] + 8;
  printf("Before my_memove3 \t %s \n", arry[2]);
  my_memmove(src_prt1, dst_prt3, move_length);
  printf("After my_memmove3 \t %s \n \n", arry[2]);

  /*declare an array and a pointer to test my_memset and my_memzero*/
  uint8_t arry1[SIZE] = {15, 19, 14, 13, 11, 2};
  uint8_t * prt1 = arry1;
  /*testing my_memset function*/
  uint8_t x = 3;
  my_memset(prt1, SIZE, x);
  printf("print: my_memset \n");
  for(uint8_t i = 0; i < SIZE; i++)
  {
    printf( "%d \t", arry1[i]);
  }
  printf("\n");

  /*testing my_memzero function*/
  my_memzero(prt1, SIZE);
  printf("print: my_memzero \n");
  for(uint8_t i = 0; i < SIZE; i++)
  {
    printf( "%d \t", arry1[i]);
  }
  printf("\n");
  
  /*declare an array and a pointer to test my_reverse*/
  uint8_t arry1_reverse[SIZE] = {15, 19, 14, 13, 11, 2};
  uint8_t arry2_reverse[SIZE-1] = {1, 20, 135, 2, 43};
  uint8_t * prt1_reverse = arry1_reverse;
  uint8_t * prt2_reverse = arry2_reverse;
  /*testing my_reverse function*/
  printf("testing even number \n"); /*testing even number*/
  printf("Before my_reverse \n");
  for(uint8_t i = 0; i < SIZE; i++)
  {
    printf( "%d \t", arry1_reverse[i]);
  }
  printf("\n");
  my_reverse(prt1_reverse, SIZE);
  printf("After my_reverse \n");
  for(uint8_t i = 0; i < SIZE; i++)
  {
    printf( "%d \t", arry1_reverse[i]);
  }
  printf("\n");
  printf("testing odd number \n"); /*testing odd number*/
  printf("Before my_reverse \n");
  for(uint8_t i = 0; i < SIZE-1; i++)
  {
    printf( "%d \t", arry2_reverse[i]);
  }
  printf("\n");
  my_reverse(prt2_reverse, SIZE-1);
  printf("After my_reverse \n");
  for(uint8_t i = 0; i < SIZE-1; i++)
  {
    printf( "%d \t", arry2_reverse[i]);
  }
  printf("\n");

  /*testing my_itoa*/
  printf("my_itoa:\n");
  uint32_t number = -1234;
  uint8_t  ptr_itoa[50];
  uint8_t n;
  n = my_itoa(number, ptr_itoa, 10);
  printf( "base = %d \t ASCII = %s \t n=%d \n",number, ptr_itoa, n);

  /*testing my_atoi*/
  printf("my_atoi:\n");
  uint8_t str[] = "10110";
  uint8_t * ptr_atoi = str;
  uint8_t digits = 6;
  uint32_t base_atoi = 2;
  int8_t value;
  value =  my_atoi(ptr_atoi, digits, base_atoi);
  printf("ptr_atoi= %s \t digits_atoi = %i \t \n", ptr_atoi, value);
  
  /*data*/
  print_cstd_type_sizes();
  print_stdint_type_sizes();
  print_pointer_sizes();
  int8_t ret;
  uint32_t da = 0x1234567;
 printf("da = 0x%X \n", da);
  printf("&da = %p \t ptrint to da = %p \t da+1 = %p \t sizeof da = %d \n", &da, (uint8_t*)&da, (uint8_t*)&da+1, sizeof(da));
  ret = swap_data_endianness((uint8_t*)&da, sizeof(da));
  ret = determine_endianness();
 printf("ret = %d\n ",ret);
// printf("BIG_ENDIAN = %d \t LITTLE= %d\n  ",BIG_ENDIAN,LITTLE_ENDIAN);
 
 //ret =ARM32_AIRCR_get_endianness_setting();
//printf("aaa = %d\n ",ret);

  return 0;
}
