//========================================================================
// utils.c
//========================================================================
// Useful functions for arrays and sorting

#include "utils.h"
#include <stdio.h>

//------------------------------------------------------------------------
// print_array
//------------------------------------------------------------------------
// Prints the array contents

void print_array( int arr[], size_t size )
{
  if ( size > 0 ) printf( "%d", arr[0] );
  for ( size_t i = 1; i < size; i++ )
    printf( ", %d", arr[i] );
  printf( "\n" );
}

//------------------------------------------------------------------------
// swap
//------------------------------------------------------------------------
// Swap the values at two indices of an array

void swap( int arr[], size_t i, size_t j )
{
  int tmp = arr[i];
  arr[i]  = arr[j];
  arr[j]  = tmp;
}

//------------------------------------------------------------------------
// compare
//------------------------------------------------------------------------
// Compare two integers, returning 0 if equal, negative if a < b, and
// positive if a > b.
//
// This function is intended to be used with the standard library qsort().

int compare( const void* a_p, const void* b_p )
{
  int a = *(int*)a_p;
  int b = *(int*)b_p;

  if      ( a > 0 && b < 0 ) return  1;
  else if ( a < 0 && b > 0 ) return -1;
  else                       return ( a - b );
}

//------------------------------------------------------------------------
// partition
//------------------------------------------------------------------------
// Helper function. Uses a pivot to split the array into two partitions.
// Adopted from topic 10 section 4.1.

size_t partition( int arr[], size_t begin, size_t end )
{
  // set pivot to last value
  int pivot = arr[end-1];
  // start at first index of the array 
  size_t idx = begin;
  // iterate through array
  for ( size_t i = begin; i < end; i++ ) {
    // move values < pivot to front of array, >= pivot to the end
    if ( arr[i] <= pivot ) {
      swap( arr, i, idx);  
      idx++;
    }  
  } 
  return idx-1;
} 

//------------------------------------------------------------------------
// quick_recur
//------------------------------------------------------------------------
// Helper function. Recursively sorts the array in place.
//Adopted from topic 10 sectino 4.2.

void quick_recur ( int arr[], size_t begin, size_t end )
{
  // base case
  if ( begin >= end ) {
      return;
  }   
  // partition array around pivot p
  size_t p = partition( arr, begin, end );
  // recurse on both sides of pivot
  quick_recur( arr, begin, p);
  quick_recur( arr, p + 1, end ); 
}
