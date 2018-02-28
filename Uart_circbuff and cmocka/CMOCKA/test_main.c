#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "conversion.h"
#include "circbuf.h"

int main(void)
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
      cmocka_unit_test(test_big_to_little32_invalid_pointers),
    cmocka_unit_test(test_little_to_big32_invalid_pointers),
    cmocka_unit_test(test_big_to_little32_check_set),
    cmocka_unit_test(test_little_to_big32_check_set),
    cmocka_unit_test(test_allocate_free_set),
    cmocka_unit_test(test_add_remove),
    cmocka_unit_test(test_buf_ptr_valid),
    cmocka_unit_test(test_buf_alloc_valid),
    cmocka_unit_test(test_wrap_add),
    cmocka_unit_test(test_wrap_remove),
	cmocka_unit_test(test_CB_overempty),
	cmocka_unit_test(test_CB_overfill), 
	cmocka_unit_test(test_CB_Buffer_Full),
	cmocka_unit_test(test_CB_Buffer_Empty), 
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
