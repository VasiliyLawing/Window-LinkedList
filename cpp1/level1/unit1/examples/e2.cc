#include <iostream>

// ------------- H ----------------------
class Frac {
    int m;
    int n;

public:
    Frac(int m, int n) {
        this->m = m;
        this->n = n;
    }

    Frac(int m){
        this->m = m;
        this->n = 1;
    }

void print(std::ostream& os) const;
Frac simplfy () const {
    for(int i = n; i >= m || i >= n; i--){
        if(m % i == 0 && n % i == 0)
            return Frac{m/i, n/i};
    }
    return Frac{m,n};
}

Frac operator! () const { return simplfy();}

Frac operator * (const Frac& f2){
    return ! Frac{m * f2.m, n * f2.n};
}

Frac operator / (const Frac& f2){
    return ! Frac{m * f2.n, n * f2.m};
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
    Frac a(111, 0);

    std::cout << !Frac{4,2} << std::endl;
    Frac f1 = {3, 4};
    Frac f2 = {3, 4};

    std::cout << "f1=" << f1 << std::endl;
    std::cout << "f2=" << f2 << std::endl;

    Frac f12 = f1 * f2;
    std::cout << "f12=" << f12 << std::endl;

    std::cout << "f1/f2=" << f1 / f2 << std::endl;
}