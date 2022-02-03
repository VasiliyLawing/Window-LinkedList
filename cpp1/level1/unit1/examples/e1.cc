#include <iostream>

struct Frac {
    int m;
    int n;

    void print(std::ostream &os) const;

    Frac operator*(const Frac &f2) const {return Frac{m * f2.m, n * f2.n}.simplify();}

    Frac operator/(const Frac &f2) const {return Frac{m * f2.n, n * f2.m}.simplify();}

    Frac operator+(Frac &f2) const {return Frac{f2.m * n + m * f2.n, f2.n * n}.simplify();}

    Frac operator-(Frac &f2) const {return Frac{f2.m * n - m * f2.n, f2.n * n}.simplify();}

    Frac simplify();

};

inline std::ostream &operator<<(std::ostream &os, const Frac &f) {
    f.print(os);
    return os;
}


// ------------------------- CC ---------------------------
void Frac::print(std::ostream &os) const {
    os << m << "/" << n << std::endl;
}

Frac Frac::simplify() {
    while ((m % 2 == 0 && n % 2 == 0) || (m % 3 == 0 && n % 3 == 0)) {
        if (m % 2 == 0 && n % 2 == 0) {
            m = m / 2;
            n = n / 2;
        } else if (m % 3 == 0 && n % 3 == 0) {
            m = m / 3;
            n = n / 3;
        }
    }
    return Frac{m, n};
}


int main() {
    Frac f1 = {7, 8};
    Frac f2 = {9, 5};

    std::cout << "f1=" << f1 << std::endl;
    std::cout << "f2=" << f1 << std::endl;

    Frac f12 = f1 * f2;
    std::cout << "f12=" << f12 << std::endl;

}