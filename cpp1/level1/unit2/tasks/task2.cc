
namespace Cpp1::Unit2::Task2 {
    int replaceChar(char* str, char srcChar, char dstChar) {
        int counter = 0;

        for (int i = 0; str[i] != 0; i++) {
            if(str[i] == srcChar) {
                str[i] = dstChar;
                counter += 1;
            }
        }

        return counter;
    }
}