/**
 * @file circbuf.h 
 * @brief This file is to be used to project 2.
 *
 * @author Gautham and Yasir
 * @date Oct 24, 2017
 *
 */
#ifndef __circbuf_H__
#define __circbuf_H__
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct buf{
	uint8_t* buffptr;
	uint8_t size;
	uint8_t *ptrhead;
	uint8_t *ptrtail;
	uint8_t count;
}cb_t;

typedef enum state
{
	bufferfull,
	bufferempty,
	success,
	error
}cb_sta;


/**
 * @brief adds an data item to circular buffer
 * 
 * This function adds an data passed to data buffer of circular buffer, 
 * appropriate circular buffer is passed in argument as a pointer
 * The ptrhead pointer is incremented an also the count of data items
 *
 * @returns enumeration that specifies success or eror
 */
cb_sta CB_buffer_add_item(cb_t *cb, uint8_t data);


/**
 * @brief this removes an data item from circualr buffer 
 * 
 * This function removes data from data buffer of circular buffer, 
 * appropriate circular buffer is passed in argument as a pointer
 * data removed  is copied into a variable
 * The ptrtail pointer is incremented an also the count of data items is decremented
 *
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_buffer_remove_item(cb_t *cb, uint8_t *var);



/**
 * @brief this checks if the buffer is filled to its max length
 * 
 * This function checks if data buffer is filled to its maximum 
 * this is done to check if it can be added more by add item function.
 * 
 *
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_is_full(cb_t *cb);


/**
 * @brief this checks if the buffer is empty
 * 
 * This function checks if data buffer of circular buffer passed  
 * as pointer to be empty . This is done to check for remove function
 * to remove elements
 *
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_is_empty(cb_t *cb);


/**
 * @brief this fucntion peeks into particular buffer for an element
 * 
 *This fucntion uses a pointer to get particualr circ buffer and  
 *element position that is to looked into.
 * the element specified is copied into a pointer variable.
 * 
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_peek(cb_t *cb, uint8_t pos, uint8_t *peekptr);


/**
 * @brief this fucntion is made for initialisation of circular buffer
 * 
 * This fucntion initialises the circular buffer by dynamically 
 *allocating the required memory by taking the size parameter
 * This initialises required variables for circ buffer to operate
 * 
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_init(cb_t *cb , uint8_t length);


/**
 * @brief this fucntion is used to free the memory allocated for circ buffer
 * 
 * This funation frees up the memory allocated in heap which
 * would be availale for further allocation
 * 
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_destroy(cb_t *cb);

void test_allocate_free_set();
void test_add_remove();
void test_buf_ptr_valid();
void test_buf_alloc_valid();
void test_wrap_add();
void test_wrap_remove();
void test_CB_overempty();
void test_CB_overfill() ;
void test_CB_Buffer_Full() ;
void test_CB_Buffer_Empty() ;
 


#endif
 
