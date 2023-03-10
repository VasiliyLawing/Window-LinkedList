#include <iostream>

/*
 * When you add or subtract number to/from a pointer in C. pointer changes by size of the type it points to.
 * For instance, if you add 1 to p declared as int* p it will increase by sizeof(int) (usually 4).
 * This example demonstrate how you can convert type of pointer forcing compiler calculate pointers differently.
 */

int main() {
    const int arSize = 5;
    int ar[arSize] = {11, 12, 13, 14, 15};

    {
        std::cout << "#1" << std::endl;

        // Notice p++ increase p by sizeof(int)
        const int* p = ar;
        for (int i = 0; i < arSize; i++, p++) {
            std::cout
                << "ar[" << i << "]= " << *p
                << " p= " << p
                << std::endl
            ;
        }
    }

    {
        std::cout << "#2" << std::endl;

        // Printing the same array but as bytes instead of ints
        // Notice p++ increase p by 1
        // We convert char and const char* to int and unsigned long to avoiding printing them as text by std::ostream
        const unsigned char* p = (const unsigned char*) ar;
        for (int i = 0; i < arSize*sizeof(int); i++, p++) {
            std::cout
                << "ar[" << i << "]= " << int(*p)
                << " p= " << (unsigned long)(p)
                << std::endl
           ;

            if(i % 4 == 0)
                std::cout << std::endl;
        }
    }
}
