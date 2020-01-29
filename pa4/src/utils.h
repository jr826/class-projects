//========================================================================
// utils.h
//========================================================================
// Useful classes and functions

#ifndef UTILS_H
#define UTILS_H

#include <string>

class OutOfRangeException
{
 public:
  OutOfRangeException();
  OutOfRangeException( const char* err_msg );

  std::string to_str() const;

 private:
  std::string m_err_msg;
};

#endif // UTILS_H
