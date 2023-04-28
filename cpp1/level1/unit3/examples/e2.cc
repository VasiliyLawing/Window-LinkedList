// Copyright (c) 2023.  Anysolo LLC

#include <iostream>

int main() {
    // We use {} blocks to have locale variable without making a function.
    {
        std::cout << "#1" << std::endl;
        int ar[5];

        std::cout << "size of ar: " << sizeof(ar) << std::endl;

        for (int i = 0; i < 5; i++)
            ar[i] = i * 10;

        for (int i = 0; i < 5; i++)
            std::cout << "ar[" << i << "]= " << ar[i] << std::endl;
    }

    // Initializing array right at its creation. It is usually better to not leave data not initialized.
    {
        std::cout << "\n#2" << std::endl;
        int ar[5] = {11,12,13,14,15};

        // Try to change i < 5 to something like i < 7. There are not any safety checks, only maximum performance.
        for (int i = 0; i < 5; i++)
            std::cout << "ar[" << i << "]= " << ar[i] << std::endl;

        // How do you think what is this?
        std::cout << ar << std::endl;
    }
}
