#include <iostream>

struct Frac {
    int m;
    int n;

public:
    Frac(int m, int n);
    Frac(int m);

    void print(std::ostream &os) const;
    Frac simplify();
    Frac operator*(const Frac &f2) const {return Frac{m * f2.m, n * f2.n}.simplify();}
    Frac operator/(const Frac &f2) const {return Frac{m * f2.n, n * f2.m}.simplify();}
    Frac operator+(Frac &f2) const {return Frac{f2.m * n + m * f2.n, f2.n * n}.simplify();}
    Frac operator-(Frac &f2) const {return Frac{f2.m * n - m * f2.n, f2.n * n}.simplify();}

private:

};

inline std::ostream &operator<<(std::ostream &os, const Frac &f) {
    f.print(os);
    return os;
}

// ------------------------- CC ---------------------------
void Frac::print(std::ostream &os) const {
    if (m == n) {
        os << 1 << std::endl;
    } else {
        os << m << "/" << n << std::endl;
    }
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

Frac::Frac(int m, int n) {
    this->m = m;
    this->n = n;
}
Frac::Frac(int m) {
    this->m = m;
    this->n = 1;
}



int main() {
    Frac f1 = {2, 2};
    Frac f2 = {4, 4};

    std::cout << "f1=" << f1 << std::endl;
    std::cout << "f2=" << f1 << std::endl;

    Frac f12 = f1 * f2;
    std::cout << "f12=" << f12 << std::endl;
}