//========================================================================
// map-spoly.h
//========================================================================
// Declarations for Pair and Map

#ifndef MAP_SPOLY_H
#define MAP_SPOLY_H

#include "types-spoly.h"

template < typename Key, typename Value >
struct Pair {
  Key   key;
  Value value;
};

template < typename Key, typename Value >
class Map
{
 public:
  Map();
  ~Map();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // It is good practice to start simple and build up complexity.
  // Implement the simplest member functions first. We recommend you
  // commenting out iterator-related code. Once you verify Map<Key,Value>
  // functions that are not related to iterator, you implement this Itr
  // class.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  class Itr
  {
   public:
    // TASK: Replace XXXXXX with a list of necessary parameters to be
    //       used to initialize member fields of this Itr class
    Itr( XXXXXX );

    // Operator overloading
    void                operator++();
    Pair< Key, Value >& operator* () const;
    bool                operator!=( const Itr& rhs ) const;
    bool                operator==( const Itr& rhs ) const;
    bool                operator< ( const Itr& rhs ) const;

   private:
    // TASK: Make a list of necessary member fields that this Itr class
    //       need to be able to iterate through a Map<Key,Value> object
  };
  // Iterator member functions

  Itr begin() const;
  Itr   end() const;

  // Other member functions

  Value& at    ( const Key& key );
  void   insert( const Key& key, const Value& value );

 private:
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Depending on your implementation of Map<Key,Value>, you decide what
  // member fields are necessary in your implementation.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
};

// This file contains all template member function definitions

#include "map-spoly.inl"

#endif // MAP_SPOLY_H
