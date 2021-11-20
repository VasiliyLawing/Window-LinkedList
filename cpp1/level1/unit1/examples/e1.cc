#include <iostream>


int main() {
  // a pointer to a constant characters
  const char* str = "ABC";

  std::cout << str << std::endl;

  // We can extract characters one by one using "i" as an index
  // Any string literal ends with a special character with code 0
  for(int i = 0; str[i] != 0; ++i) {
    std::cout << str[i] << " " << std::endl;
  }

  // We can print ASCII codes of all characters
  for(int i = 0; str[i] != 0; ++i) {
    std::cout << (int)str[i] << " " << std::endl;
  }
}
