#include <iostream>


int main() {
  const char* text = "ABC";
  const char* text2 = text;
  const char* anotherText = "Other text";

  std::cout << "text: \"" << text << "\" at addr: " << (const void*) text << std::endl;
  text = anotherText;
  std::cout << "text: \"" << text << "\" at addr: " << (const void*) text << std::endl;


  std::cout << "original text: " << text2 << "\" at the same addr: " << (const void*) text2 << std::endl;
}
