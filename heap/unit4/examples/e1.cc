#include <iostream>


namespace Cpp1::Unit4::E1 {


  class MyClass {
  public:
    MyClass() {
      std::cerr << "Constructor" << std::endl;
    }

    ~MyClass() {
      std::cerr << "Destructor" << std::endl;
    }
  };
}


int main() {
  using namespace Cpp1::Unit4;

  std::cerr << "Before block" << std::endl;
  {
    E1::MyClass myObj;
  }
  std::cerr << "After block" << std::endl;
}
