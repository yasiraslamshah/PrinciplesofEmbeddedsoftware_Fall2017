
#include "memory.h"

#include <math.h>


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "conversion.h"


//TO CHECK FOR NULL POINTER CASE
void test_memmove_invalid_pointers() 
{
  enum test_status status = TEST_SUCCEED;
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrb;
  uint8_t * ptrc;
   ptra = &set[0];
  ptrb = &set[0];
  ptrc=my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  if (! ptrc )
  {
     status= TEST_ERROR_INVALID_POINTERS;;
  }

  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
  }

//TO CHECK FOR NULL POINTER CASE
void test_memcpy_invalid_pointers()
{ 
  enum test_status status = TEST_SUCCEED;
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrb;
   ptra = &set[0];
  ptrb = &set[0];
  uint8_t * ptrc;
 ptrc= my_memcpy(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  if (! ptrc )
  {
     status= TEST_ERROR_INVALID_POINTERS;;
  }

  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}
//TO CHECK FOR NULL POINTER CASE

void test_memzero_invalid_pointers()
{ 
  enum test_status status = TEST_SUCCEED;
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrc;
   ptra = &set[0];
  ptrc=my_memzero(ptra,TEST_MEMMOVE_LENGTH);
  if (! ptrc )
  {
     status= TEST_ERROR_INVALID_POINTERS;;
  }

  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

//TO CHECK FOR NULL POINTER CASE
void test_reverse_invalid_pointers()
{ 
  enum test_status status = TEST_SUCCEED;
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrc;
   ptra = &set[0];
  ptrc=my_reverse(ptra,TEST_MEMMOVE_LENGTH);
  if (! ptrc )
  {
     status= TEST_ERROR_INVALID_POINTERS;;
  }

  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

//TO CHECK FOR OVERLAP CASE
void test_memmove_no_overlap() {
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  printf("test_memmove1() - NO OVERLAP\n");
  set = (uint8_t*) reserve_words( MEM_SET_SIZE_W );

  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }

  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 16] != i)
    {
      status = TEST_ERROR;
    }
  }
   assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)set );
}

//TO CHECK THE CONDITION OF SRC OVERLAPPING DST
void test_memmove_src_in_dst() {
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  printf("test_memmove() -OVERLAP END OF SRC BEGINNING OF DST\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);
  ptra = &set[0];
  ptrb = &set[8];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }


  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
 

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 8] != i)
    {
       status = TEST_ERROR;
    }
  }
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)set );
  
}
//TO CHECK THE CONDITION OF DST OVERLAPPING SRC

void test_memmove_dst_in_src() {
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
 
  set = (uint8_t*)reserve_words( MEM_SET_SIZE_W);

  ptra = &set[8];
  ptrb = &set[0];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }


  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);


  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i] != (i + 8))
    {
      status = TEST_ERROR;
    }
  }

  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)set );
  

}

//TO CHECK WHETHER MEMCPY IS WORKING FINE OR NOT

void test_memcpy_check_set() {
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  printf("test_memcpy()\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }


  my_memcpy(ptra, ptrb, TEST_MEMMOVE_LENGTH);


  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i+16] != i)
    {
      status = TEST_ERROR;
    }
  }
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)set );
}

//TO CHECK WHETHER MEMZER0 IS WORKING FINE OR NOT
void test_memzero_check_set()
{
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * set;
  uint8_t * ptra;
  printf("test_memzero()\n");
  set = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  ptra = &set[0];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }
  my_memzero(ptra, MEM_ZERO_LENGTH);
 /* Validate Set & Zero Functionality */
  for (i = 0; i < MEM_ZERO_LENGTH; i++)
  {
    if (set[i] != 0)
    {
      status = TEST_ERROR;
    }
  }
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)set );
}

//TO CHECK WHETHER REVERSE IS WORKING FINE OR NOT FOR EVEN NUMBERS
void test_reverse_even_check_set()
{
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * copy;
  uint8_t set[MEM_SET_SIZE_B] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68, 0x54
                               };
  printf("test_reverse()\n");
  copy = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! copy )
  {
    status=TEST_ERROR_INVALID_POINTERS;
  }

  my_memcpy(set, copy, MEM_SET_SIZE_B);


  my_reverse(set, MEM_SET_SIZE_B);

  for (i = 0; i < MEM_SET_SIZE_B; i++)
  {
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1])
    {
      status = TEST_ERROR;
    }
  }
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)copy );
}

//TO CHECK WHETHER REVERSE IS WORKING FINE OR NOT FOR ODD NUMBERS
void test_reverse_odd_check_set()
{
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * copy;
  uint8_t set[31] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68
                               };
  printf("test_reverse()\n");
  copy = (uint8_t*)reserve_words(31);
  if (! copy )
  {
    status=TEST_ERROR_INVALID_POINTERS;
  }

  my_memcpy(set, copy, 31);


  my_reverse(set, 31);

  for (i = 0; i < 31; i++)
  {
    if (set[i] != copy[31 - i - 1])
    {
      status = TEST_ERROR;
    }
  }
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)copy );
}

//TO CHECK WHETHER REVERSE IS WORKING FINE OR NOT FOR CHARACTERS
void test_reverse_character_check_set()
{
  uint8_t i;
  enum test_status status = TEST_SUCCEED;
  uint8_t * copy;
  uint8_t set[32] = {'a', 'b', 'c', 'd', 'e','f', 'g','h',
                                 'i','j','k','l','m','n','o','p',
                                'q','r','s','t','u','v','w','x',
                                'y','z','a','b','c','d','e','f'
                               };
  printf("test_reverse()\n");
  copy = (uint8_t*)reserve_words(32);
  if (! copy )
  {
    status=TEST_ERROR_INVALID_POINTERS;
  }

  my_memcpy(set, copy, MEM_SET_SIZE_B);


  my_reverse(set, MEM_SET_SIZE_B);

  for (i = 0; i < MEM_SET_SIZE_B; i++)
  {
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1])
    {
      status = TEST_ERROR;
    }
  }
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)copy );
}





/*int main(int argc ,char ** argv)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_memmove_invalid_pointers),
    cmocka_unit_test(test_memcpy_invalid_pointers),
    cmocka_unit_test(test_memzero_invalid_pointers),
    cmocka_unit_test(test_reverse_invalid_pointers),
    cmocka_unit_test(test_memmove_no_overlap),
    cmocka_unit_test(test_memmove_src_in_dst),
    cmocka_unit_test(test_memmove_dst_in_src),
    cmocka_unit_test(test_memcpy_check_set),
    cmocka_unit_test(test_memzero_check_set),
     cmocka_unit_test(test_reverse_even_check_set),
     cmocka_unit_test(test_reverse_odd_check_set),
     cmocka_unit_test(test_reverse_character_check_set),
     cmocka_unit_test(test_little_to_big32_invalid_pointers),
    cmocka_unit_test(test_big_to_little32_invalid_pointers),
    cmocka_unit_test(test_big_to_little32_check_set),
    cmocka_unit_test(test_little_to_big32_check_set),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
*/
