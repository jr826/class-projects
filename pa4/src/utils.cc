//========================================================================
// utils.cc
//========================================================================
// Useful classes and functions

#include "utils.h"

//========================================================================
// OutOfRangeException class
//========================================================================

OutOfRangeException::OutOfRangeException() { }

OutOfRangeException::OutOfRangeException( const char* err_msg )
  : m_err_msg( err_msg )
{ }

std::string OutOfRangeException::to_str() const
{
  return m_err_msg;
}
