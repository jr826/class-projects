//========================================================================
// types-spoly.cc
//========================================================================
// Definitions for misc types

#include "types-spoly.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>

//========================================================================
// Complex
//========================================================================
//------------------------------------------------------------------------
// Overloaded operators
//------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const Complex& rhs )
{
  return rhs.print( os );
}

bool operator==( const Complex& lhs, const Complex& rhs )
{
  return lhs.eq(rhs);
}

bool operator!=( const Complex& lhs, const Complex& rhs )
{
  return !lhs.eq(rhs);
}

bool operator<( const Complex& lhs, const Complex& rhs )
{
  return lhs.lt(rhs);
}

bool operator==( const Complex* lhs, const Complex& rhs )
{
  return (*lhs).eq(rhs);
}

bool operator==( const Complex& lhs, const Complex* rhs )
{
  return (*rhs).eq(lhs);
}

//------------------------------------------------------------------------
// Constructors / Destructors
//------------------------------------------------------------------------

Complex::Complex()                           : m_real(0.0),  m_imag(0.0)  {}
Complex::Complex( double real, double imag ) : m_real(real), m_imag(imag) {}
Complex::Complex( const Complex& x ) : m_real(x.m_real), m_imag(x.m_imag) {}
Complex::~Complex()                                                       {}

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------
// Note that this comparison only compares the real components

