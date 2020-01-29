//========================================================================
// map-dpoly.h
//========================================================================
// PairIObject and MapIObject function definitions

#include "utils.h"
#include "map-dpoly.h"
#include <cstdlib>
#include <cstring>

//========================================================================
// MapIObject
//========================================================================
//------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------
MapIObject::MapIObject() {
  map_arr = new PairIObject[4];
  size = 0;
  maxsize = 4;
  head_ptr = nullptr;
}

//------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------
MapIObject::~MapIObject() {
  for( size_t i = 0; i != size ; i++ ){
    delete( map_arr[i].key_p );
    delete( map_arr[i].value_p );
  }
  delete[] map_arr;
  free_tree ( head_ptr );
  size = 0;
  maxsize = 0;
  head_ptr = nullptr;
}

//------------------------------------------------------------------------
// Itr begin() and end()
//------------------------------------------------------------------------

MapIObject::Itr MapIObject::begin() const
{
  return MapIObject::Itr(0, map_arr);
}

MapIObject::Itr MapIObject::end() const
{
  return MapIObject::Itr(size, map_arr);
}

//------------------------------------------------------------------------
// at
//------------------------------------------------------------------------

IObject& MapIObject::at( const IObject& key )
{
  if ( head_ptr == nullptr ) throw OutOfRangeException("Value not found");
  // Start search at head_ptr ( top of tree )
  TreeNode* current_ptr = head_ptr;
  // loop until reach the bottom of tree
  while( current_ptr != nullptr ) 
  {
    // index in the map that the current tree node is associated with
    size_t curr_index = current_ptr -> index;
    // current key of the current tree node
    auto curr_key = map_arr[curr_index].key_p;
    // if equal to the given key, return the associated value
    if( (*curr_key).eq(key)) 
      return *(map_arr[curr_index].value_p);
    else {
      // set current_ptr to the left tree when the given value is less than 
      // the current key of the current tree node
      if( (*curr_key).lt(key) ) 
        current_ptr = current_ptr -> left_tree;
      // set current_ptr to the right tree when the given value is greater than 
      // the current key of the current tree node
      else
        current_ptr = current_ptr -> right_tree;
    }
  }
  // Value not found
  throw OutOfRangeException("Value not found");
}
  
//------------------------------------------------------------------------
// insert
//------------------------------------------------------------------------

void MapIObject::insert( const IObject& key, const IObject& value )
{
  // New Object
  PairIObject new_node;
  new_node.key_p = key.clone();
  new_node.value_p = value.clone();
  
  // When no values exist, make head_ptr iniitial tree
  if (head_ptr == nullptr) {
    map_arr[size] = new_node;
    TreeNode* new_tree = new TreeNode();
    new_tree -> index = 0;
    new_tree -> left_tree = nullptr;
    new_tree -> right_tree = nullptr;
    head_ptr = new_tree;
  }
  // When values exist
  else
  {
    // current tree node in while loop
    TreeNode* current_node = head_ptr;
    // previous node in for loop
    TreeNode* prev_node = nullptr;
    // bool to check if new node should be added to left or right subtree 
    // of the previous node
    bool lt = false;
    // Loop until you reach bottom of tree branch
    while( current_node != nullptr)
    {
      // index in the map that the current tree node is associated with
      size_t curr_index = current_node -> index;
      // key of the PairIObject associated with the index curr_index
      auto curr_key = map_arr[curr_index].key_p;
      // if the keys are equal, replace the current value with new value
      if( (*curr_key).eq(key))
      {
        // deallocate old value
        delete( map_arr[curr_index].value_p );
        // set new value
        map_arr[curr_index].value_p = new_node.value_p;
        // deallocate new nodes key
        delete( new_node.key_p );
        return;
      }
      // set next tree node to the left tree if the key is less than current 
      // key in the tree
      else if( (*curr_key).lt(key) )
      {
        prev_node = current_node;
        current_node = current_node -> left_tree;
        lt = true;
      }
      // set next tree node to the right tree if the key is greater than current 
      // key in the tree
      else
      {
        prev_node = current_node;
        current_node = current_node -> right_tree;
        lt = false;
      }
    }
    // if the maxsize is met, double the size of the map and copy all old values into new map
    if( size == maxsize ) 
    {
      PairIObject* new_map = new PairIObject[maxsize * 2];
      for( size_t i = 0; i != size; i++ )
      {
        new_map[i] = map_arr[i];
      }
      delete[] map_arr ;
      map_arr = new_map;
      maxsize *= 2;
    }
    // Create new tree node
    map_arr[size] = new_node;
    TreeNode* new_pair = new TreeNode;
    new_pair -> index = size;
    new_pair -> left_tree = nullptr;
    new_pair -> right_tree = nullptr;
    
    // Sets pointer to new node from the previous node
    if( lt ) 
      prev_node -> left_tree = new_pair;
    else
      prev_node -> right_tree = new_pair;
  }
  // increment the size
  size++;
}
//========================================================================
// MapIObject::Itr
//========================================================================

//------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------

MapIObject::Itr::Itr( size_t size, PairIObject* map_arr  )
{
  map_arr_itr = map_arr;
  size_itr = size;
}

//------------------------------------------------------------------------
// operator++
//------------------------------------------------------------------------

void MapIObject::Itr::operator++() 
{
  size_itr++;
}

//------------------------------------------------------------------------
// operator*
//------------------------------------------------------------------------

PairIObject& MapIObject::Itr::operator*() const
{
  return map_arr_itr[size_itr];
}
//------------------------------------------------------------------------
// operator==
//------------------------------------------------------------------------

bool MapIObject::Itr::operator==( const MapIObject::Itr& rhs ) const
{
  if ( size_itr == rhs.size_itr ) 
    return true;
  else
    return false;
}
//------------------------------------------------------------------------
// operator!=
//------------------------------------------------------------------------

bool MapIObject::Itr::operator!=( const MapIObject::Itr& rhs ) const
{
   if ( size_itr != rhs.size_itr ) 
    return true;
  else
    return false;
}
//------------------------------------------------------------------------
// operator<
//------------------------------------------------------------------------
bool MapIObject::Itr::operator< ( const MapIObject::Itr& rhs ) const
{
  if ( size_itr < rhs.size_itr ) 
    return true;
  else
    return false;
}

// Private variables
  PairIObject* map_arr;
  
  PairIObject* map_arr_itr;
  
  size_t size_itr;
  
  size_t size;
  
  size_t maxsize;
  
  struct TreeNode {
    size_t index;
    struct TreeNode* left_tree;
    struct TreeNode* right_tree;
  };
  
  TreeNode* head_ptr;
  
  void MapIObject::free_tree (TreeNode* node) {
    // do nothing if the current node is a nullptr
    if ( node == nullptr ) return;
    // get the left and right tree from the current node
    TreeNode* left_t = node -> left_tree;
    TreeNode* right_t = node -> right_tree;
    //delete the current node
    delete (node);
    // free the left and right subtrees
    free_tree( left_t );
    free_tree( right_t );
  }
