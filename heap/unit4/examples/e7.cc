#include <iostream>


namespace Cpp1::Level1::Unit4::E7 {

  enum class XO {x, o};


  // static functions visible only in this file.
  static const char* xoToStr(XO xo) {
    const char* str;

    switch(xo) {
      case XO::x:
        str = "X";
        break;

      case XO::o:
        str = "O";
        break;

      default:
        str = "?";
        break;
    }

    return str;
  }
}


int main() {
  using namespace Cpp1::Level1::Unit4::E7;

  XO xo = XO::o;

  // This would be an error
  //  std::cout << xo << std::endl;


  std::cout << xoToStr(xo) << std::endl;
}
