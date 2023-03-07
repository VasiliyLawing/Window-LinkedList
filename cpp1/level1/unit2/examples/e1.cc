#include <iostream>

// You can get size of any variable or type via "sizeof"

int main() {
    char ch = 'a';
    int n = 1;
    int m = 1;
    long k = 1;

    std::cout << "Variables:" << std::endl;
    std::cout << "size of ch= " << sizeof(ch) << std::endl;
    std::cout << "size of n= " << sizeof(n) << std::endl;
    std::cout << "size of m= " << sizeof(m) << std::endl;
    std::cout << "size of k= " << sizeof(k) << std::endl;

    std::cout << "Types:" << std::endl;
    std::cout << "size of int= " << sizeof(int) << std::endl;
    std::cout << "size of long= " << sizeof(long) << std::endl;
}

