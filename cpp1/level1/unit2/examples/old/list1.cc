#include <iostream>


int main() {
  // a pointer to a constant characters
  // You can change pointer itself but you cannot change what it points to.
  const char* str = "ABC";

  // operator cout << prints all characters until \x00
  std::cout << "str: " << str << std::endl;

  // You can print as a row memory address by converting to const void*
  std::cout << "memory address: " << (const void*)str << std::endl;


  std::cout << "printing characters one by one:" << std::endl;
  // We can extract characters one by one using "i" as an index
  // Any string literal ends with a special character with code 0
  for(int i = 0; str[i] != 0; ++i) {
    std::cout << str[i] << " " << std::endl;
  }
  std::cout << std::endl;

  std::cout << "ASCII codes:" << std::endl;
  // We can print ASCII codes of all characters
  for(int i = 0; str[i] != 0; ++i) {
    std::cout << (int)str[i] << " " << std::endl;
  }
}
