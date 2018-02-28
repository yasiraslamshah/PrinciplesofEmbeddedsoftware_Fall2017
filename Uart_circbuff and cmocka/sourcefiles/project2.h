/*
 * project2.h
 *
 *  Created on: Oct 29, 2017
 *  Author: Gautham
 */

#ifndef __PROJECT2_H_
#define __PROJECT2_H_

#include <MKL25Z4.H>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include"circbuf.h"
#include"uart.h"
#include"conversion.h"
#include"memory.h"
#define rx_cbuf_size 64
#define tx_cbuf_size 256
#define ITOA_STRINGSIZE 5

void project2();


typedef struct{
	uint8_t Alpha;
	uint8_t Num;
	uint8_t punct;
	uint8_t others;
}statistics;

void dump(statistics* stat);	

#endif 

