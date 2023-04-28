// Copyright (c) 2023.  Anysolo LLC

#include <iostream>

#include "fraction.hh"


// Functions takes Fraction as parameter and return nothing.
void print(Fraction f) {
    std::cout << f.m << "/" << f.n;
}


int main() {
    Fraction f1 = {1, 2};

    std::cout << "f1=";
    print(f1);
    std::cout << std::endl;

    std::cout << "toDouble(f1)=" << toDouble(f1) << std::endl;

    Fraction f2 = {3, 4};

    std::cout << "f2=";
    print(f2);
    std::cout << std::endl;

    auto f3 = multiply(f1, f2);

    std::cout << "f3=";
    print(f3);
    std::cout << std::endl;
}
