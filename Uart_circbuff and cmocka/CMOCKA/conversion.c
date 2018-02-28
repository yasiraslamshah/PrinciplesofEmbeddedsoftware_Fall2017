/*This program is used to convert interger to ASCII and ASCII to interger converion.*/
/*This conversion program to convert big endian to little endian and vice versa */

/*Author Gautham and Yasir*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "conversion.h"
#include "memory.h"	


int8_t big_to_little32(uint32_t * data, uint32_t length)
{     
 enum test_status status = TEST_SUCCEED;

    if (! data )

    {

    status= TEST_ERROR_INVALID_POINTERS;
    return status;
    }

	int8_t result = 1;
	if(data!=NULL)
	{
		uint8_t * byte_ptr = (uint8_t *) data;
		uint32_t x = 0;

		/*
			Return an error because the data is not aligend on a word.  Endian conversion
			will fail.
		*/
		if(length%4 != 0)
		{
			result = 1;
		}else
		{
			/*
				Loop for every word.  Reverse the values of the word.
				Set result to success.
			*/
			for(x = 0; x<length/4;x++)
			{
				byte_ptr = (uint8_t *)data;
				byte_ptr = my_reverse(byte_ptr,4);
				data += 1;
			}
			result = 0;
		}	

		data = data - x;
	}
	
	
	return result;
	
}

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
	int8_t result = 0;
	
	/*
		The process is the same to go from big_to_little and little_to_big.
		Call the big_to_little function and return result
	*/
	if(data!=NULL)
	{
		result = big_to_little32(data, length);
	}
	
	return result;
	
}

