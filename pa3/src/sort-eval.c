//========================================================================
// sort-eval.c
//========================================================================
// This program evalutes the performance of each function by running for
// multiple trials and averaging the elapsed run times.

#include "selection-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "radix-sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

//------------------------------------------------------------------------
// Input dataset
//------------------------------------------------------------------------

#include "sort.dat"

//------------------------------------------------------------------------
// Timing function
//------------------------------------------------------------------------


double time_me( int ntrials,
                char sort_name[], void (*sort)( int[], size_t ),
                char arr_name[], const int arr_size, int arr[], int arr_ref[] )
{

  printf( "\n" );
  printf( "---------------------------------------------------------\n" );
  printf( "'%s' sort with '%s' dataset of size %d\n", sort_name,
                                                      arr_name,
                                                      arr_size );
  printf( "---------------------------------------------------------\n" );
  printf( "\n" );

  // Create a buffer for the in-place sort

  int* arr_buffer = malloc( arr_size * sizeof(int) );

  // Run the experiment and track time using gettimeofday()

  double elapsed_avg = 0.0;

  for ( int i = 0; i < ntrials; i++ ) {

    // Track time using timers

    struct timeval start;
    struct timeval end;

    // Copy the input array into the buffer for the in-place sort

    memcpy( arr_buffer, arr, arr_size * sizeof(int) );

    // Start tracking time

    gettimeofday( &start, NULL );

    // Run for at least a few hundred microseconds to avoid precision issues

    sort( arr_buffer, arr_size );

    // Stop tracking time

    gettimeofday( &end, NULL );

    // Calculate elapsed time

    double elapsed = ( end.tv_sec - start.tv_sec ) +
                   ( ( end.tv_usec - start.tv_usec ) / 1000000.0 );

    elapsed_avg += elapsed;

    printf( "Elapsed time for trial %d is %f\n", i, elapsed );
  }

  // Calculate average elapsed time per trial

  elapsed_avg = elapsed_avg / ntrials;

  printf( "\n" );
  printf( "Elapsed time (averaged) is %f\n", elapsed_avg );

  // Verify the results

  if ( memcmp( arr_buffer, arr_ref, arr_size * sizeof(int) ) != 0 ) {
    printf( "Error: Dataset '%s' was not sorted correctly with %s!\n",
        arr_name, sort_name );
    return 1;
  }

  // Verify the results

  printf("Verification passed\n");
  printf( "\n" );

  return elapsed_avg;
}

//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------

int main( void )
{
  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so that the total runtime of the trial is at
  // least a few seconds. This avoids precision issues with
  // gettimeofday().

  int ntrials    = 5;

  //......................................................................
  // Sort metadata
  //......................................................................

  typedef void (*sortfunc_t)( int[], size_t );

  enum sorts {
    SELECTION,
    MERGE,
    QUICK,
    RADIX,
    NUM_SORTS
  };

  char* sort_names[NUM_SORTS];
  sort_names[SELECTION] = "Selection";
  sort_names[MERGE]     = "Merge";
  sort_names[QUICK]     = "Quick";
  sort_names[RADIX]     = "Radix";

  sortfunc_t sort_funcs[NUM_SORTS];
  sort_funcs[SELECTION] = &selection_sort;
  sort_funcs[MERGE]     = &merge_sort;
  sort_funcs[QUICK]     = &quick_sort;
  sort_funcs[RADIX]     = &radix_sort;

  //......................................................................
  // Input metadata
  //......................................................................

  enum inputs {
    REVERSED,
    ALMOST_SORTED,
    FEW_UNIQUE,
    RANDOM,
    RANDOM_X5,
    RANDOM_X10,
    NUM_INPUTS
  };

  char* arr_names[NUM_INPUTS];
  arr_names[RANDOM_X10]    = "Random-x10";
  arr_names[RANDOM_X5]     = "Random-x5";
  arr_names[RANDOM]        = "Random";
  arr_names[REVERSED]      = "Reversed";
  arr_names[ALMOST_SORTED] = "Almost Sorted";
  arr_names[FEW_UNIQUE]    = "Few Unique";

  int arr_sizes[NUM_INPUTS];
  arr_sizes[RANDOM_X10]    = size_x10;
  arr_sizes[RANDOM_X5]     = size_x5;
  arr_sizes[RANDOM]        = size;
  arr_sizes[REVERSED]      = size;
  arr_sizes[ALMOST_SORTED] = size;
  arr_sizes[FEW_UNIQUE]    = size;

  int* arrs[NUM_INPUTS];
  arrs[RANDOM_X10]    = arr_random_x10;
  arrs[RANDOM_X5]     = arr_random_x5;
  arrs[RANDOM]        = arr_random;
  arrs[REVERSED]      = arr_reversed;
  arrs[ALMOST_SORTED] = arr_almost_sorted;
  arrs[FEW_UNIQUE]    = arr_few_unique;

  int* arr_refs[NUM_INPUTS];
  arr_refs[RANDOM_X10]    = arr_random_x10_ref;
  arr_refs[RANDOM_X5]     = arr_random_x5_ref;
  arr_refs[RANDOM]        = arr_random_ref;
  arr_refs[REVERSED]      = arr_reversed_ref;
  arr_refs[ALMOST_SORTED] = arr_almost_sorted_ref;
  arr_refs[FEW_UNIQUE]    = arr_few_unique_ref;

  //......................................................................
  // Run the evaluation
  //......................................................................
  // Run the evaluation on each sort function with each input. Verify
  // the results against the reference. Return the average elapsed time.

  double data[NUM_SORTS][NUM_INPUTS];

  for ( int i = 0; i < NUM_SORTS; i++ )
    for ( int j = 0; j < NUM_INPUTS; j++ )
      data[i][j] = time_me( ntrials,
                            sort_names[i], sort_funcs[i],
                            arr_names[j], arr_sizes[j], arrs[j], arr_refs[j] );

  //......................................................................
  // Summary table (raw numbers)
  //......................................................................

  printf( "\n" );
  printf( "========================================" );
  printf( "========================================\n" );
  printf( "Summary Table: Raw data\n" );
  printf( "========================================" );
  printf( "========================================\n" );
  printf( "Time in seconds to sort an array of length %d\n", size );
  printf( "\n" );

  // Header strip

  printf( "%15s | ", "" );

  for ( int i = 0; i < NUM_SORTS; i++ )
    printf( "%10s  ", sort_names[i] );

  printf( "\n" );
  printf( "----------------------------------------" );
  printf( "----------------------------------------" );
  printf( "\n" );

  // Print data for each input

  for ( int i = 0; i < NUM_INPUTS; i++ ) {
    printf( "%15s | ", arr_names[i] );
    for ( int j = 0; j < NUM_SORTS; j++ )
      printf( "%10.4f  ", data[j][i] );
    printf( "\n" );
  }
  printf( "\n" );

//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return 0;
}
