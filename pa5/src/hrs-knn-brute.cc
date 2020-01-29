//========================================================================
// hrs-knn-brute.cc
//========================================================================
// Handwriting recognition system member function definitions

#include "hrs-knn-brute.h"
#include <array>
#include <cmath>
#include <cassert>
#include <cfloat>

//========================================================================
// HandwritingRecSysKnnBruteForce
//========================================================================
//------------------------------------------------------------------------
// train
//------------------------------------------------------------------------

void HandwritingRecSysKnnBruteForce::train( const std::vector<LabeledImage>& v )
{
  m_training_set = v;
}

//------------------------------------------------------------------------
// classify
//------------------------------------------------------------------------

Label HandwritingRecSysKnnBruteForce::classify( const Image& image )
{
  return knn( image );
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

Label HandwritingRecSysKnnBruteForce::knn( const Image& image )
{
  // get size of training data
  size_t training_size = m_training_set.size();
  // if no training data, cannot label so return invalid label
  if ( training_size == 0 ) return Label( Label::INVALID );
  // variable to store closest image
  LabeledImage closest;
  // variable to hold distance between ref and closest image
  double closest_dist = DBL_MAX;
  // loop through training data
  for( size_t i = 0; i < training_size; i++ ) {
    // take distance of reference image and current image in training set
    double distance = euclidian_dist( image, m_training_set[i].get_image(), image_size );
    // if distance between ref and new image is less than ref and closest
    if( distance < closest_dist ) {
      // set new closest distance
      closest_dist = distance;
      // set new closest image
      closest = m_training_set[i];
    }
  }
  // return label of closest image from training set
  return closest.get_label();
}
