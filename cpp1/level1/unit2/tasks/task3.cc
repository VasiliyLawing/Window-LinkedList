#include <iostream>

namespace Cpp1::Unit2::Task3 {
    int reverseStr(char* str) {
        int length = 0;

        for (int i = 0; str[i] != 0; i++) {
            length=i;
        }

        int left = 0;
        int right = length;
        while(left < right) {
            int temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            std::cout << length << std::endl;
            left++;
            right--;
        }

        return 0;
    }
}