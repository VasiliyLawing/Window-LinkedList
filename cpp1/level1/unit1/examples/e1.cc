#include <iostream>

struct Frac {
    int m;
    int n;

    void print(std::ostream& os) const;

    Frac operator * (const Frac& f2){
        return Frac{m * f2.m, n * f2.n};
    }
    Frac operator / (const Frac& f2){
        return Frac{m * f2.n, n*f2.m };
    }


    Frac simplify () {
        while ((m % 2 == 0 && n % 2 == 0) || (m % 3 == 0 && n % 3 == 0)) {
            // int m = m * n + m * f2.n;
            // int denominator = f2.n* n;

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

    Frac operator + (Frac& f2) {
        int numerator = f2.m * n + m * f2.n;
        int denominator = f2.n* n;
        return Frac{numerator, denominator};

    }
    Frac operator - (Frac& f2) {
        int numerator = f2.m * n - m * f2.n;
        int denominator = f2.n* n;
        return Frac{numerator, denominator};

    }
};

inline std::ostream& operator<< (std::ostream& os, const Frac& f) {
    f.print(os);
    return os;
}


// ------------------------- CC ---------------------------
void Frac::print(std::ostream& os) const {
    os << m << "/" << n << std::endl;
}


int main()  {
    Frac f1 = {1, 3};
    Frac f2 = {2, 4};

    std::cout << "f1=" << f1 << std::endl;
    std::cout << "f2=" << f1 << std::endl;

    Frac f12 = f1 / f2;
    f12.simplify();
    std::cout << "f12=" << f12 << std::endl;

}