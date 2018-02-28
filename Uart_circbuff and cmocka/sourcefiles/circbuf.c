/*
 * circbuf.c
 *
 *  Created on: Oct 26, 2017
 *      Author: Gautham
 */




#include "malloc.h"
#include "circbuf.h"



state CB_init(cb_t *cb,uint8_t length)
{
	cb_t->ptrhead = (cb_t*)malloc(sizeof(cb_t));
	cb_t->buffptr = (char*)malloc(length * sizeof(char));
	if(cb->buffptr == NULL)	
	return error;	
	cb->length = length;
	cb->count = 0;
	cb->ptrhead = cb->buffptr;
	cb->ptrtail = cb->buffptr;
	return success;
}


cb_sta CB_buffer_add_item(cb_t *cb, uint8_t data){
	uint8_t a ;
	a = CB_is_full(*cb);
	if (a == bufferfull) 
	return error;
	*(cb->ptrhead) = data; 
	if(cb->ptrhead == buffptr + (length*sizeof(uint32_t))
	cb->ptrhead = cb->buffptr;
	else
	cb->ptrhead = cb->ptrhead + sizeof(uint32_t);
	cb->count++;
	return success;
}

cb_sta CB_buffer_remove_item(cb_t *cb, uint8_t *var){
	uint8_t  a ;
	a = CB_is_empty(*cb);
	if (a == bufferempty) 
	return error;
	var = *(cb->ptrtail) ;
	*(cb->ptrtail) = 0;
	if(cb->ptrtail == buffptr + (length*sizeof(uint32_t))
	cb->ptrtail = cb->buffptr;	
	else
	cb->ptrtail = cb->ptrtail +sizeof(uint32_t);
	cb->count--;
	return success ;
}

/*<CB enum type> CB_is_full(<buffer to check>);
*1. The function will take in the circular buffer to check if it is full
*2. The function returns the status of the circular buffer or an error code
*/
cb_sta CB_is_full(cb_t *cb){
	if (cb->count == length)
	return bufferfull ;
	else
	return error;
}





/*<CB enum type> CB_is_empty(<buffer to check>);
*1. The function will take in the circular buffer to check if it is empty
*2. The function returns the status of the circular buffer or an error codes
*/
cb_sta CB_is_empty(cb_t *cb){
	if(cb->count==0)
	return bufferempty;
	else
	return error;
}


/*<CB enum type> CB_peek(<buffer to peek into>, <position to peek>);

1. The function will take 2 arguments:
a. Pointer to the circular buffer to peek into
b. The position from the head of the buffer to peek into
2. The function returns the status of the circular buffer or an error code
3. Must take into consideration the corner cases possible
*/
cb_sta CB_peek(cb_t *cb, uint8_t pos, uint8_t *peekptr){
	if(cb->count==0)
	return bufferempty	;
	if (pos >cb->length){
	pos = cb->length - pos;
}
	
	cb->ptrhead = cb->ptrhead +(pos * sizeof(uint32_t);
	*peekptr = *(cb->ptrhead);
	return success;
}



/*<CB enum type> CB_init(<pointer of buffer type>, <length of buffer>);
1. The function will take 2 arguments:
a. Pointer to the circular buffer
b. The length/size to be reserved for the buffer
2. The function returns the status of the circular buffer or an error codes
*/




/*<CB enum type> CB_destroy(<pointer of buffer type>);
1. The functions takes in the buffer to be destroyed
2. The function returns the status of the circular buffer or an error codes
*/

cb_sta CB_destroy(cb_t *cb){
	if(cb_t *cb == NULL)
	return error;
	else
	free(cb->bufferptr);
	cb->count = 0;
	return success;
}







