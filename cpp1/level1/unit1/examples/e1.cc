#include <iostream>

struct Frac {
    int m;
    int n;

    void print(std::ostream& os) const;

    Frac operator * (const Frac& f2){
        return Frac{m * f2.m, n * f2.n};
    }
    Frac operator + (Frac& f2) {
        int numerator = f2.m * n + m * f2.n;
        int denominator = f2.n* n;

        while ((numerator % 2 == 0 && denominator % 2 == 0) || (numerator % 3 == 0 && denominator % 3 == 0)) {
           // int numerator = m * n + m * f2.n;
           // int denominator = f2.n* n;

            if (numerator % 2 == 0 && denominator % 2 == 0) {
                numerator = numerator / 2;
                denominator = denominator / 2;

            } else if (numerator % 3 == 0 && denominator % 3 == 0) {
                numerator = numerator / 3;
                denominator = denominator / 3;

            }
        }
        return Frac{numerator, denominator};


    //    return Frac{numerator1 + numerator2, denominator1 + denominator2};
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
    Frac f1 = {3, 6};
    Frac f2 = {2, 5};

    std::cout << "f1=" << f1 << std::endl;
    std::cout << "f2=" << f1 << std::endl;

    Frac f12 = f1 + f2;
    std::cout << "f12=" << f12 << std::endl;

}