#include "./Closure.hh"
#include <iostream>

int main() {
    std::cout << Closure(3)(4)(5) << std::endl;
    return 0;
}