#include <iostream>
#include <cpp1/level1/unit2/examples/fraction.hh>

// Using pointer to a struct and operator "->"

int main() {
    Fraction f1 = {3, 4};

    // Fraction takes memory for 2 int variables
    std::cout << "sizeof(f1): " << sizeof(f1) << std::endl;

    Fraction* p = &f1;
    std::cout << "#1 " << p->m << "/" << p->n << std::endl;

    p->m = 7;
    std::cout <<"#2 " << p->m << "/" << p->n << std::endl;

    std::cout << "#3 " << f1.m << "/" << f1.n << std::endl;
}
