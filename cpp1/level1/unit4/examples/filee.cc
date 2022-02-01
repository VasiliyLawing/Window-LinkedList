#include <iostream>

struct Frac {
    int m;
    int n;
};

void print(const Frac* f) {
    std::cout << f->m << "/" << f->n << std::endl;
}

Frac mutiply(const Frac* f1, const Frac* f2){
    return Frac{f1->m * f2->m,f1->n * f2->n};
}

int main()  {
    Frac f1 = {3, 4};
    Frac f2 = {3, 5};

    Frac f12 = mutiply(&f1, &f2);

    print(&f12);
}