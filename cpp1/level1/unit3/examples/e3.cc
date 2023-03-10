#include <iostream>


int main() {
    int ar[5] = {11, 12, 13, 14, 15};

    {
        std::cout << "#1" << std::endl;

        // How do you think, why do we use "sizeof(ar) / sizeof(int)" instead of 5?
        for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
            std::cout << "ar[" << i << "]= " << ar[i] << std::endl;
    }

    {
        std::cout << "\n#2" << std::endl;

        // "auto" will work as int* here. "int*" means pointer to int aka address of int in memory.
        auto p = ar;

        for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
            std::cout << "ar[" << i << "]= " << *(p + i) << std::endl;
    }

    {
        std::cout << "\n#3" << std::endl;

        auto p = ar;

        for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++,p++)
            *p += 10;

        // You can mix array form ar[i] and pointer form *p at your convenience.
        // As long as you understand what are you doing. Which as you will see soon a general idea in C/C++.
        for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
            std::cout << "ar[" << i << "]= " << ar[i] << std::endl;

        std::cout << std::endl;

        for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
            std::cout << "ar[" << i << "]= " << *(--p) << std::endl;

    }
}
