//========================================================================
// hrs-knn-kdtree.cc
//========================================================================
// Handwriting recognition system member function definitions

#include "hrs-knn-kdtree.h"
#include <array>
#include <cassert>
#include <cfloat>
#include <cmath>

//========================================================================
// HandwritingRecSysKnnKdTree
//========================================================================
//------------------------------------------------------------------------
// train
//------------------------------------------------------------------------

void HandwritingRecSysKnnKdTree::train( const std::vector<LabeledImage>& v )
{
  // Save the training data

  m_training_set = v;

  // Build the kdtree from the training data

  m_kdtree.build( m_training_set.begin(), m_training_set.end() );
}

//------------------------------------------------------------------------
// classify
//------------------------------------------------------------------------

Label HandwritingRecSysKnnKdTree::classify( const Image& image )
{
  // This handwriting recognition system classifies images with two steps:
  //
  // 1. Use the k-d tree to "zoom in" on a small partition with very few
  //    points.
  //
  // 2. Run a brute force knn on this small subset to find the nearest
  //    neighbor.

  // Step 1. Search the tree with the input image. We also declare a
  // "v_neighbors" vector and pass it into the k-d tree search. The k-d
  // tree will fill the vector with a small subset of potential neighbors.

  // Note: The k-d tree is built to search for labeled images and not
  // regular unlabeled images. We create a dummy labeled image from the
  // regular image and use it to walk the k-d tree.

  LabeledImage              dummy_labeled_image( image, Label::INVALID );
  std::vector<LabeledImage> v_neighbors;

  m_kdtree.search( dummy_labeled_image, v_neighbors );

  // Step 2. Now do a brute force search on the "v_neighbors" vector.

  return knn( image, v_neighbors );
}

//------------------------------------------------------------------------
// euclidian_dist
//------------------------------------------------------------------------

double euclidian_dist( const Image& image_ref, const Image& image_comp, size_t size ) {
  // total distance
  int total = 0;
  // loop through each position in the matrix
  for( size_t i = 0; i < size; i++ ) {
      // get value of reference difference
      int diff = image_ref[i] - image_comp[i];
      // square difference between values
      int diff_sq = diff * diff;
      // add difference squared to total
      total += diff_sq;
  }
  // take the square root of all squared distances and return
  return std::sqrt( (double) total );
  
}

//----------------------------------------------------------------------
// knn
//----------------------------------------------------------------------
// Brute force k-nearest neighbors across the given vector of labeled
// images. Returns the label of the exact nearest neighbor.

Label HandwritingRecSysKnnKdTree::knn( const Image& image,
                         std::vector<LabeledImage>& v_neighbors )
{
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // This function executes brute-force k-nearest neighbors just as in the
  // HandwritingRecSysKnnBruteForce class. However, we no longer need to
  // search the entire training set "m_training_set" because the k-d tree
  // has provided a much smaller subset of nearby LabeledImage's.
  //
  // Copy your brute-force k-nearest neighbors solution and make light
  // adaptations so that it searches over the input vector "v_neighbors"
  // instead of over the entire "m_training_set".
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    // get size of training data
  size_t neighbors_size = v_neighbors.size();
  // if no training data, cannot label so return invalid label
  if ( neighbors_size == 0 ) return Label( Label::INVALID );
  // variable to store closest image
  LabeledImage closest;
  // variable to hold distance between ref and closest image
  double closest_dist = DBL_MAX;
  // loop through training data
  for( size_t i = 0; i < neighbors_size; i++ ) {
    // take distance of reference image and current image in training set
    double distance = euclidian_dist( image, v_neighbors[i].get_image(), image_size );
    // if distance between ref and new image is less than ref and closest
    if( distance < closest_dist ) {
      // set new closest distance
      closest_dist = distance;
      // set new closest image
      closest = v_neighbors[i];
    }
  }
  // return label of closest image from training set
  return closest.get_label();
}

