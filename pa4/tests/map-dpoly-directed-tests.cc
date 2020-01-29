//========================================================================
// map-dpoly-directed-tests
//========================================================================
// This file contains directed tests for MapIObject

#include <iostream>
#include <cstdlib>
#include <unordered_map>

#include "utils.h"
#include "utst.h"
#include "map-dpoly.h"

int main() {

  UTST_BEGIN();
  
  UTST_TEST_LABEL( "Insert key-value pairs with different types" ); 
  {
    
    MapIObject my_map;
    // Integer and Integer
    my_map.insert( Integer( 0 ), Integer( -10 ) );
    my_map.insert( Integer( 1 ), Integer( -11 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Integer( 0 ) ) == Integer( -10 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 1 ) ) == Integer( -11 ) );
    // Integer and Double
    my_map.insert( Integer( 0 ), Double( -10.2 ) );
    my_map.insert( Integer( 1 ), Double( 23.2 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Integer( 0 ) ) == Double( -10.2 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 1 ) ) == Double( 23.2 ) );
    // Integer and Complex
    my_map.insert( Integer( 3 ), Complex( 13.1 , 17.2 ) );
    my_map.insert( Integer( 4 ), Complex( 14.3 , 100.1 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Integer( 3 ) ) == 
                                  Complex( 13.1 , 17.2 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 4 ) ) == 
                                  Complex( 14.3 , 100.1 ) );
    // Integer and IpAddress
    my_map.insert( Integer( 100 ), IpAddress( 10 , 20 , 30 , 40 ) );
    my_map.insert( Integer( 111 ), IpAddress( 11 , 22 , 33 , 44 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Integer( 100 ) ) == 
                                  IpAddress( 10 , 20 , 30 , 40 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 111 ) ) == 
                                  IpAddress( 11 , 22 , 33 , 44 ) );
    // Integer and ShortString
    my_map.insert( Integer( 3 ), ShortString( "h" ) );
    my_map.insert( Integer( 4 ), ShortString( "e" ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Integer( 3 ) ) == 
                                  ShortString( "h" ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 4 ) ) == 
                                  ShortString( "e" ) );
    // Integer and RoutingInfo
    my_map.insert( Integer( 0 ), RoutingInfo( 
                                  IpAddress( 10 , 20 , 30, 40 ) , 100 ) );
    my_map.insert( Integer( 1 ), RoutingInfo( 
                                  IpAddress( 11 , 22 , 33, 44 ) , 10 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Integer( 0 ) ) == 
                    RoutingInfo( IpAddress( 10 , 20 , 30, 40 ) , 100 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 1 ) ) == 
                    RoutingInfo( IpAddress( 11 , 22 , 33, 44 ) , 10 ) );
    // Double and Integer
    my_map.insert( Double( 3.3 ), Integer( 13 ) );
    my_map.insert( Double( 4.4 ), Integer( 14 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Double( 3.3 ) ) == Integer( 13 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 4.4 ) ) == Integer( 14 ) );
    // Double and Double
    my_map.insert( Double( 1.2 ), Double( -67.9 ) );
    my_map.insert( Double( 27.56 ), Double( -582.23 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Double( 1.2 ) ) == Double( -67.9 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 27.56 ) ) == Double( -582.23 ) );
    // Double and Complex
    my_map.insert( Double( 0.5 ), Complex( 10.2 , 2.1 ) );
    my_map.insert( Double( 10.2 ), Complex( 11.1 , 90.2 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Double( 0.5 ) ) == 
                                  Complex( 10.2 , 2.1 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 10.2 ) ) == 
                                  Complex( 11.1 , 90.2 ) );
    // Double and IpAddress
    my_map.insert( Double( 1.1 ), IpAddress( 13 , 14 , 15 , 16 ) );
    my_map.insert( Double( -96.5 ), IpAddress( 31 , 41 , 51 , 61 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Double( 1.1 ) ) == 
                                  IpAddress( 13 , 14 , 15 , 16 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( -96.5 ) ) == 
                                  IpAddress( 31 , 41 , 51 , 61 ) );
    // Double and ShortString
    my_map.insert( Double( 0.1 ), ShortString( "hello" ) );
    my_map.insert( Double( 0.2 ), ShortString( "yellow" ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Double( 0.1 ) ) == 
                                  ShortString( "hello" ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 0.2 ) ) == 
                                  ShortString( "yellow" ) );
    // Double and RoutingInfo
    my_map.insert( Double( 3.3 ), RoutingInfo( 
                                  IpAddress( 10 , 20 , 30, 40 ) , 100 ) );
    my_map.insert( Double( 4.4 ), RoutingInfo( 
                                  IpAddress( 20 , 40 , 60, 80 ) , 57 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Double( 3.3 ) ) == 
                    RoutingInfo( IpAddress( 10 , 20 , 30, 40 ) , 100 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 4.4 ) ) == 
                    RoutingInfo( IpAddress( 20 , 40 , 60, 80 ) , 57 ) );
    // Complex and Integer
    my_map.insert( Complex( 0.0 , 0.0 ), Integer( 10 ) );
    my_map.insert( Complex( 1.0 , 2.0 ), Integer( 11 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Complex( 0.0 , 0.0 ) ) == 
                                  Integer( 10 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( 1.0 , 2.0 ) ) == 
                                  Integer( 11 ) );
    // Complex and Double
    my_map.insert( Complex( 3.3 , 20.1 ), Double( 13.13 ) );
    my_map.insert( Complex( 4.4 , 4.4 ), Double( 14.14 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Complex( 3.3 , 20.1 ) ) == 
                                  Double( 13.13 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( 4.4 , 4.4 ) ) == 
                                  Double( 14.14 ) );
    // Complex and Complex
    my_map.insert( Complex( -1.2 , 2.3 ), Complex( 2.2 , -19.11 ) );
    my_map.insert( Complex( 3.4 , -4.5 ), Complex( -21.21 , 32.19 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Complex( -1.2 , 2.3 ) ) == 
                                  Complex( 2.2 , -19.11 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( 3.4 , -4.5 ) ) == 
                                  Complex( -21.21 , 32.19 ) );
    // Complex and IpAddress
    my_map.insert( Complex( 0.0 , 1.0 ), IpAddress( 10 , 13 , 16, 19 ) );
    my_map.insert( Complex( 1.1 , 2.2 ), IpAddress( 11 , 14 , 17, 20 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Complex( 0.0 , 1.0 ) ) == 
                                  IpAddress( 10 , 13 , 16, 19 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( 1.1 , 2.2 ) ) == 
                                  IpAddress( 11 , 14 , 17, 20 ) );
    // Complex and ShortString
    my_map.insert( Complex( 3.3 , -7.9 ), ShortString( "0" ) );
    my_map.insert( Complex( -4.0 , 0.0 ), ShortString( "1" ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Complex( 3.3 , -7.9 ) ) == 
                                  ShortString( "0" ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( -4.0 , 0.0 ) ) == 
                                  ShortString( "1" ) );
    // Complex and RoutingInfo
    my_map.insert( Complex( 0.0 , 0.0 ),
                    RoutingInfo( IpAddress( 10 , 20 , 30, 40 ) , 100 ) );
    my_map.insert( Complex( 1.0 , 0.0 ), 
                    RoutingInfo( IpAddress( 20 , 40 , 60, 80 ) , 57 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( Complex( 0.0 , 0.0 ) ) == 
                    RoutingInfo( IpAddress( 10 , 20 , 30, 40 ) , 100 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( 1.0 , 0.0 ) ) == 
                    RoutingInfo( IpAddress( 20 , 40 , 60, 80 ) , 57 ) );
    // IpAddress and Integer
    my_map.insert( IpAddress( 10 , 20 , 30, 40 ), Integer( 13 ) );
    my_map.insert( IpAddress( 20 , 40 , 60, 80 ), Integer( 14 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 10 , 20 , 30, 40 ) ) == 
                                  Integer( 13 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 20 , 40 , 60, 80 ) ) == 
                                  Integer( 14 ) );
    // IpAddress and Double
    my_map.insert( IpAddress( 1 , 2 , 3, 4 ), Double( 10.1 ) );
    my_map.insert( IpAddress( 0 , 4 , 6, 8 ), Double( 11.2 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 1 , 2 , 3, 4 ) ) == 
                                  Double( 10.1 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 0 , 4 , 6, 8 ) ) == 
                                  Double( 11.2 ) );
    // IpAddress and Complex
    my_map.insert( IpAddress( 3 , 6 , 9 , 12 ), Complex( 0.0 , 1.0 ) );
    my_map.insert( IpAddress( 0 , 3 , 6 , 9 ), Complex( 10.0 , 100.0 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 3 , 6 , 9 , 12 ) ) == 
                                  Complex( 0.0 , 1.0 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 0 , 3 , 6 , 9 ) ) == 
                                  Complex( 10.0 , 100.0 ) );
    // IpAddress and IpAddress
    my_map.insert( IpAddress( 0 , 1 , 2 , 3 ), 
                    IpAddress( 4 , 5 , 6 , 7 ) );
    my_map.insert( IpAddress( 45 , 67 , 21 , 50 ), 
                    IpAddress( 11 , 12 , 14 , 16 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 0 , 1 , 2 , 3 ) ) == 
                                  IpAddress( 4 , 5 , 6 , 7 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 45 , 67 , 21 , 50 ) ) == 
                                  IpAddress( 11 , 12 , 14 , 16 ) );
    // IpAddress and ShortString
    my_map.insert( IpAddress( 2 , 4 , 6 , 8 ), ShortString( "yes" ) );
    my_map.insert( IpAddress( 3 , 4 , 5 , 6 ), ShortString( "no" ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 2 , 4 , 6 , 8 ) ) == 
                                  ShortString( "yes" ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 3 , 4 , 5 , 6 ) ) == 
                                  ShortString( "no" ) );
    // IpAddress and RoutingInfo
    my_map.insert( IpAddress( 1 , 10 , 1 , 10 ), 
                    RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 11 ) );
    my_map.insert( IpAddress( 20 , 21 , 22 , 23 ), 
                    RoutingInfo( IpAddress( 20 , 21 , 22 , 23 ) , 12 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 1 , 10 , 1 , 10 ) ) == 
                    RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 11 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 20 , 21 , 22 , 23 ) ) == 
                    RoutingInfo( IpAddress( 20 , 21 , 22 , 23 ) , 12 ) );
    // ShortString and Integer
    my_map.insert( ShortString( "10" ), Integer( 10 ) );
    my_map.insert( ShortString( "11" ), Integer( 11 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( ShortString( "10" ) ) == Integer( 10 ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "11" ) ) == Integer( 11 ) );
    // ShortString and Double
    my_map.insert( ShortString( "1" ), Double( 0.0 ) );
    my_map.insert( ShortString( "2" ), Double( 0.5 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( ShortString( "1" ) ) == Double( 0.0 ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "2" ) ) == Double( 0.5 ) );
    // ShortString and Complex
    my_map.insert( ShortString( "a" ), Complex( 0.0 , 0.0 ) );
    my_map.insert( ShortString( "b" ), Complex( 0.0 , 1.0 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( ShortString( "a" ) ) == 
                                  Complex( 0.0 , 0.0 ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "b" ) ) == 
                                  Complex( 0.0 , 1.0 ) );
    // ShortString and IpAddress
    my_map.insert( ShortString( "D" ), IpAddress( 0 , 0 , 0 , 0 ) );
    my_map.insert( ShortString( "E" ), IpAddress( 1 , 1 , 1 , 1 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( ShortString( "D" ) ) == 
                                  IpAddress( 0 , 0 , 0 , 0 ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "E" ) ) == 
                                  IpAddress( 1 , 1 , 1 , 1 ) );
    // ShortString and ShortString
    my_map.insert( ShortString( "hello" ), ShortString( "world" ) );
    my_map.insert( ShortString( "ece" ), ShortString( "2400" ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( ShortString( "hello" ) ) == 
                                  ShortString( "world" ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "ece" ) ) == 
                                  ShortString( "2400" ) );
    // ShortString and RoutingInfo
    my_map.insert( ShortString( "x" ), 
                    RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 10 ) );
    my_map.insert( ShortString( "y" ), 
                    RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 11 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( ShortString( "x" ) ) == 
                      RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 10 ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "y" ) ) == 
                      RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 11 ) );
    // RoutingInfo and Integer
    my_map.insert( RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 10 ), 
                    Integer( 13 ) );
    my_map.insert( RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 11 ), 
                    Integer( 13 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( 
    RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 10 ) ) == Integer( 13 ) );
    UTST_ASSERT_TRUE( my_map.at( 
    RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 11 ) ) == Integer( 13 ) );
    // RoutingInfo and Double
    my_map.insert( RoutingInfo( IpAddress( 10 , 10 , 10 , 10 ) , 100 ), 
                    Double( 11.1 ) );
    my_map.insert( RoutingInfo( IpAddress( 1 , 1 , 1 , 1 ) , 1 ), 
                    Double( 12.2 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 10 , 10 , 10 , 10 ) , 100 ) ) == Double( 11.1 ) );
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 1 , 1 , 1 , 1 ) , 1 ) ) == Double( 12.2 ) );
    // RoutingInfo and Complex
    my_map.insert( RoutingInfo( IpAddress( 99 , 98 , 97 , 96 ) , 95 ), 
                    Complex( 0.0 , 0.0 ) );
    my_map.insert( RoutingInfo( IpAddress( 94 , 93 , 92 , 91 ) , 90 ), 
                    Complex( 11.0 , 1.0 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 99 , 98 , 97 , 96 ) , 95 ) ) == Complex( 0.0 , 0.0 ) );
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 94 , 93 , 92 , 91 ) , 90 ) ) == Complex( 11.0 , 1.0 ) );
    // RoutingInfo and IpAddress
    my_map.insert( RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 5 ), IpAddress( 1 , 10 , 10 , 1 ) );
    my_map.insert( RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 6 ), IpAddress( 1 , 2 , 3 , 4 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 1 , 10 , 1 , 10 ) , 5 ) ) == IpAddress( 1, 10, 10, 1 ) );
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 1 , 10 , 1 , 10 ) , 6 ) ) == IpAddress( 1, 2, 3, 4 ) );
    // RoutingInfo and ShortString
    my_map.insert( RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 33 ), 
                    ShortString( "X" ) );
    my_map.insert( RoutingInfo( IpAddress( 1 , 10 , 1 , 10 ) , 44 ), 
                    ShortString( "Y" ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 1 , 10 , 1 , 10 ) , 33 ) ) == ShortString( "X" ) );
    UTST_ASSERT_TRUE( my_map.at( RoutingInfo( 
      IpAddress( 1 , 10 , 1 , 10 ) , 44 ) ) == ShortString( "Y" ) );
    // RoutingInfo and RoutingInfo
    my_map.insert( RoutingInfo( IpAddress( 19 , 29 , 39 , 49 ) , 59 ), 
                    RoutingInfo( IpAddress( 18 , 28 , 38 , 48 ) , 58 ) );
    my_map.insert( RoutingInfo( IpAddress( 17 , 27 , 37 , 47 ) , 57 ), 
                    RoutingInfo( IpAddress( 16 , 26 , 36 , 46 ) , 56 ) );
    // check for pairs
    UTST_ASSERT_TRUE( my_map.at( 
      RoutingInfo( IpAddress( 19 , 29 , 39 , 49 ) , 59 ) ) == 
        RoutingInfo( IpAddress( 18 , 28 , 38 , 48 ) , 58 ) );
    UTST_ASSERT_TRUE( my_map.at( 
      RoutingInfo( IpAddress( 17 , 27 , 37 , 47 ) , 57 ) ) == 
          RoutingInfo( IpAddress( 16 , 26 , 36 , 46 ) , 56 ) );
  }
  UTST_TEST_LABEL( "Inserting on existing keys" );
  {
    MapIObject my_map;
    // existing Integer
    my_map.insert( Integer( 0 ), Integer( -10 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 0 ) ) == Integer( -10 ) );
    my_map.insert( Integer( 0 ), Integer( -11 ) );
    UTST_ASSERT_TRUE( my_map.at( Integer( 0 ) ) == Integer( -11 ) );
    // existing Double
    my_map.insert( Double( 1.2 ), Double( -67.9 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 1.2 ) ) == Double( -67.9 ) );
    my_map.insert( Double( 1.2 ), Double( -582.23 ) );
    UTST_ASSERT_TRUE( my_map.at( Double( 1.2 ) ) == Double( -582.23 ) )
    // existing Complex
    my_map.insert( Complex( -1.2 , 2.3 ), Complex( 2.2 , -19.11 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( -1.2 , 2.3 ) ) == 
                                  Complex( 2.2 , -19.11 ) );
    my_map.insert( Complex( -1.2 , 2.3 ), Complex( -21.21 , 32.19 ) );
    UTST_ASSERT_TRUE( my_map.at( Complex( -1.2 , 2.3 ) ) == 
                                  Complex( -21.21 , 32.19 ) );
    // existing IpAddress
    my_map.insert( IpAddress( 0 , 1 , 2 , 3 ), 
                    IpAddress( 4 , 5 , 6 , 7 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 0 , 1 , 2 , 3 ) ) == 
                                  IpAddress( 4 , 5 , 6 , 7 ) );
    my_map.insert( IpAddress( 0 , 1 , 2 , 3 ), 
                    IpAddress( 11 , 12 , 14 , 16 ) );
    UTST_ASSERT_TRUE( my_map.at( IpAddress( 0 , 1 , 2 , 3 ) ) == 
                                  IpAddress( 11 , 12 , 14 , 16 ) );
    // existing ShortString
    my_map.insert( ShortString( "hello" ), ShortString( "world" ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "hello" ) ) == 
                                  ShortString( "world" ) );
    my_map.insert( ShortString( "hello" ), ShortString( "2400" ) );
    UTST_ASSERT_TRUE( my_map.at( ShortString( "hello" ) ) == 
                                  ShortString( "2400" ) );
    // existing RoutingInfo
    my_map.insert( RoutingInfo( IpAddress( 19 , 29 , 39 , 49 ) , 59 ), 
                    RoutingInfo( IpAddress( 18 , 28 , 38 , 48 ) , 58 ) );
    UTST_ASSERT_TRUE( my_map.at( 
      RoutingInfo( IpAddress( 19 , 29 , 39 , 49 ) , 59 ) ) == 
        RoutingInfo( IpAddress( 18 , 28 , 38 , 48 ) , 58 ) );
    my_map.insert( RoutingInfo( IpAddress( 17 , 27 , 37 , 47 ) , 57 ), 
                    RoutingInfo( IpAddress( 16 , 26 , 36 , 46 ) , 56 ) );
    UTST_ASSERT_TRUE( my_map.at( 
      RoutingInfo( IpAddress( 17 , 27 , 37 , 47 ) , 57 ) ) == 
          RoutingInfo( IpAddress( 16 , 26 , 36 , 46 ) , 56 ) );
  }
  UTST_TEST_LABEL( "Test Itr" ); 
  {
    MapIObject my_map;
    // add elements
    UTST_ASSERT_TRUE( my_map.begin() == my_map.end() );
    my_map.insert( Integer( 0 ), Integer( 10 ) );
    UTST_ASSERT_TRUE( my_map.begin() != my_map.end() );
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

  UTST_TEST_LABEL( "Test exception handling" );
  {
    MapIObject my_map;
     int i = 0;
     bool error = false;
     while ( i < 10 ) {
      try {
        my_map.at( Integer( 0 ) );
        error = false;
      }
      catch ( OutOfRangeException& e ) {
        error = true;
      }
      UTST_ASSERT_TRUE( error );
      i++;
     }
  } 
  
  UTST_TEST_LABEL( "Test all values to left_tree" );
  {
    MapIObject my_map;
    my_map.insert( Integer( 10 ), Integer( 10 ) );
    my_map.insert( Integer( 9 ), Integer( 9 ) );
    my_map.insert( Integer( 8 ), Integer( 8 ) );
    my_map.insert( Integer( 7 ), Integer( 7 ) );
    my_map.insert( Integer( 6 ), Integer( 6 ) );
    
    int current = 10;
    while( current != 5 ) {
      UTST_ASSERT_TRUE( my_map.at( Integer( current ) ) == Integer( current ) );
      current--;
    }
      
  }
  
  UTST_TEST_LABEL( "Test all values to right_tree" );
  {
    MapIObject my_map;
    my_map.insert( Integer( 6 ), Integer( 6 ) );
    my_map.insert( Integer( 7 ), Integer( 7 ) );
    my_map.insert( Integer( 8 ), Integer( 8 ) );
    my_map.insert( Integer( 9 ), Integer( 9 ) );
    my_map.insert( Integer( 10 ), Integer( 10 ) );
    
    int current = 10;
    while( current != 5 ) {
      UTST_ASSERT_TRUE( my_map.at( Integer( current ) ) == Integer( current ) );
      current--;
    }
      
  }
  
  UTST_TEST_LABEL( "Test all values to left and right trees" );
  {
    MapIObject my_map;
    my_map.insert( Integer( 8 ), Integer( 8 ) );
    my_map.insert( Integer( 7 ), Integer( 7 ) );
    my_map.insert( Integer( 10 ), Integer( 10 ) );
    my_map.insert( Integer( 9 ), Integer( 9 ) );
    my_map.insert( Integer( 6 ), Integer( 6 ) );
    
    int current = 10;
    while( current != 5 ) {
      UTST_ASSERT_TRUE( my_map.at( Integer( current ) ) == Integer( current ) );
      current--;
    }
      
  }
  
  UTST_TEST_LABEL( "testing iterator" );
  {
    MapIObject my_map;
    my_map.insert( Integer( 8 ), Integer( 8 ) );
    my_map.insert( Integer( 7 ), Integer( 7 ) );
    my_map.insert( Integer( 10 ), Integer( 10 ) );
    my_map.insert( Integer( 9 ), Integer( 9 ) );
    my_map.insert( Integer( 6 ), Integer( 6 ) );
    
    auto itr_s = my_map.begin();
    auto itr_e = my_map.end();
    UTST_ASSERT_TRUE( itr_s != itr_e );
    UTST_ASSERT_TRUE( !(itr_s == itr_e) );
    ++itr_s;
    ++itr_s;
    ++itr_s;
    UTST_ASSERT_TRUE( itr_s < itr_e );
    UTST_ASSERT_TRUE( !(itr_e < itr_s) );
    ++itr_s;
    ++itr_s;
    UTST_ASSERT_TRUE( itr_s == itr_e );
  }
  
  UTST_END();

  return 0;
}
