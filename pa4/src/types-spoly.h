//========================================================================
// types-spoly.h
//========================================================================
// Declarations for misc types

#ifndef TYPES_SPOLY_H
#define TYPES_SPOLY_H

#include <iostream>

//------------------------------------------------------------------------
// Complex
//------------------------------------------------------------------------

class Complex
{
 public:
  Complex();
  Complex( double real, double imag );
  Complex( const Complex& x );
  ~Complex();

  bool eq( const Complex& rhs ) const;
  bool lt( const Complex& rhs ) const;

  Complex* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

 private:
  double m_real;
  double m_imag;
};

std::ostream& operator<<(  std::ostream&  os, const Complex& rhs );
bool          operator==( const Complex& lhs, const Complex& rhs );
bool          operator!=( const Complex& lhs, const Complex& rhs );
bool          operator< ( const Complex& lhs, const Complex& rhs );

bool          operator==( const Complex* lhs, const Complex& rhs );
bool          operator==( const Complex& lhs, const Complex* rhs );

//------------------------------------------------------------------------
// IpAddress
//------------------------------------------------------------------------

class IpAddress
{
 public:
  IpAddress();
  IpAddress( int field_0, int field_1, int field_2, int field_3 );
  IpAddress( const IpAddress& x                                 );
  ~IpAddress();

  bool eq( const IpAddress& rhs ) const;
  bool lt( const IpAddress& rhs ) const;

  IpAddress* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

 private:
  // IPv4 address consists of four 1-byte numbers, so we represent it in
  // an array of 4 characters.
  char m_ip[4];
};

std::ostream& operator<<(  std::ostream&    os, const IpAddress& rhs );
bool          operator==( const IpAddress& lhs, const IpAddress& rhs );
bool          operator!=( const IpAddress& lhs, const IpAddress& rhs );
bool          operator< ( const IpAddress& lhs, const IpAddress& rhs );

bool          operator==( const IpAddress* lhs, const IpAddress& rhs );
bool          operator==( const IpAddress& lhs, const IpAddress* rhs );

//------------------------------------------------------------------------
// ShortString
//------------------------------------------------------------------------

class ShortString
{
 public:
  ShortString();
  ShortString( const char* cstr     );
  ShortString( const ShortString& x );
  ~ShortString();

  bool eq( const ShortString& rhs ) const;
  bool lt( const ShortString& rhs ) const;

  ShortString* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

  static const size_t m_maxsize = 256;

 private:
  char m_cstr[ m_maxsize ];
};

std::ostream& operator<<(  std::ostream&      os, const ShortString& rhs );
bool          operator==( const ShortString& lhs, const ShortString& rhs );
bool          operator!=( const ShortString& lhs, const ShortString& rhs );
bool          operator< ( const ShortString& lhs, const ShortString& rhs );

bool          operator==( const ShortString* lhs, const ShortString& rhs );
bool          operator==( const ShortString& lhs, const ShortString* rhs );

//------------------------------------------------------------------------
// RoutingInfo
//------------------------------------------------------------------------

class RoutingInfo
{
 public:
  RoutingInfo();
  RoutingInfo( const IpAddress& next_hop, const int route_cost );
  RoutingInfo( const RoutingInfo& x                            );
  ~RoutingInfo();

  bool eq( const RoutingInfo& rhs ) const;
  bool lt( const RoutingInfo& rhs ) const;

  RoutingInfo* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

 private:
  IpAddress m_next_hop;
  int       m_route_cost;
};

std::ostream& operator<<(  std::ostream&      os, const RoutingInfo& rhs );
bool          operator==( const RoutingInfo& lhs, const RoutingInfo& rhs );
bool          operator!=( const RoutingInfo& lhs, const RoutingInfo& rhs );
bool          operator< ( const RoutingInfo& lhs, const RoutingInfo& rhs );

bool          operator==( const RoutingInfo* lhs, const RoutingInfo& rhs );
bool          operator==( const RoutingInfo& lhs, const RoutingInfo* rhs );

#endif // TYPES_SPOLY_H
