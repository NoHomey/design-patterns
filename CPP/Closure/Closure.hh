#ifndef _CLOSURE_HH

#define _CLOSURE_HH

#include "./Inner.hh"

class Closure {
private:
    const int _x;
public:
    Closure(const int x);
    Inner operator()(const int y) const;
};

#endif