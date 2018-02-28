/**
 * @file debug.c 
 * @brief This file is to be used to project 1.
 *
 * @author Gautham and Yasir
 * @date Oct 2, 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "debug.h"	


#include"debug.h"
#ifdef VERBOSE
void print_memory(uint8_t* start,uint32_t length)
{
	
	while(length != 0)
	{
		
		printf("The byte in hexadecimal %x \n ",*start);
		start++;
		length--;
	}
}
#else 
void print_memory(uint8_t* start,uint32_t length)
	{
		printf("NULL");
		
	}
#endif