bool Complex::eq( const Complex& rhs ) const
{
  return ( m_real == rhs.m_real );
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------
// Note that this comparison only compares the real components

bool Complex::lt( const Complex& rhs ) const
{
  return ( m_real < rhs.m_real );
}

//------------------------------------------------------------------------
// clone
//------------------------------------------------------------------------

Complex* Complex::clone() const
{
  return new Complex( *this );
}

//------------------------------------------------------------------------
// to_str
//------------------------------------------------------------------------

std::string Complex::to_str() const
{
  std::stringstream ss;
  ss << m_real << " + " << m_imag << "i";
  return ss.str();
}

//------------------------------------------------------------------------
// to_cstr
//------------------------------------------------------------------------

const char* Complex::to_cstr() const
{
  return to_str().c_str();
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

std::ostream& Complex::print( std::ostream& os ) const
{
  os << m_real << " + " << m_imag << "i";
  return os;
}

//========================================================================
// IpAddress
//========================================================================
//------------------------------------------------------------------------
// Overloaded operators
//------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const IpAddress& rhs )
{
  return rhs.print( os );
}

bool operator==( const IpAddress& lhs, const IpAddress& rhs )
{
  return lhs.eq(rhs);
}

bool operator!=( const IpAddress& lhs, const IpAddress& rhs )
{
  return !lhs.eq(rhs);
}

bool operator<( const IpAddress& lhs, const IpAddress& rhs )
{
  return lhs.lt(rhs);
}

bool operator==( const IpAddress* lhs, const IpAddress& rhs )
{
  return (*lhs).eq(rhs);
}

bool operator==( const IpAddress& lhs, const IpAddress* rhs )
{
  return (*rhs).eq(lhs);
}

//------------------------------------------------------------------------
// Constructors / Destructors
//------------------------------------------------------------------------

IpAddress::IpAddress() : m_ip { 0, 0, 0, 0 } { }
IpAddress::IpAddress( int field_0, int field_1, int field_2, int field_3 )
{
  m_ip[0] = (char) field_0;
  m_ip[1] = (char) field_1;
  m_ip[2] = (char) field_2;
  m_ip[3] = (char) field_3;
}

IpAddress::IpAddress( const IpAddress& x )
{
  for ( int i = 0; i < 4; i++ )
    m_ip[i] = x.m_ip[i];
}

IpAddress::~IpAddress() {}

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------

bool IpAddress::eq( const IpAddress& rhs ) const
{
  for ( int i = 0; i < 4; i++ )
    if ( m_ip[i] != rhs.m_ip[i] )
      return false;

  return true;
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool IpAddress::lt( const IpAddress& rhs ) const
{
  for ( int i = 0; i < 4; i++ ) {
    if      ( m_ip[i] < rhs.m_ip[i] ) return true;
    else if ( m_ip[i] > rhs.m_ip[i] ) return false;
  }

  return false;
}

//------------------------------------------------------------------------
// clone
//------------------------------------------------------------------------

IpAddress* IpAddress::clone() const
{
  return new IpAddress( *this );
}

//------------------------------------------------------------------------
// to_str
//------------------------------------------------------------------------

std::string IpAddress::to_str() const
{
  std::stringstream ss;
  ss << (int) m_ip[0] << "."
     << (int) m_ip[1] << "."
     << (int) m_ip[2] << "."
     << (int) m_ip[3];
  return ss.str();
}

//------------------------------------------------------------------------
// to_cstr
//------------------------------------------------------------------------

const char* IpAddress::to_cstr() const
{
  return to_str().c_str();
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

std::ostream& IpAddress::print( std::ostream& os ) const
{
  os << (int) m_ip[0] << "."
     << (int) m_ip[1] << "."
     << (int) m_ip[2] << "."
     << (int) m_ip[3];
  return os;
}

//========================================================================
// ShortString
//========================================================================
//------------------------------------------------------------------------
// Overloaded operators
//------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const ShortString& rhs )
{
  return rhs.print( os );
}

bool operator==( const ShortString& lhs, const ShortString& rhs )
{
  return lhs.eq(rhs);
}

bool operator!=( const ShortString& lhs, const ShortString& rhs )
{
  return !lhs.eq(rhs);
}

bool operator<( const ShortString& lhs, const ShortString& rhs )
{
  return lhs.lt(rhs);
}

bool operator==( const ShortString* lhs, const ShortString& rhs )
{
  return (*lhs).eq(rhs);
}

bool operator==( const ShortString& lhs, const ShortString* rhs )
{
  return (*rhs).eq(lhs);
}

//------------------------------------------------------------------------
// Constructors / Destructors
//------------------------------------------------------------------------

ShortString::ShortString()
{
  m_cstr[0] = '\0';
}

ShortString::ShortString( const char* cstr )
{
  size_t copy_size = ( strlen( cstr ) < m_maxsize - 1 ) ? strlen( cstr ) :
                                                          m_maxsize - 1;
  memcpy( m_cstr, cstr, copy_size );
  m_cstr[ copy_size ] = '\0';
}

ShortString::ShortString( const ShortString& x )
{
  memcpy( m_cstr, x.m_cstr, m_maxsize );
}

ShortString::~ShortString()
{
}

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------

bool ShortString::eq( const ShortString& rhs ) const
{
  if ( strcmp( m_cstr, rhs.m_cstr ) == 0 ) return true;
  return false;
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool ShortString::lt( const ShortString& rhs ) const
{
  if ( strcmp( m_cstr, rhs.m_cstr ) < 0 ) return true;
  return false;
}

//------------------------------------------------------------------------
// clone
//------------------------------------------------------------------------

ShortString* ShortString::clone() const
{
  return new ShortString( *this );
}

//------------------------------------------------------------------------
// to_str
//------------------------------------------------------------------------

std::string ShortString::to_str() const
{
  return std::string( m_cstr );
}

//------------------------------------------------------------------------
// to_cstr
//------------------------------------------------------------------------

const char* ShortString::to_cstr() const
{
  return m_cstr;
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

std::ostream& ShortString::print( std::ostream& os ) const
{
  os << m_cstr;
  return os;
}

//========================================================================
// RoutingInfo
//========================================================================
//------------------------------------------------------------------------
// Overloaded operators
//------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const RoutingInfo& rhs )
{
  return rhs.print( os );
}

bool operator==( const RoutingInfo& lhs, const RoutingInfo& rhs )
{
  return lhs.eq(rhs);
}

bool operator!=( const RoutingInfo& lhs, const RoutingInfo& rhs )
{
  return !lhs.eq(rhs);
}

bool operator<( const RoutingInfo& lhs, const RoutingInfo& rhs )
{
  return lhs.lt(rhs);
}

bool operator==( const RoutingInfo* lhs, const RoutingInfo& rhs )
{
  return (*lhs).eq(rhs);
}

bool operator==( const RoutingInfo& lhs, const RoutingInfo* rhs )
{
  return (*rhs).eq(lhs);
}

//------------------------------------------------------------------------
// Constructors / Destructors
//------------------------------------------------------------------------

RoutingInfo::RoutingInfo() { }
RoutingInfo::RoutingInfo( const IpAddress& next_hop, const int route_cost )
  : m_next_hop  ( next_hop ),
    m_route_cost( route_cost )
{ }

RoutingInfo::RoutingInfo( const RoutingInfo& x )
  : m_next_hop  ( x.m_next_hop ),
    m_route_cost( x.m_route_cost )
{ }

RoutingInfo::~RoutingInfo() {}

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------

bool RoutingInfo::eq( const RoutingInfo& rhs ) const
{
  if ( m_next_hop != rhs.m_next_hop || m_route_cost != rhs.m_route_cost )
    return false;

  return true;
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool RoutingInfo::lt( const RoutingInfo& rhs ) const
{
  if ( m_next_hop < rhs.m_next_hop )
    return true;

  if ( m_next_hop   == rhs.m_next_hop   &&
       m_route_cost <  rhs.m_route_cost    )
    return true;

  return false;
}

//------------------------------------------------------------------------
// clone
//------------------------------------------------------------------------

RoutingInfo* RoutingInfo::clone() const
{
  return new RoutingInfo( *this );
}

//------------------------------------------------------------------------
// to_str
//------------------------------------------------------------------------

std::string RoutingInfo::to_str() const
{
  std::stringstream ss;
  ss << "next hop: "      << m_next_hop.to_str()
     << " & route cost: " << m_route_cost;
  return ss.str();
}

//------------------------------------------------------------------------
// to_cstr
//------------------------------------------------------------------------

const char* RoutingInfo::to_cstr() const
{
  return to_str().c_str();
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

std::ostream& RoutingInfo::print( std::ostream& os ) const
{
  os << "next hop: "      << m_next_hop.to_str()
     << " & route cost: " << m_route_cost;
  return os;
}
