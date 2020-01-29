//========================================================================
// merge-sort-basic-tests.c
//========================================================================
// This file contains the tests for the merge sort function

#include <stdio.h>
#include <stdlib.h>

#include "utst.h"
#include "merge-sort.h"
#include "utils.h"

int main() {

  UTST_BEGIN();

  //------------------------------------------------------------------------
  // Basic Tests
  //------------------------------------------------------------------------
  // These are simple test cases to check that the most basic functionality
  // works correctly.
  //
  // Do not add any additional tests here.

  //........................................................................
  // Basic merge sort
  //........................................................................

  UTST_TEST_LABEL( "Basic merge sort" );

  {
    size_t size      = 5;
    int    arr[]     = {1, 4, 3, 2, 5};
    int    arr_ref[] = {1, 2, 3, 4, 5};

    // Call sort

    merge_sort( arr, size );

    // Verify by comparing the array contents

    for ( size_t i = 0; i < size; i++ )
      UTST_ASSERT_INT_EQ( arr[i], arr_ref[i] );
  }

  UTST_END();

  return 0;
}
