//========================================================================
// selection-sort.c
//========================================================================
// Implementation of the selection sort function

#include "selection-sort.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>

//------------------------------------------------------------------------
// find_min 
//------------------------------------------------------------------------
// Helper function. Returns the index of the minimum value in the array
// Based on the pseudocode from Topic 10 section  2.1.
int find_min ( int arr[], size_t begin, size_t size ) 
{
    // store min_value and its index
    int min_value = arr[ (int) begin ];
    int min_idx = (int) begin;
    
    //iterate through array looking for min value
    for (size_t i = begin; i < size; i++ ) {
      // if value at current index is less than min value
      if ( arr[i] < min_value ) {
        // set new min value
        min_value = arr[i];
        // set new min idx
        min_idx = i;    
      }
    }
  return min_idx;  
}

//------------------------------------------------------------------------
// selection_sort
//------------------------------------------------------------------------
// Sorts the array with selection sort
// In place selection sort adopted from topic 10 section 2.3

void selection_sort( int arr[], size_t size )
{
  // iterate through array
  for ( size_t i = 0; i < size; i++ ) {
    // get index of min value
    size_t idx = find_min( arr, i, size);
    // swap min value with value at position i
    swap( arr, i, idx );
  }
}

