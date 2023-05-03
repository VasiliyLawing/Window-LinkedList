// Copyright (c) 2023.  Anysolo LLC

#include <iostream>
#include <bitset>

/*
 * Operator & performs bit AND for two numbers.
 * Logical AND produces 1 only if both input bits are 1.
 */

int main() {
    int n1 = 1 + 2 + 4 + 8;
    int n2 = 1 + 8 + 16;
    int n3 = n1 & n2;

    std::cout << "#1" << std::endl;
    std::cout << n3 << std::endl;

    std::cout << "\n#2" << std::endl;
    std::cout << std::bitset<8>(n1) << std::endl;
    std::cout << std::bitset<8>(n2) << std::endl;
    std::cout << std::bitset<8>(n3) << std::endl;
}
