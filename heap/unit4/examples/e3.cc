#include <iostream>

/*
 * A reference is basically a pointer but you use it like usual variable.
 * A reference must be initialized.
 */


int main() {
  // An int variable
  int n = 1;

  // A reference to an int variable
  int& nr = n;

  std::cout << "#1 " << std::endl;
  std::cout << n << std::endl;
  std::cout << nr << std::endl;

  ++nr;
  std::cout << "\n#2 " << std::endl;
  std::cout << n << std::endl;
  std::cout << nr << std::endl;

  ++n;
  std::cout << "\n#3 " << std::endl;
  std::cout << n << std::endl;
  std::cout << nr << std::endl;
}
