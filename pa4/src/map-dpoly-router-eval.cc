//========================================================================
// map-dpoly-router-eval.cc
//========================================================================
// This program evalutes the performance of MapIOject by running for
// multiple trials and averaging the elapsed run times.

#include <cstdio>
#include <sys/time.h>

#include "utils.h"
#include "types-dpoly.h"
#include "map-dpoly.h"

//------------------------------------------------------------------------
// Input dataset
//------------------------------------------------------------------------

#include "router.dat"

//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------

int main( void )
{
  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so that the total runtime of the trial is at
  // least a few seconds. This avoids precision issues with
  // gettimeofday().

  size_t ntrials    = 5;
  size_t nsubtrials = 10;

  // Run the experiment and track time using gettimeofday()

  bool result[size_search];

  std::cout.precision(5);
  std::cout << std::fixed;

  double elapsed_insert_avg = 0.0;
  double elapsed_at_avg     = 0.0;
  double elapsed_avg        = 0.0;

  // Timing loop

  for ( size_t i = 0; i < ntrials; i++ ) {

    // Track time using timers

    struct timeval start;
    struct timeval middle;
    struct timeval end;

    // Start tracking time

    gettimeofday( &start, NULL );

    {
      // Fill the data structure

      MapIObject my_map;

      for ( size_t j = 0; j < size_data; j++ )
        my_map.insert( dest_ip_data_arr[ j ], routing_data_arr[ j ] );

      gettimeofday( &middle, NULL );

      // Run for at least a few hundred microseconds to avoid precision issues

      for ( size_t j = 0; j < nsubtrials; j++ ) {
        for ( size_t k = 0; k < size_search; k++ ) {
          try {
            dynamic_cast< RoutingInfo& >( my_map.at( dest_ip_search_arr[ k ] ) );
            result[ k ] = true;
          } catch ( const OutOfRangeException& e ) {
            result[ k ] = false;
          }
        }
      }
    }

    // Stop tracking time

    gettimeofday( &end, NULL );

    // Calculate elapsed time

    double elapsed_insert = ( middle.tv_sec - start.tv_sec ) +
                            ( ( middle.tv_usec - start.tv_usec ) / 1000000.0 );
    double elapsed_at     = ( end.tv_sec - middle.tv_sec ) +
                            ( ( end.tv_usec - middle.tv_usec ) / 1000000.0 );
    double elapsed        = ( end.tv_sec - start.tv_sec ) +
                            ( ( end.tv_usec - start.tv_usec ) / 1000000.0 );

    elapsed_insert_avg += elapsed_insert;
    elapsed_at_avg     += elapsed_at;
    elapsed_avg        += elapsed;

    std::cout << "Trial " << i << ": "
              << elapsed_insert << " (insert), "
              << elapsed_at     << " (at), "
              << elapsed        << " (total)"
              << std::endl;
  }

  // Calculate average elapsed time per trial

  elapsed_insert_avg  = elapsed_insert_avg / ntrials;
  elapsed_at_avg      = elapsed_at_avg / ntrials;
  elapsed_avg         = elapsed_avg / ntrials;

  std::cout << "Average: "
            << elapsed_insert_avg << " (insert), "
            << elapsed_at_avg     << " (at), "
            << elapsed_avg        << " (total)"
            << std::endl;

  // Verify the results
  for ( size_t i = 0; i < size_search; i++ ) {
    if ( result[ i ] != ref[ i ] ) {
      std::cout << "Error: Search for "     << dest_ip_search_arr[ i ]
                << " incorrect, found was " << result[ i ]
                << " but should be "        << ref[ i ]
                << std::endl;
      return 1;
    }
  }

  printf("Verification passed\n");

  return 0;
}
