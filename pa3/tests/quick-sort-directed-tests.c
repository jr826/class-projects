//========================================================================
// quick-sort-directed-tests.c
//========================================================================
// This file contains the tests for the quick sort function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utst.h"
#include "quick-sort.h"
#include "utils.h"

int main() {

  UTST_BEGIN();

  // empty array
  UTST_TEST_LABEL( "Testing empty array" );
  {
    size_t size      = 0;
    int    arr[size];
    int    arr_ref[size];

    // Call sort
    quick_sort( arr, size );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size; i++ )
      UTST_ASSERT_INT_EQ( arr[i], arr_ref[i] );
  }
  
  // array of 1 element
  UTST_TEST_LABEL( "Testing array of 1 element" );
  {
    size_t size      = 1;
    int    arr[]     = {1};
    int    arr_ref[] = {1};

    // Call sort
    quick_sort( arr, size );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size; i++ )
      UTST_ASSERT_INT_EQ( arr[i], arr_ref[i] );
  
      size_t size1      = 1;
      int    arr1[]     = {100};
      int    arr_ref1[] = {100};

      // Call sort
      quick_sort( arr1, size1 );

      // Verify by comparing the array contents
      for ( size_t i = 0; i < size1; i++ )
        UTST_ASSERT_INT_EQ( arr1[i], arr_ref1[i] );
  
  }
  
  // already sorted array
  UTST_TEST_LABEL( "Already sorted array" );
  {
    size_t size      = 5;
    int    arr[]     = {1, 2, 3, 4, 5};
    int    arr_ref[] = {1, 2, 3, 4, 5};

    // Call sort
    quick_sort( arr, size );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size; i++ )
      UTST_ASSERT_INT_EQ( arr[i], arr_ref[i] );          
  
    size_t size1      = 10;
    int    arr1[]     = {1, 2, 3, 4, 5, 10, 15, 20, 25, 30};
    int    arr_ref1[] = {1, 2, 3, 4, 5, 10, 15, 20, 25, 30};

    // Call sort
    quick_sort( arr1, size1 );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size1; i++ )
      UTST_ASSERT_INT_EQ( arr1[i], arr_ref1[i] );
  
    size_t size2      = 3;
    int    arr2[]     = {1, 3, 5};
    int    arr_ref2[] = {1, 3, 5};

    // Call sort
    quick_sort( arr2, size2 );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size2; i++ )
      UTST_ASSERT_INT_EQ( arr2[i], arr_ref2[i] );
  }
  
  // array with duplicates
  UTST_TEST_LABEL( "Array with duplicates" );
  {
    size_t size      = 5;
    int    arr[]     = {1, 5, 3, 5, 5};
    int    arr_ref[] = {1, 3, 5, 5, 5};

    // Call sort
    quick_sort( arr, size );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size; i++ )
      UTST_ASSERT_INT_EQ( arr[i], arr_ref[i] );
      
    size_t size1      = 8;
    int    arr1[]     = {100, 20, 35, 20, 9999, 58, 35, 57};
    int    arr_ref1[] = {20, 20, 35, 35, 57, 58, 100, 9999};

    // Call sort
    quick_sort( arr1, size1 );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size1; i++ )
      UTST_ASSERT_INT_EQ( arr1[i], arr_ref1[i] );
      
    size_t size2      = 20;
    int    arr2[]     = {10000, 1000, 5, 0, 1, 1, 50, 500, 10000, 10000, 
                        1000, 100, 10, 100, 10, 5000, 100, 1, 10, 1000};
    int    arr_ref2[] = {0, 1, 1, 1, 5, 10, 10, 10, 50, 100, 100, 100, 500, 
                        1000, 1000, 1000, 5000, 10000, 10000, 10000};

    // Call sort
    quick_sort( arr2, size2 );

    // Verify by comparing the array contents
    for ( size_t i = 0; i < size2; i++ )
      UTST_ASSERT_INT_EQ( arr2[i], arr_ref2[i] );
  }

  UTST_END();

  return 0;
}
