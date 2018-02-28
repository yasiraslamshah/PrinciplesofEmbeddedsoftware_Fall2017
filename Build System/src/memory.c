/**
 * @file memory.c
 * @brief This file is to be used to project 1.
 *
 * @author Gautham and Yasir
 * @date Oct 2, 2017
 *
 */
#include <stdio.h>
#include <stdint.h>
#include "platform.h"
#include "project1.h"
#include "memory.h"
#include <stdlib.h>

uint8_t* my_memmove(uint8_t* src,uint8_t* dst,size_t length)
{
    uint8_t   i ,a , b, c ;
	uint8_t* retn ;
	retn = dst ;
	a = dst - src ;
    if ( length > a )
    {
        b = length-a ;
        for ( c = 0 ; c < b ; c++)
        {
            *(dst+b) = *(dst);
			dst++;
        }
    }
    for( i =0 ;  i<length ; i++)
    {
            if ( (src+i) != retn )
            *(retn+i) =  *(src + i);
	}
	return (uint8_t*) retn ;
}



uint8_t* my_memcpy( uint8_t* src, uint8_t* dst , size_t length)
{
	uint8_t   i;
for( i =0 ;  i<length ; i++)
	{
		*(dst+i) =  *(src + i);
	}
	return (uint8_t*)dst ;
}



uint8_t* my_memset(uint8_t* src, uint8_t length, size_t value)
{
	uint8_t i;	
	for(i = 0 ; i < length ; i++)
	{
		*(src+i) = value ;
	}

	return (uint8_t*)src;

}



uint8_t* my_memzero(uint8_t* src, size_t length)
{
	for(uint8_t i = 0 ; i < length ; i++)
	{
		*(src+i) = 0 ;
	}

	return (uint8_t*)src;
}



uint8_t* my_reverse(uint8_t* src, size_t length)
{
	uint8_t temp;
	uint8_t i=0 , value = length ;
	while(i<length-1)
	{
		temp = *(src+i);
		*(src+i) = *(src+value);
		*(src+value) =  temp ;
		value--;
		i++;	
	}

	

	return (uint8_t*)src;
}



int32_t* reserve_words(size_t length)
{

	int32_t* ptr ;
	ptr = (int32_t *) malloc(length*sizeof(int32_t));
	return ptr;
}




void free_words(int32_t * src)
{
	if(src!=NULL);
	free (src);
}




