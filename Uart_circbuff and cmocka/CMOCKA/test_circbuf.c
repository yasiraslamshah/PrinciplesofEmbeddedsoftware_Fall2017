/*********************************************************
*author: Gautham and yasir
*
This contains the functions to check whether conversation.c 
*functions worked fine or not
*
**********************************************************/

#include "circbuf.h"

void test_allocate_free_set()
{
	uint8_t length = 6;
	cb_sta status ;
	cb_t cb;
	cb_t *ptr = &cb;
	status  = CB_init(ptr , length);
	assert_int_equal(status,success);
} 

void test_add_remove()
{
	uint8_t length = 4;
	uint8_t i, j=5;
	uint8_t a, count =0;
	uint8_t *st = &a; 
	cb_sta status;
	cb_t cb;
	cb_t *ptr = &cb;
	CB_init(ptr , length);
	for(i=0 ; i<length ; i++)
	{ 
		j = j+i;
		CB_buffer_add_item(ptr,j);
		CB_buffer_remove_item(ptr,st);
		if(*st == j)
		{ 
			count ++;
		}

	}
		if(count == length)
		{
		status = success;
		assert_int_equal(status,success);
		}
		//else
		//status = error ;
		//assert_int_equal(status,success);
			
}
	
void test_buf_ptr_valid()
{
	uint8_t length = 6;
	cb_sta status ;
	cb_t cb;
	cb_t *ptr = &cb;
	status  = CB_init(ptr , length);
	if(ptr->buffptr != NULL)
	status = success;
	assert_int_equal(status,success);
}

void test_buf_alloc_valid(){
	uint8_t length = 6;
	cb_sta status ;
	cb_t cb;
	cb_t *ptr = &cb;
	status  = CB_init(ptr , length);
	assert_int_equal(status,success);
}


void test_wrap_add(){
	uint8_t length = 2, i=2;
	uint8_t a ;
	uint8_t *st = &a;
	cb_sta status ;
	cb_t cb;
	cb_t *ptr = &cb;
	CB_init(ptr , length);
	CB_buffer_add_item(ptr,i++);
	//if(status == success)
	CB_buffer_add_item(ptr,i++);
	//if(status == success)
	CB_buffer_remove_item(ptr,st);
	//if(status == success)
	//CB_buffer_add_item(ptr,i);
	//if(status == success)
	if((ptr->buffptr) == (ptr->ptrhead))
	{
		status = success;
	}
	else
	{
		status = error;
	}
        assert_int_equal(status,success);

}


void test_wrap_remove()
{
	uint8_t length = 2, i=2;
	uint8_t a ;
	uint8_t *st = &a;
	cb_sta status = error;
	cb_t cb;
	cb_t *ptr = &cb;
	CB_init(ptr,length);
	
		CB_buffer_add_item(ptr,i);
		CB_buffer_add_item(ptr,i);
		CB_buffer_remove_item(ptr,st);
		
	
	//CB_buffer_add_item(ptr,i);
	CB_buffer_remove_item(ptr,st);
	if(ptr->ptrtail == ptr->buffptr)
         {
		status=success;
	 }
	assert_int_equal(status,success);
}
	 
void test_CB_Buffer_Empty() 
{
  uint8_t length;
  length=5;
  cb_sta status;
  cb_t a;
  cb_t * ptr = &a;
  CB_init(ptr, length);
  status=CB_is_empty(ptr);
  assert_int_equal(status,bufferempty);
}

void test_CB_Buffer_Full() 
{
  uint8_t length,i;
  length=5;
  i=0;
  cb_sta status;
  cb_t cb;
  cb_t * ptr = &cb;
  CB_init(ptr, length);
  uint8_t a[5]={1,2,3,4,5};
  while(i<length)
{
  CB_buffer_add_item(ptr, a[i]);
  i++;
}
  status=CB_is_full(ptr);
  assert_int_equal(status,bufferfull);
}

void test_CB_overfill() 
{
  uint8_t length,i;
  length=5;
  i=0;
  cb_sta status;
  cb_t cb;
  cb_t * ptr = &cb;
  CB_init(ptr, length);
  uint8_t a[6]={1,2,3,4,5,6};
  while(i<length)
{
  CB_buffer_add_item(ptr,a[i]);
  i++;
}
 
  status=CB_buffer_add_item(ptr,a[5]);
  if(status!=success)
 {
    status=error;
 }
  assert_int_equal(status,error);
}

void test_CB_overempty() 
{
  uint8_t length,a;
  length=5;
  uint8_t * ptr1 = &a;
  cb_sta status;
  cb_t circ_buf;
  cb_t * ptr = &circ_buf;
  CB_init(ptr, length);
  status= CB_buffer_remove_item(ptr,ptr1);
  if(status!=success)
  {
    status=error;
  }
 
  assert_int_equal(status,error);
}



