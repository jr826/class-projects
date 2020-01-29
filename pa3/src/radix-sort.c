//========================================================================
// radix-sort.c
//========================================================================
// Implementation of the radix sort function

#include "radix-sort.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <limits.h>

//------------------------------------------------------------------------
// get_digit_at
//------------------------------------------------------------------------
// Inputs
//    - number: input number
//    - pos   : position of the target digit. The least significant digit
//              has position 0
//    - radix : the base/radix in which the number is represented
//
// Output
//    - Value of the digit at position "pos" in the representation of "number"
//    in radix/base of "radix"
//
// For example,
//
//  - get_digit_at( 249, 1, 10 ) = 4
//
//    The digit at position 2 in the representation of number 249 in the
//    radix of 10 is 2
//
//  - get_digit_at( 10, 3, 2  ) = 1
//
//    The digit at position 3 in the representation of number 10 in the
//    radix of 2 (i.e., number 10 in binary is 1010) is 1
//

size_t get_digit_at( int number, size_t pos, int radix ) {
  return ( pos == 0 ) ?
              (size_t) number % radix :
              (size_t) ( number / (size_t) pow( radix, pos ) ) % radix;
}

//------------------------------------------------------------------------
// radix_help
//------------------------------------------------------------------------
void radix_help ( int arr[], size_t pos, size_t begin, size_t end ) 
{ 
  // hold start of bin
  size_t hold = 0;
  // R values
  size_t r = 0;
  // iterator to put values in bins, hold end of bin
  size_t itr = begin;
  // move through array
  while (itr < end && r < 10 ) {
    for ( size_t i = begin; i < end; i++ ) {
      // if in current bin
      if ( get_digit_at( arr[i], pos, 10 ) == r ) {
        // move forward in array
        swap( arr, i, itr );
        itr++;  
      }  
    }
    // sort bin
    quick_recur( arr, hold, itr);
    // set new start of bin
    hold = itr;
    // check next bin
    r++;
  }
}

//------------------------------------------------------------------------
// radix_sort
//------------------------------------------------------------------------
// Sorts the array with radix sort
// Uses R = 10 and K = 5
void radix_sort( int arr[], size_t size )
{
  // call helper to sort by k
  radix_help( arr, 4, 0, size );
}
