namespace Cpp1::Unit2::Task1 {
    int searchChar(const char *str, char ch) {
        for (int i = 0; str[i] != 0; i++) {
            if(str[i] == ch) {
                return i;
            }
        }

        return -1;
    }
}
