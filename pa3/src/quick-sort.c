//========================================================================
// quick-sort.c
//========================================================================
// Implementation of the quick sort function

#include "quick-sort.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>
//------------------------------------------------------------------------
// quick sort helper functions are in utils.c as they are also used in the
// pseudo radix sort
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// quick_sort
//------------------------------------------------------------------------
// Sorts the array with quick sort

void quick_sort( int arr[], size_t size )
{
  // call recursive sort
  quick_recur ( arr, 0, size);
}

