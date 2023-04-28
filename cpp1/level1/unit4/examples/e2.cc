// Copyright (c) 2023.  Anysolo LLC

#include <iostream>

/*
 * Operator | performs bit OR for two numbers.
 * For positive numbers it works as additions. But if we interested in bits better use "|" as a proper operator.
 * Also in version with "+" instead of "|" we need use () to have order of operation we need.
 */

int main() {
    std::cout << (1 | 1 << 2) << std::endl;
    std::cout << (1 + (1 << 2)) << std::endl;
}
