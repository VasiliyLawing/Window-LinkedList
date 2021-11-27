#include <iostream>


int main() {
  int counter = 0;

  while(counter < 10) {
    std::cout << "counter=" << counter << std::endl;
    counter++;
  }

  std::cout << counter << std::endl;
}
