// Copyright (c) 2023.  Anysolo LLC

#include <iostream>


/*
 * Operators << and >> shift bits left and right
 * To make shift BEFORE printing we need to use ().
 * We can use std::hex to print number in hex format.
 * one hex-decimal digit contains 4 bits.
 * 1L creates long integer literal.
 */

int main() {
    std::cout << "#1" << std::endl;
    std::cout << (1 << 0) << std::endl;
    std::cout << (1 << 1) << std::endl;
    std::cout << (1 << 2) << std::endl;
    std::cout << (1 << 3) << std::endl;
    std::cout << (1 << 8) << std::endl;
    std::cout << (1 << 16) << std::endl;
    std::cout << (1L << 32) << std::endl;

    std::cout << "\n#2" << std::endl;
    std::cout << (16 >> 2) << std::endl;
    std::cout << std::hex << (0xFFFF >> 4) << std::endl;
    std::cout << std::hex << (0xFFFF >> 8) << std::endl;
}
