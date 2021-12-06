#include <iostream>


int main() {
  const char* str = "ABC";

  std::cout << "iterating using pointer directly instead of [] " << std::endl;
  const char* p = str;
  for(; *p != 0; ++p) {
    std::cout << *p << " " << std::endl;
  }
  std::cout << std::endl;
  --p;


  do {
    std::cout << *p << " " << std::endl;
  } while(p-- != str);
  std::cout << std::endl;
}
