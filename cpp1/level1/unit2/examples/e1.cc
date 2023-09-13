// Copyright (c) 2023.  Anysolo LLC

#include <iostream>

// We append contents of file fraction.hh inhere.
#include "fraction.hh"


int main() {
    Fraction f1 = {1, 2};
    std::cout << "f1=" << f1.m << "/" << f1.n << std::endl;

    Fraction f2;
    f2.m = 3;
    f2.n = 4;
    std::cout << "f2=" << f2.m << "/" << f2.n << std::endl;

    f2 = {5, 7};
    std::cout << "f2.2=" << f2.m << "/" << f2.n << std::endl;
}
