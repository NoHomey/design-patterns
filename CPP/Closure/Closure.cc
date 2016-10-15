#include "./Closure.hh"

Closure::Closure(const int x): _x(x * 2) {}

Inner Closure::operator() (const int y) const {
    return Inner(_x * 3 - y);
}