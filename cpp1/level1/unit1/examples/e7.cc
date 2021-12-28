#include <iostream>


int main() {
  int i = 0;

  // You can skip one or more part in "for" parenthesis.
  for(; i < 3; ++i) {
    std::cout << "i = " << i << std::endl;
  }

  // Now "i" exists after the loop
  std::cout << "i after the loop = " << i << "\n\n";


  // This is the simplest way to do forever loop in C and C++
  i = 0;

  for(;;) {
    std::cout << "i = " << i << std::endl;

    // We do not want it to be really forever ;)
    if(i++ == 3)
      break;
  }
}
