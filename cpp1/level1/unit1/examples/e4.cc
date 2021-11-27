#include <iostream>

int main() {
  // Try to change next line to counter = 11
  // and you see the difference between while and do loops
  int counter = 0;

  do {
    std::cout << "counter=" << counter << std::endl;
    counter++;
  } while(counter < 10);

  std::cout << counter << std::endl;
}
