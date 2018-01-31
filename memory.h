#ifndef _MEMORY_H_
#define _MEMORY_H_
/************************************************************
*  my_memmove() - Takes two byte pointer (one source and
*  	one destination) and a length of bytes to copy from 
*  	the source location to the destination.
*  Inputs:
*  	unit8_t * src: Pointer starting byte
*  	unit8_t * dst: Pointer ending byte
*  	size_t length : Number of bytes to move
*  Return: Return a pointer to the destination(dst)  
*************************************************************/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

#endif
