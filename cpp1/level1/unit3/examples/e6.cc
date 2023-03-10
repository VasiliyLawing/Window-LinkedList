#include <iostream>
#include <cpp1/level1/unit2/examples/fraction.hh>

// Using pointer to a struct and operator "->"

int main() {
    Fraction f1 = {3, 4};

    Fraction* p = &f1;
    std::cout << p->m << "/" << p->n << std::endl;

    p->m = 7;
    std::cout << p->m << "/" << p->n << std::endl;

    std::cout << f1.m << "/" << f1.n << std::endl;
}
