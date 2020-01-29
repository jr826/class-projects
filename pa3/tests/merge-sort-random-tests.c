//========================================================================
// merge-sort-random-tests.c
//========================================================================
// This file contains the tests for the merge sort function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utst.h"
#include "merge-sort.h"
#include "utils.h"

int main() {

  UTST_BEGIN();
  // set random seed
  srand(99);
  // max input is 99,999, use 100,000 for modulus
  int max = 100000;
  
  for ( int i = 0; i < 100; i++ ) {
    // set array size, limited from 0 to 1000 elements
    size_t size = abs(rand() % 1000);
    int arr[size];
    // fill array with random values from 0 to 99,999
    for ( size_t i = 0; i < size; i++ ) {
        arr[i] = abs( rand() % max );
    }
    // create sorted reference array using stdlib qsort
    int arr_ref[size];
    for ( size_t i = 0; i < size; i++ ) {
        arr_ref[i] = arr[i];
    }
    qsort( arr_ref, size, sizeof(arr_ref[0]), compare );

    // Call sort
    merge_sort( arr, size );
    // Verify by comparing the array contents
    for ( size_t i = 0; i < size; i++ )
      UTST_ASSERT_INT_EQ( arr[i], arr_ref[i] );
  }
  
  UTST_END();

  return 0;
}
