/**
 * @file debug.h 
 * @brief This file is to be used to project 1.
 *
 * @author Gautham and Yasir
 * @date Oct 2, 2017
 *
 */
#ifndef __PROJECT1_H__
#define __PROJECT1_H__

#include <stdint.h>

#define DATA_SET_SIZE_W (10)
#define MEM_SET_SIZE_B  (32)
#define MEM_SET_SIZE_W  (8)
#define MEM_ZERO_LENGTH (16)

#define TEST_MEMMOVE_LENGTH (16)
#define TEST_ERROR          (1)
#define TEST_NO_ERROR       (0)
#define TESTCOUNT           (8)


/**
 * @brief  It takes a pointer to memory and prints the hex output of bytes given a pointer to a memory
 *  location and a length of bytes to print.
 * 
 * This function is written such that it can enable/disable debug printing with a compile
 * time switch .If enabled it will print as normal. It gets a pointer and lenght of bytes 
 * to print as hex output.
 *
 * @return void
 void print_memory(uint8_t * start, uint32_t length);

#endif