#include <iostream>


namespace Cpp1::Level1::Unit4::E6 {

  enum XO {x, o};

}


int main() {
  using namespace Cpp1::Level1::Unit4::E6;

  XO xo = XO::o;
  std::cout << xo << std::endl;

  std::cout << (xo == 0) << std::endl;
  std::cout << (xo == 1) << std::endl;
}
