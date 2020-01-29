//========================================================================
// map-spoly-basic-tests
//========================================================================
// This file contains basic tests for Map<Key,Value>

#include <unordered_map>

#include "utst.h"
#include "map-spoly.h"

int main() {

  UTST_BEGIN();

  //------------------------------------------------------------------------
  // Basic Tests
  //------------------------------------------------------------------------
  // These are simple test cases to check that the most basic functionality
  // works correctly.
  //
  // Do not add any additional tests here.

  UTST_TEST_LABEL( "Basic: Constructor" );

  {
    Map< int, int > my_map;

    // Assert that the my_map is actually empty

    UTST_ASSERT_TRUE( my_map.begin() == my_map.end() );
  }

  UTST_TEST_LABEL( "Basic: insert and at functions" );

  {
    Map< int, int > my_map;

    // Insert unique key-value pairs

    my_map.insert( 0, 10 );
    my_map.insert( 1, 11 );
    my_map.insert( 2, 12 );
    my_map.insert( 3, 13 );
    my_map.insert( 4, 14 );

    // Check if the inserted pairs exist

    UTST_ASSERT_TRUE( my_map.at( 0 ) == 10 );
    UTST_ASSERT_TRUE( my_map.at( 1 ) == 11 );
    UTST_ASSERT_TRUE( my_map.at( 2 ) == 12 );
    UTST_ASSERT_TRUE( my_map.at( 3 ) == 13 );
    UTST_ASSERT_TRUE( my_map.at( 4 ) == 14 );
  }

  UTST_TEST_LABEL( "Basic: iterator" );

  {
    Map< int, int > my_map;

    my_map.insert( 0, 10 );
    my_map.insert( 1, 11 );
    my_map.insert( 2, 12 );
    my_map.insert( 3, 13 );
    my_map.insert( 4, 14 );

    // Construct a reference map using C++ standard unordered_map class

    std::unordered_map< int, int > ref_map;

    // Add the same pairs to ref_map

    ref_map[ 0 ] = 10;
    ref_map[ 1 ] = 11;
    ref_map[ 2 ] = 12;
    ref_map[ 3 ] = 13;
    ref_map[ 4 ] = 14;

    // The following loop tests basic functions of MapIObject::Itr class

    auto itr = my_map.begin();

    // Testing operator !=

    while ( itr != my_map.end() ) {

      // Testing operator<: Assert that itr is less than my_map.end

      UTST_ASSERT_TRUE( itr < my_map.end() );

      // Testing operator*: Dererence the iterator to get a reference to
      // a pair

      Pair< int, int >& my_pair = *itr;

      // Get key and value from the pair

      int my_key   = my_pair.key  ;
      int my_value = my_pair.value;

      // Check if my_key exists in the ref_map

      UTST_ASSERT_TRUE( ref_map.count( my_key ) == 1 );

      // Check if my_value matches the copy in ref_map

      UTST_ASSERT_TRUE( ref_map[ my_key ] == my_value );

      // Testing operator++: Increment itr

      ++itr;
    }
  }

  UTST_END();

  return 0;
}
