#include <iostream>


int main() {
  // You can specify size of an array explicitly
  char text[10] = "ABC";
  std::cout << "text: \"" << text << "\" " << sizeof(text) << std::endl;

  // "text" array behaves like a pointer with type char*
  // We can assign it to const char* because it applies more restrictions.
  const char* p1 = text;

  // Notice sizeof(p1) return size of the pointer not the array.
  std::cout << "p1: \"" << p1 << "\" " << sizeof(p1) << std::endl;

  const char* text2 = "Hello";
  // Try to uncomment and you see you cannot assign const char* to char*
  // because it would be to circumvent restrictions.
  // char* p2 = text2;
}
