// Copyright (c) 2023.  Anysolo LLC

#include <iostream>


int main() {
  int i = 10;
  double d = 1.11;

  std::cout << "#1 i=" << i << ", d=" << d << std::endl;
  std::cout << "#2 " << i * d << std::endl;

  // Compiler will detect type automatically
  auto m = i * d;
  std::cout << "#3 m=" << m << std::endl; 
}
