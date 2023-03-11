// use path relative to the unit
#include "examples/fraction.hh"


// Converts Fraction to double
double toDouble(Fraction f) {
    return double(f.m) / f.n;
}

Fraction multiply(Fraction f1, Fraction f2) {
    return {f1.m * f2.m, f1.n * f2.n};
}
