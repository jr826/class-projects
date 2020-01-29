//========================================================================
// types-dpoly.h
//========================================================================
// Declarations for misc types

#ifndef TYPES_DPOLY_H
#define TYPES_DPOLY_H

#include <iostream>

//------------------------------------------------------------------------
// IObject
//------------------------------------------------------------------------

class IObject
{
 public:
  virtual ~IObject(){};

  virtual         bool     eq( const IObject& rhs ) const = 0;
  virtual         bool     lt( const IObject& rhs ) const = 0;

  virtual      IObject* clone()                     const = 0;
  virtual  std::string  to_str()                    const = 0;
  virtual   const char* to_cstr()                   const = 0;
  virtual std::ostream& print( std::ostream& os )   const = 0;
};

std::ostream& operator<<(  std::ostream&  os, const IObject& rhs );
bool          operator==( const IObject& lhs, const IObject& rhs );
bool          operator!=( const IObject& lhs, const IObject& rhs );
bool          operator< ( const IObject& lhs, const IObject& rhs );

bool          operator==( const IObject* lhs, const IObject& rhs );
bool          operator==( const IObject& lhs, const IObject* rhs );

//------------------------------------------------------------------------
// Integer
//------------------------------------------------------------------------

class Integer : public IObject
{
 public:
  Integer();
  Integer( int data );
  Integer( const Integer& x );
  ~Integer();

  bool eq( const IObject& rhs ) const;
  bool lt( const IObject& rhs ) const;

  Integer* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;
  int           to_int ()                 const;

 private:
  int m_data;
};

//------------------------------------------------------------------------
// Double
//------------------------------------------------------------------------

class Double : public IObject
{
 public:
  Double();
  Double( double data     );
  Double( const Double& x );
  ~Double();

  bool eq( const IObject& rhs ) const;
  bool lt( const IObject& rhs ) const;

  Double* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;
  double        to_double ()              const;

 private:
  double m_data;
};


//------------------------------------------------------------------------
// Complex
//------------------------------------------------------------------------

class Complex : public IObject
{
 public:
  Complex();
  Complex( double real, double imag );
  Complex( const Complex& x );
  ~Complex();

  bool eq( const IObject& rhs ) const;
  bool lt( const IObject& rhs ) const;

  Complex* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

 private:
  double m_real;
  double m_imag;
};

//------------------------------------------------------------------------
// IpAddress
//------------------------------------------------------------------------

class IpAddress : public IObject
{
 public:
  IpAddress();
  IpAddress( int field_0, int field_1, int field_2, int field_3 );
  IpAddress( const IpAddress& x                                 );
  ~IpAddress();

  bool eq( const IObject& rhs ) const;
  bool lt( const IObject& rhs ) const;

  IpAddress* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

 private:
  // IPv4 address consists of four 1-byte numbers, so we represent it in
  // an array of 4 characters.
  char m_ip[4];
};

//------------------------------------------------------------------------
// ShortString
//------------------------------------------------------------------------

class ShortString : public IObject
{
 public:
  ShortString();
  ShortString( const char* cstr     );
  ShortString( const ShortString& x );
  ~ShortString();

  bool eq( const IObject& rhs ) const;
  bool lt( const IObject& rhs ) const;

  ShortString* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

  static const size_t m_maxsize = 256;

 private:
  char m_cstr[ m_maxsize ];
};

//------------------------------------------------------------------------
// RoutingInfo
//------------------------------------------------------------------------

class RoutingInfo : public IObject
{
 public:
  RoutingInfo();
  RoutingInfo( const IpAddress& next_hop, const int route_cost );
  RoutingInfo( const RoutingInfo& x                            );
  ~RoutingInfo();

  bool eq( const IObject& rhs ) const;
  bool lt( const IObject& rhs ) const;

  RoutingInfo* clone() const;

  std::string   to_str ()                 const;
  const char*   to_cstr()                 const;
  std::ostream& print( std::ostream& os ) const;

 private:
  IpAddress m_next_hop;
  int       m_route_cost;
};

#endif // TYPES_DPOLY_H
