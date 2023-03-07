#include <iostream>

int main() {
    // We use {} blocks to have locale variable without making a function.
    {
        std::cout << "#1" << std::endl;
        int ar[5];

        for (int i = 0; i < 5; i++)
            ar[i] = i * 10;

        for (int i = 0; i < 5; i++)
            std::cout << "ar[" << i << "]= " << ar[i] << std::endl;
    }

    {
        std::cout << "#2" << std::endl;
        int ar[5] = {11,12,13,14,15};

        // Try to change i < 5 to something like i < 7. There are not any safety checks, only maximum perfomance.
        for (int i = 0; i < 5; i++)
            std::cout << "ar[" << i << "]= " << ar[i] << std::endl;
    }
}
