#include <iostream>


int main() {
  // "for" loop has 3 part inside () separated by ;;
  // This example shows when each part executed.
  // Part #2 works like the condition for while loop.

  int i = 0;

  for(std::cout << "#1\n"; std::cout << "#2\n"; std::cout << "#3\n") {
    std::cout << "loop body\n";

    // We use "break" to stop the loop, because we print text instead doing real loop condition in part #2
    if(i++ == 3)
      break;
  }

  // Uncomment the next line and you that variable "i" is visible only inside the loop
  // std::cout << i << std::endl;
}
