#include "./Inner.hh"

Inner::Inner(const int z): _z(z + 5) {}

int Inner::operator()(const int u) const {
   return (_z * 7) - (u * 3);
}