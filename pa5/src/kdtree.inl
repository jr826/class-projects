//========================================================================
// kdtree.inl
//========================================================================
// Definitions for kdtree (inlined)

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

//========================================================================
// KdTree::Node
//========================================================================
//========================================================================
// Constructors
//========================================================================

template <unsigned int K, typename T, typename Itr, typename V>
KdTree<K, T, Itr, V>::Node::Node()
  : m_left_p     ( nullptr ),
    m_right_p    ( nullptr ),
    m_is_leaf    ( false   ),
    m_data_start ( Itr()   ),
    m_data_end   ( Itr()   )
{}

template <unsigned int K, typename T, typename Itr, typename V>
KdTree<K, T, Itr, V>::Node::Node( Itr start, Itr end )
  : m_left_p     ( nullptr ),
    m_right_p    ( nullptr ),
    m_is_leaf    ( false   ),
    m_data_start ( start   ),
    m_data_end   ( end     )
{}

//========================================================================
// KdTree
//========================================================================
//------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
KdTree<K, T, Itr, V>::KdTree()
  : m_leaf_size (   250  ), // leaf node size
    m_root_p    ( nullptr )
{}

//------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
KdTree<K, T, Itr, V>::~KdTree()
{
  // loop through nodelist vector
  for ( unsigned int i = 0; i < m_nodelist.size(); i++ ) {
    // delete each element
    delete m_nodelist[i];
  }
}

//------------------------------------------------------------------------
// search
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
void KdTree<K, T, Itr, V>::search( T& item, std::vector<T>& v_data )
{
  // start at root of tree
  Node* curr_node = get_root();
  while( !(curr_node -> m_is_leaf) )
  {
    if ( item[curr_node->m_dim] <= curr_node->m_threshold ) {
      // go left
      curr_node = curr_node->m_left_p;
    }
    else {
      // go right
      curr_node = curr_node->m_right_p;
    }
  }

  // get start of node data
  Itr i = curr_node->m_data_start;
  // loop through node data
  while ( i != curr_node->m_data_end ) {
    // put node data in v_data
    v_data.push_back( *i );
    // increment itr
    ++i;
  }
  // done, so return
  return;
  
}

//------------------------------------------------------------------------
// build
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
inline void KdTree<K, T, Itr, V>::build( Itr start, Itr end )
{
  m_root_p = build_kernel( start, end );
}

//------------------------------------------------------------------------
// build_kernel
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
typename KdTree<K, T, Itr, V>::Node*
  KdTree<K, T, Itr, V>::build_kernel( Itr start, Itr end )
{
  unsigned int size = std::distance( start, end );

  // No elements
  if ( size == 0 ) return nullptr;
  // If the size is less than or equal to the leaf size
  if ( size <= m_leaf_size ) {
    // 1. Create a new Node
    Node* leaf_node = new Node( start , end );
    // Set the "m_is_leaf" field of the node to be true
    leaf_node->m_is_leaf = true;
    // Push back the node pointer into "m_nodelist" 
    m_nodelist.push_back( leaf_node );
    // Return the node pointer to complete the base case.
    return leaf_node;
  }
  // Create a new non-leaf node
  Node* new_node = new Node();
  // Push back the node pointer into "m_nodelist"
  m_nodelist.push_back( new_node );
  
  // Set the new non-leaf node's m_dim field using choose_dimension
  unsigned int dim = choose_dimension( start , end );
  new_node->m_dim = dim;
  // Call the partition function to partition the dataset
  Itr i = partition( start , end , dim ,  new_node );

  // 1. Call build_kernel on the left and right partitions
  // 2. Return the node pointer

  // left side
  Node* left = build_kernel( start , i );
  // right side
  Node* right = build_kernel( i , end );
  // update new_node
  new_node->m_left_p = left;
  new_node->m_right_p = right;
  return new_node;
}

//------------------------------------------------------------------------
// Choose one of K dimensions for partition
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
unsigned int KdTree<K, T, Itr, V>::choose_dimension( Itr start, Itr end )
{
  // Find a nice dimension to split along
  //
  // In particular, we don't want to choose a dimension where all elements
  // have the exact same value, because then there is no meaningful
  // partitioning.
  //
  // For example, in two dimensions, if all elements have the same x
  // position, then it is not meaningful to partition along the x axis:
  //
  //     4 |   x
  //     3 |   x
  //     2 |   x
  //     1 |   x
  //       +---------
  //         1 2 3 4
  //
  // In this situation, we should re-roll and choose another dimension to
  // partition along (e.g., the y axis).
  
  // get random dimension
  unsigned int dim = rand() % K;
  // boolean to check if all values same
  bool same = true;
  // iterate through values
  Itr ref = start;
  Itr i = start;
  while ( i != end && same ) {
    // compare values / position
    if ( (*ref)[dim] != (*i)[dim] ) {
      same = false; 
    }
    i++;
  }
  // if valid dimension, use
  if ( !same ) { 
    return dim;
  }
  // else, pick new dimension
  else {
    return choose_dimension( start , end );
  }
}

//------------------------------------------------------------------------
// Partition along the chosen dimension
//------------------------------------------------------------------------
// Partition the elements along the chosen dimension into a left partition
// and a right partition.

template <unsigned int K, typename T, typename Itr, typename V>
Itr KdTree<K, T, Itr, V>::partition( Itr          start,
                                     Itr          end,
                                     unsigned int dim,
                                     Node*        node_p )
{
  // sort elements based on value at chosen dimension
  std::sort( start , end , [dim] (T& i1, T& i2) 
  { return i1[dim] < i2[dim]; } );
  // get median
  int dist = std::distance(start, end);
  Itr med = start;
  for( int i = 0; i < dist; i = i + 2 ) 
    ++med;
  // get median value for threshold
  auto threshold = (*med)[dim];
  // partition around threshold
  Itr middle = std::partition( start , end , 
                             [&] (T& i) { return i[dim] <= threshold; } );
  // check if right partition is empty
  if ( middle == end ) {
    // choose new threshold
      threshold = (*start)[dim];
      middle = std::partition( start , end , 
                             [&] (T& i) { return i[dim] <= threshold; } );
    }
  // store final threshold in given node
  node_p->m_threshold = threshold;
  // return first element of right side partition
  return middle;
}

//------------------------------------------------------------------------
// set_leaf_size
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
void KdTree<K, T, Itr, V>::set_leaf_size( unsigned int leaf_size )
{
  m_leaf_size = leaf_size;
}

//------------------------------------------------------------------------
// get_root
//------------------------------------------------------------------------

template <unsigned int K, typename T, typename Itr, typename V>
typename KdTree<K, T, Itr, V>::Node*& KdTree<K, T, Itr, V>::get_root()
{
  return m_root_p;
}

