//========================================================================
// map-dpoly-basic-tests
//========================================================================
// This file contains the tests for MapIObject

#include <unordered_map>

#include "utst.h"
#include "map-dpoly.h"

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
    MapIObject my_map;

    // Assert that the my_map is actually empty

    UTST_ASSERT_TRUE( my_map.begin() == my_map.end() );
  }

  UTST_TEST_LABEL( "Basic: insert and at functions" );

  {
    MapIObject my_map;

    // Insert unique key-value pairs

    my_map.insert( Integer( 0 ), Integer( 10 ) );
    my_map.insert( Integer( 1 ), Integer( 11 ) );
    my_map.insert( Integer( 2 ), Integer( 12 ) );
    my_map.insert( Integer( 3 ), Integer( 13 ) );
    my_map.insert( Integer( 4 ), Integer( 14 ) );
    my_map.insert( Integer( 4 ), Integer( 15 ) );

    // Check if the inserted pairs exist
    
    UTST_ASSERT_TRUE( my_map.at( Integer( 0 ) ) == Integer( 10 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 1 ) ) == Integer( 11 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 2 ) ) == Integer( 12 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 3 ) ) == Integer( 13 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 4 ) ) == Integer( 15 ) );
  }

  UTST_TEST_LABEL( "Basic: iterator" );

  {
    MapIObject my_map;

    my_map.insert( Integer( 0 ), Integer( 10 ) );
    my_map.insert( Integer( 1 ), Integer( 11 ) );
    my_map.insert( Integer( 2 ), Integer( 12 ) );
    my_map.insert( Integer( 3 ), Integer( 13 ) );
    my_map.insert( Integer( 4 ), Integer( 15 ) );

    // Construct a reference map using C++ standard unordered_map class

    std::unordered_map< int, int > ref_map;

    // Add the same pairs to ref_map

    ref_map[ 0 ] = 10;
    ref_map[ 1 ] = 11;
    ref_map[ 2 ] = 12;
    ref_map[ 3 ] = 13;
    ref_map[ 4 ] = 15;

    // The following loop tests basic functions of MapIObject::Itr class

    auto itr = my_map.begin();

    // Testing operator !=

    while ( itr != my_map.end() ) {

      // Testing operator<: Assert that itr is less than my_map.end

      UTST_ASSERT_TRUE( itr < my_map.end() );

      // Testing operator*: Dererence the iterator to get a reference to
      // an IObject pair

      PairIObject& my_pair = *itr;

      // Get key and value from the pair

      Integer& my_key   = dynamic_cast<Integer&>( *( my_pair.key_p   ));
      Integer& my_value = dynamic_cast<Integer&>( *( my_pair.value_p ));

      // Check if my_key exists in the ref_map

      UTST_ASSERT_TRUE( ref_map.count( my_key.to_int() ) == 1 );

      // Check if my_value matches the copy in ref_map

      UTST_ASSERT_TRUE( ref_map[ my_key.to_int() ] == my_value.to_int() );

      // Testing operator++: Increment itr

      ++itr;
    }
  }

  UTST_END();

  return 0;
}
