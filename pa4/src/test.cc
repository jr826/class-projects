#include "map-dpoly.cc"
#include "utils.cc"
#include "types-dpoly.cc"

int main() {
  MapIObject map;
  map.insert( Integer(0), Integer(11) );
  map.insert( Integer(2), Integer(3) );
  map.insert( Integer(3), Integer(12) );
  map.insert( Integer(4), Integer(13) );
  map.insert( Integer(5), Integer(14) );
  map.insert( Integer(6), Integer(15) );
  map.at( Integer(0) );
  return 0;
}
