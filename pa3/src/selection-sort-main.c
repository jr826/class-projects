//========================================================================
// selection-sort-main.c
//========================================================================

#include <stdio.h>
#include <stdlib.h>

#include "selection-sort.h"
#include "utils.h"

int main() {

  size_t size      = 5;
  int    arr[]     = {1, 4, 3, 2, 5};

  // Print out arr before

  printf( "Before sorting: " );

  for ( size_t i = 0; i < size; i++ )
    printf( "%d ", arr[i] );

  printf( "\n" );

  // Call sort

  selection_sort( arr, size );

  // Print out arr after

  printf( "After sorting:  " );

  for ( size_t i = 0; i < size; i++ )
    printf( "%d ", arr[i] );

  printf( "\n" );

  return 0;
}
