//========================================================================
// types-dpoly.cc
//========================================================================
// Definitions for misc types

#include "types-dpoly.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>

//========================================================================
// IObject
//========================================================================
//------------------------------------------------------------------------
// Overloaded operators
//------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const IObject& rhs )
{
  return rhs.print( os );
}

bool operator==( const IObject& lhs, const IObject& rhs )
{
  return lhs.eq(rhs);
}

bool operator!=( const IObject& lhs, const IObject& rhs )
{
  return !lhs.eq(rhs);
}

bool operator<( const IObject& lhs, const IObject& rhs )
{
  return lhs.lt(rhs);
}

bool operator==( const IObject* lhs, const IObject& rhs )
{
  return (*lhs).eq(rhs);
}

bool operator==( const IObject& lhs, const IObject* rhs )
{
  return (*rhs).eq(lhs);
}

//========================================================================
// Integer
//========================================================================
//------------------------------------------------------------------------
// Constructors / Destructors
//------------------------------------------------------------------------

Integer::Integer()                   : m_data(0)        {}
Integer::Integer( int data )         : m_data(data)     {}
Integer::Integer( const Integer& x ) : m_data(x.m_data) {}
Integer::~Integer()                                     {}

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------

bool Integer::eq( const IObject& rhs ) const
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data == rhs_p->m_data );
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool Integer::lt( const IObject& rhs ) const
{
  const Integer* rhs_p = dynamic_cast<const Integer*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data < rhs_p->m_data );
}

//------------------------------------------------------------------------
// clone
//------------------------------------------------------------------------

Integer* Integer::clone() const
{
  return new Integer( *this );
}

//------------------------------------------------------------------------
// to_str
//------------------------------------------------------------------------

std::string Integer::to_str() const
{
  std::stringstream ss;
  ss << m_data;
  return ss.str();
}

//------------------------------------------------------------------------
// to_cstr
//------------------------------------------------------------------------

const char* Integer::to_cstr() const
{
  return to_str().c_str();
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

std::ostream& Integer::print( std::ostream& os ) const
{
  os << m_data;
  return os;
}

//------------------------------------------------------------------------
// to_int
//------------------------------------------------------------------------

int Integer::to_int() const
{
  return m_data;
}

//========================================================================
// Double
//========================================================================
//------------------------------------------------------------------------
// Constructors / Destructors
//------------------------------------------------------------------------

Double::Double()                  : m_data(0.0)      {}
Double::Double( double data     ) : m_data(data)     {}
Double::Double( const Double& x ) : m_data(x.m_data) {}
Double::~Double()                                    {}

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------

bool Double::eq( const IObject& rhs ) const
{
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data == rhs_p->m_data );
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool Double::lt( const IObject& rhs ) const
{
  const Double* rhs_p = dynamic_cast<const Double*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_data < rhs_p->m_data );
}

//------------------------------------------------------------------------
// clone
//------------------------------------------------------------------------

Double* Double::clone() const
{
  return new Double( *this );
}

//------------------------------------------------------------------------
// to_str
//------------------------------------------------------------------------

std::string Double::to_str() const
{
  std::stringstream ss;
  ss << m_data;
  return ss.str();
}

//------------------------------------------------------------------------
// to_cstr
//------------------------------------------------------------------------

const char* Double::to_cstr() const
{
  return to_str().c_str();
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

std::ostream& Double::print( std::ostream& os ) const
{
  os << m_data;
  return os;
}

//------------------------------------------------------------------------
// to_double
//------------------------------------------------------------------------

double Double::to_double() const
{
  return m_data;
}

//========================================================================
// Complex
//========================================================================
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

bool Complex::eq( const IObject& rhs ) const
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_real == rhs_p->m_real );
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------
// Note that this comparison only compares the real components

bool Complex::lt( const IObject& rhs ) const
{
  const Complex* rhs_p = dynamic_cast<const Complex*>( &rhs );
  if ( rhs_p == nullptr ) return false;
  else                    return ( m_real < rhs_p->m_real );
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

bool IpAddress::eq( const IObject& rhs ) const
{
  const IpAddress* rhs_p = dynamic_cast<const IpAddress*>( &rhs );
  if ( rhs_p == nullptr )
    return false;

  for ( int i = 0; i < 4; i++ )
    if ( m_ip[i] != rhs_p->m_ip[i] )
      return false;

  return true;
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool IpAddress::lt( const IObject& rhs ) const
{
  const IpAddress* rhs_p = dynamic_cast<const IpAddress*>( &rhs );
  if ( rhs_p == nullptr )
    return false;

  for ( int i = 0; i < 4; i++ ) {
    if      ( m_ip[i] < rhs_p->m_ip[i] ) return true;
    else if ( m_ip[i] > rhs_p->m_ip[i] ) return false;
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
{ }

//------------------------------------------------------------------------
// eq
//------------------------------------------------------------------------

bool ShortString::eq( const IObject& rhs ) const
{
  const ShortString* rhs_p = dynamic_cast<const ShortString*>( &rhs );
  if ( rhs_p == nullptr )
    return false;

  if ( strcmp( m_cstr, rhs_p->m_cstr ) == 0) return true;

  return false;
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool ShortString::lt( const IObject& rhs ) const
{
  const ShortString* rhs_p = dynamic_cast<const ShortString*>( &rhs );
  if ( rhs_p == nullptr )
    return false;

  if ( strcmp( m_cstr, rhs_p->m_cstr ) < 0) return true;

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

bool RoutingInfo::eq( const IObject& rhs ) const
{
  const RoutingInfo* rhs_p = dynamic_cast<const RoutingInfo*>( &rhs );
  if ( rhs_p == nullptr )
    return false;

  if ( m_next_hop != rhs_p->m_next_hop || m_route_cost != rhs_p->m_route_cost )
    return false;

  return true;
}

//------------------------------------------------------------------------
// lt
//------------------------------------------------------------------------

bool RoutingInfo::lt( const IObject& rhs ) const
{
  const RoutingInfo* rhs_p = dynamic_cast<const RoutingInfo*>( &rhs );
  if ( rhs_p == nullptr )
    return false;

  if ( m_next_hop < rhs_p->m_next_hop )
    return true;

  if ( m_next_hop   == rhs_p->m_next_hop   &&
       m_route_cost <  rhs_p->m_route_cost    )
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
