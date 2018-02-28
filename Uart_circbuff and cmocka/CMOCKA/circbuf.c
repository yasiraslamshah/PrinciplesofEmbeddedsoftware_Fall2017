#include"malloc.h"
#include"circbuf.h"
#include <stdint.h>





//extern cb_t *ptra;
//extern cb_t *ptr_rx;


cb_sta CB_buffer_add_item(cb_t *cb, uint8_t data){
	//cb_sta code;
	cb_sta a ;
	a = CB_is_full(cb);
	if (a == bufferfull)
	return error;
	*(cb->ptrhead) = data; 
	if(cb->ptrhead == ( cb->buffptr + ((cb->size-1) * sizeof(uint8_t))))
	cb->ptrhead = cb->buffptr;
	else
	cb->ptrhead = cb->ptrhead + sizeof(uint8_t);
	cb->count++;
	return success;
}

cb_sta CB_buffer_remove_item(cb_t *cb, uint8_t *var)
{
	//cb_sta code;

	cb_sta a ;
	a = CB_is_empty (cb);
	if (a == bufferempty)
	return error;
	*var = *(cb->ptrtail) ;
	*(cb->ptrtail) = 0;
	if(cb->ptrtail == ( cb->buffptr + ((cb->size-1)*sizeof(uint8_t))))
	cb->ptrtail = cb->buffptr;	
	else
	cb->ptrtail = cb->ptrtail +sizeof(uint8_t);
	cb->count--;
	return success ;
}

/*<CB enum type> CB_is_full(<buffer to check>);
*1. The function will take in the circular buffer to check if it is full
*2. The function returns the status of the circular buffer or an error code
*/
cb_sta CB_is_full(cb_t * cb)
{
	if (cb->count == cb->size)
	return bufferfull ;
	else
	return error;
}





/*<CB enum type> CB_is_empty(<buffer to check>);
*1. The function will take in the circular buffer to check if it is empty
*2. The function returns the status of the circular buffer or an error codes
*/
cb_sta CB_is_empty(cb_t *cb)
{
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
	if (pos > (cb->size)){
	pos = cb->size - pos;
}
	
	cb->ptrhead = (cb->ptrhead +(pos * sizeof(uint8_t)));
	*peekptr = *(cb->ptrhead);
	return success;
}



/*<CB enum type> CB_init(<pointer of buffer type>, <length of buffer>);
1. The function will take 2 arguments:
a. Pointer to the circular buffer
b. The length/size to be reserved for the buffer
2. The function returns the status of the circular buffer or an error codes
*/

cb_sta CB_init(cb_t *cb,uint8_t length)
{
	//len = length ;
	cb->buffptr = (uint8_t*)malloc(length) ;
	if(cb->buffptr == NULL)	
	return error;
	cb->size = length;
	cb->count = 0;
	cb->ptrhead = cb->buffptr;
	cb->ptrtail = cb->buffptr;
	return success;
}



/*<CB enum type> CB_destroy(<pointer of buffer type>);
1. The functions takes in the buffer to be destroyed
2. The function returns the status of the circular buffer or an error codes
*/

cb_sta CB_destroy(cb_t *cb){
	if(cb == NULL)
	return error;
	else
	free(cb->buffptr);
	cb->count = 0;
	return success;
}







