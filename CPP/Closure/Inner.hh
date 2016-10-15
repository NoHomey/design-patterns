#ifndef _INNER_HH

#define _INNER_HH

class Inner {
private:
    const int _z;
public:
    Inner(const int z);
    int operator()(const int u) const;
};

#endif