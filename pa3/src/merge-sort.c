//========================================================================
// merge-sort.c
//========================================================================
// Implementation of the merge sort function

#include "merge-sort.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>

//------------------------------------------------------------------------
// merge
//------------------------------------------------------------------------
// Helper function. Merges two sorted input arrays into a new output.
// Adopted from topic 10 section 3.1.

void merge ( int out_arr[], int arr_a[], size_t begin_a, size_t end_a,
             int arr_b[], size_t begin_b, size_t end_b)
{
  // get size of out_arr
  size_t size = ( end_a - begin_a ) + ( end_b - begin_b ); 
  // set indexes
  size_t idxa = begin_a;
  size_t idxb = begin_b;
  //iterate through arrays
  for ( size_t i = 0; i < size; i++ ) {
    // check if done with a
    if ( idxa == end_a ) {
      // take values from b
      out_arr[i] = arr_b[idxb];
      idxb++;
    }
    // check if done with b
    else if ( idxb == end_b ) {
      // take values from a
      out_arr[i] = arr_a[idxa];
      idxa++;  
    }  
    // front of a is less than front of b
    else if ( arr_a[idxa] < arr_b[idxb] ) {
      // take value from a
      out_arr[i] = arr_a[idxa];
      idxa++;  
    }
    // front of b is less than front of a
    else {
      // take values from b
      out_arr[i] = arr_b[idxb];
      idxb++;
    }
  }
}

//------------------------------------------------------------------------
// merge_recur
//------------------------------------------------------------------------
// Helper function. Recursive function to handle merge sorting using 
// begin and end inputs. Adopted from topic 10 section 3.2.

void merge_recur ( int arr[] , size_t begin, size_t end ) 
{
  // get array size
  size_t size = end - begin;
  // base case
  if ( size <= 1 ) return;
  // get mid
  size_t mid = ( begin + end ) / 2;
  //recurse on each half
  merge_recur( arr, begin, mid );
  merge_recur( arr, mid, end );
  // create temp array of size
  int tmp[size];
  //merge values into temp array
  merge( tmp, arr, begin, mid, arr, mid, end );
  //copy temp array to input array
  int tmp_idx = 0;
  for ( size_t i = begin; i < end; i++ ) {
    arr[i] = tmp[tmp_idx];
    tmp_idx++;
  }
}

//------------------------------------------------------------------------
// merge_sort
//------------------------------------------------------------------------
// Sorts the array with merge sort

void merge_sort( int arr[], size_t size )
{
  // call recursive function
  merge_recur( arr, 0, size );
}

