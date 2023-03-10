#include <iostream>

/*
 * "&" makes a pointer to something
 * "*" access to something via a pointer
 */

int main() {
    int m = 13;

    int* p = &m;
    std::cout << *p << std::endl;

    *p = 14;
    std::cout << *p << std::endl;
    std::cout << m << std::endl;
}
