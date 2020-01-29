//=========================================================================
// map-dpoly.h
//=========================================================================
// Declarations for PaiIObject and MapIObject

#ifndef MAP_DPOLY_H
#define MAP_DPOLY_H

#include "types-dpoly.h"

struct PairIObject {
  IObject* key_p;
  IObject* value_p;
};

class MapIObject
{
 public:
  MapIObject();
  ~MapIObject();

  // Iterator for this class

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // It is good practice to start simple and build up complexity.
  // Implement the simplest member functions first. We recommend you
  // commenting out iterator-related code. Once you verify MapIObject
  // functions that are not related to iterator, you implement this Itr
  // class.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  
  class Itr
  {
   public:
    // TASK: Replace XXXXXX with a list of necessary parameters to be
    //       used to initialize member fields of this Itr class
    Itr( size_t size, PairIObject* map_arr );

    void         operator++();
    PairIObject& operator* () const;
    bool         operator!=( const MapIObject::Itr& rhs ) const;
    bool         operator==( const MapIObject::Itr& rhs ) const;
    bool         operator< ( const MapIObject::Itr& rhs ) const;

   private:
    // TASK: Make a list of necessary member fields that this Itr class
    //       need to be able to iterate through a MapIObject object
    PairIObject* map_arr_itr;
    size_t size_itr;
  };
  // Iterator member functions

  Itr begin() const;
  Itr   end() const;
  
  
  // Other member functions

  IObject& at    ( const IObject& key );
  void     insert( const IObject& key, const IObject& value );

 private:
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Depending on your implementation of MapIObject, you decide what
  // member fields are necessary in your implementation.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  PairIObject* map_arr;
  size_t size;
  size_t maxsize;
  struct TreeNode {
    size_t index;
    struct TreeNode* left_tree;
    struct TreeNode* right_tree;
  };
  TreeNode* head_ptr;
  void free_tree(TreeNode* node);
  
};

#endif // MAP_DPOLY_H
