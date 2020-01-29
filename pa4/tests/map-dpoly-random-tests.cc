//========================================================================
// map-dpoly-random-tests
//========================================================================
// This file contains random tests for MapIObject

#include <iostream>
#include <cstdlib>
#include <unordered_map>

#include "utils.h"
#include "utst.h"
#include "map-dpoly.h"

#define MAX 1000

int main() {

  UTST_BEGIN();
  //------------------------------------------------------------------------
  // Random Tests
  //------------------------------------------------------------------------
  // set random seed
  srand(99);
  
  UTST_TEST_LABEL( "Random tests with Integers, Doubles, Complex and IP" );
  {
    // construct map object
    MapIObject my_map;
    // assert map is empty
    UTST_ASSERT_TRUE( my_map.begin() == my_map.end() );
    // run 1000 tests using MAX define
    for ( size_t i = 0; i < MAX; i++ ) {
      // add Integers
      if ( i % 10 == 1 || i % 10 == 2 ) {
        // random Integer key
        int ki = rand() % MAX;
        // random Integer value
        int vi = rand() % MAX;
        // insert Key,Value pair to the map
        my_map.insert( Integer( ki ) , Integer( vi ) );
        // test pair was added properly
        UTST_ASSERT_TRUE( my_map.at( Integer( ki ) ) == Integer( vi ) );
      }
      // add Double
      else if ( i % 10 == 3 || i % 10 == 4 || i % 10 == 5 ) {
        // random Double key
        double kd = ( rand() % 100000 ) / MAX;
        // random Double value
        double vd = ( rand() % 100000 ) / MAX;
        // insert pair to map
        my_map.insert( Double( kd ) , Double( vd ) );
        // test pair was added properly
        UTST_ASSERT_TRUE( my_map.at( Double( kd ) ) == Double( vd ) );
      }
      // add Complex
      else if ( i % 10 == 6 || i % 10 == 7 ) {
        // random Complex key real and img
        double kc_r = ( rand() % 100000 ) / MAX;
        double kc_i = ( rand() % 100000 ) / MAX;
        // random Complex value real and img
        double vc_r = ( rand() % 100000 ) / MAX;
        double vc_i = ( rand() % 100000 ) / MAX;
        // insert pair to map
        my_map.insert( Complex( kc_r , kc_i ) , Complex( vc_r , vc_i ) );
        // test pair was added properly
        UTST_ASSERT_TRUE( my_map.at( Complex( kc_r , kc_i ) ) == 
                                    Complex( vc_r , vc_i ) );
      }
      // add IpAddress
      else {
        // random key ints
        int kip0 = rand() % MAX;
        int kip1 = rand() % MAX;
        int kip2 = rand() % MAX;
        int kip3 = rand() % MAX;
        // random value ints
        int vip0 = rand() % MAX;
        int vip1 = rand() % MAX;
        int vip2 = rand() % MAX;
        int vip3 = rand() % MAX;
        // insert pair to map
        my_map.insert( IpAddress( kip0 , kip1 , kip2 , kip3 ) , 
                      IpAddress( vip0 , vip1 , vip2 , vip3 ) );
        // test pair was added properly
        UTST_ASSERT_TRUE( my_map.at(IpAddress( kip0 , kip1 , kip2 , kip3 )) 
                          == IpAddress( vip0 , vip1 , vip2 , vip3 ) );
      }
    }
  }
  
  UTST_TEST_LABEL( "Adding random Integers to test tree structure" );
  {
    MapIObject my_map;
    for( int i = 0; i != 5000; i++ ) {
      int rand_int = rand() % 100000;
      my_map.insert( Integer( rand_int ), Integer( i ) );
      UTST_ASSERT_TRUE( my_map.at( Integer ( rand_int ) ) == Integer( i ) );
    }
  }

  UTST_END();

  return 0;
}
