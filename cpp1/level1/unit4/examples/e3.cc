#include <iostream>

/*
 * Operator & performs bit AND for two numbers.
 * Logical AND produces 1 only if both input bits are 1.
 */

int main() {
    int n1 = 1 + 2 + 4 + 8;
    int n2 = 4 + 8;

    std::cout << (n1 & n2) << std::endl;
}
