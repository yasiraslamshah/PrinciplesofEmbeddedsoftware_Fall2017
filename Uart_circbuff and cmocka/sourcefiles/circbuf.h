/**
 * @file circbuf.h 
 * @brief This file is to be used to project 2.
 *
 * @author Gautham
 * @date Oct 24, 2017
 *
 */
#ifndef __circbuf_H__
#define __circbuf_H__

typedef struct circ {
	char * buffptr;
	uint8_t length;
	struct node *ptrhead;
	struct node *ptrtail;
	uint8_t count;
}cb_t;

typedef enum cb_sta{
	bufferfull,
	bufferempty,
	success,
	error
}state;


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
cb_sta CB_init(uint8_t *cb , uint32_t length);


/**
 * @brief this fucntion is used to free the memory allocated for circ buffer
 * 
 * This funation frees up the memory allocated in heap which
 * would be availale for further allocation
 * 
 * @return returns enumeration that specifies success or eror
 */
cb_sta CB_destroy(cb_t *cb);

//cb_t tx_buff ,rx_buff ;

#endif
 
