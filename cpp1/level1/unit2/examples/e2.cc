#include <iostream>

#include "fraction.hh"


void print(Fraction f) {
    std::cout << f.m << "/" << f.n;
}

double toDouble(Fraction f) {
    return double(f.m) / f.n;
}

int main() {
    Fraction f1 = {1, 2};

    std::cout << "f1=";
    print(f1);
    std::cout << std::endl;

    std::cout << "toDouble(f1)=" << toDouble(f1) << std::endl;
}
