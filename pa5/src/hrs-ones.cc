//========================================================================
// hrs-ones.cc
//========================================================================
// Handwriting recognition system member function definitions

#include "hrs-ones.h"
#include <array>
#include <cassert>

//========================================================================
// HandwritingRecSysClassifyOnes
//========================================================================
//------------------------------------------------------------------------
// train
//------------------------------------------------------------------------

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HandwritingRecSysClassifyOnes::train( const std::vector<LabeledImage>& v )
{}
#pragma GCC diagnostic pop

//------------------------------------------------------------------------
// classify
//------------------------------------------------------------------------

Label HandwritingRecSysClassifyOnes::classify( const Image& image )
{
  return detect_ones( image );
}

//------------------------------------------------------------------------
// Detect ones
//------------------------------------------------------------------------

Label HandwritingRecSysClassifyOnes::detect_ones( const Image& image )
{ 
  // represents chance number is a 0. If > 1, we say it is a 0.
  int poss_zero = 0;
  // two for loops in order to go across each row
  for ( size_t r = 0; r< 28; r++ ) {
    // check for empty spots in middle of a number
    int middle_zero = 0;
    // keep track of whether or not we are in the number
    bool in_num = false;
    for ( size_t c = 0; c < 28; c++ ) {
      // if not in number yet, but find a pixel that has been drawn on
      if ( image.at( r , c ) > 0 && !in_num ) {
          // set that we are in the number
          in_num = true;
      }
      // if pixel is not drawn on, but we are in the number
      else if ( image.at( r , c ) == 0 && in_num ) {
          // increment middle zero
          middle_zero++;
      }
      // if we were in the number, found zeroes, and are now back in 
      // the number
      else if ( image.at( r , c ) > 0 && in_num && middle_zero >= 2 ) {
          // increment possible zero
          poss_zero++;
      }
      // if we found two or more gaps in the number, say it is a zero
      if ( poss_zero > 1 ) {
          return Label('0');
      }
    }
  }
  // two for loops in order to go down each column
  for ( size_t c = 0; c < 28; c++ ) {
    // check for empty spots in middle of a number
    int middle_zero = 0;
    // keep track of whether or not we are in the number
    bool in_num = false;
    for ( size_t r = 0; r < 28; r++ ) {
      // if not in number yet, but find a pixel that has been drawn on
      if ( image.at( r , c ) > 0 ) {
          // set that we are in the number
          in_num = true;
      }
      // if pixel is not drawn on, but we are in the number
      else if ( image.at( r , c ) == 0 && in_num ) {
          // increment middle zero
          middle_zero++;
      }
      // if we were in the number, found zeroes, and are now back in 
      // the number
      else if ( image.at( r , c ) > 0 && in_num && middle_zero >= 2 ) {
          // increment possible zero
          poss_zero++;
      }
      // if we found two or more gaps in the number, say it is a zero
      if ( poss_zero > 1 ) {
          return Label('0');
      }
    }
  }
  // if number does not have any gaps or breaks in it, say it is a 1
  return Label('1');
}
