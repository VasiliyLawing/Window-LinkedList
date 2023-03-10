#include <iostream>


int main() {
  const char* text = "QWERTYUIOPASDFGHJKL";

  // If you uncomment the next line you see that you cannot change the character pointer "text" points to.
  //text[0] = '*';

  // Creating an array of characters and initialize it with our text.
  // You use an array the same way as usual pointer.
  char text2[] = "QWERTYUIOPASDFGHJKL";
  std::cout << "text2: \"" << text2 << " " << sizeof(text2) << std::endl;

  std::cout << "sizeof text: " << sizeof(text) << std::endl;

  // You can change character in array 'text2'
  text2[0] = '1';
  text2[1] = '2';
  std::cout << "text2: \"" << text2 << " " << std::endl;
}
