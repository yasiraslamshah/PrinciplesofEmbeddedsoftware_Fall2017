/**
 * @file conversoion.h 
 * @brief This file is to be used to project 1.
 *
 * @author Gautham and Yasir
 * @date Oct 2, 2017
 *
 */


#ifndef __CONVERSION_H__
#define __CONVERSION_H__

#include <stdint.h>

#define error (16)

/**
 * @brief function to convert integer to ascii string
 * 
 * this function takes 32 bit integer data and conver it to
 *ascii string data which is stored in a pointer given
 * and it supports bases 2 to 16 
 *
 * @return lenght of ascii string
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief function to convert ascii string to decimal integer
 * 
 * this function takes a pointer and gives number of digits present
 * and integer value of the ascii string is returned ,
 * and it supports bases 2 to 16 
 *
 * @return return integer value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);




/*@filename:  Big endian to Little endian
*@brief: short decription: a function is written that converts Big endian to Little Endian
*
*Long description: a function is used to convert the big endian to little endian ,the function
*swaps the msb and lsb of big endian to get the lsb and msb of little endian.
*The LSB of Big Endian is equal to the LSB of Little Endian and the MSB of Big Endian is the LSB
*of Little Endian.
*@return : error if not successful
*@date: 2nd October
*/
int8_t big_to_little32(uint32_t * data, uint32_t length);





/*@filename:  little endian to big endian
*@brief: –short decription: a function is written that converts little endian to big indian
*Long description: a function is used to convert the little endian to big
*endian ,the function  swaps the msb and lsb of little endian to get the lsb
*and msb  of big endian..
*@return : error if not successful
*@date: 2nd October
*/
int8_t little_to_big32(uint32_t * data, uint32_t length);


#endif /* __Conversion_H__ */

