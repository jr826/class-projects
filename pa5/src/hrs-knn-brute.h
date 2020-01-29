//========================================================================
// hrs-knn-brute.h
//========================================================================
// Declarations for handwriting recognition systems

#ifndef HRS_KNN_BRUTE_H
#define HRS_KNN_BRUTE_H

#include "types.h"
#include "hrs.h"
#include <vector>

//------------------------------------------------------------------------
// HandwritingRecSysKnnBruteForce
//------------------------------------------------------------------------
// This handwriting recognition system uses the k-nearest neighbors
// algorithm to search across the training images for the nearest neighbor
// using the Euclidean distance. Then it classifies the incoming image
// with the closest neighbor's label.

class HandwritingRecSysKnnBruteForce : public IHandwritingRecSys
{
 public:
  void  train    ( const std::vector<LabeledImage>& v );
  Label classify ( const Image& image );

 private:
  Label knn( const Image& image );

  std::vector<LabeledImage> m_training_set;
};

#endif // HRS_KNN_BRUTE_H

