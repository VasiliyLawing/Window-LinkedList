#include <iostream>

/*
 * "for" loop has 3 part inside () separated by ;;
 * for(init_stmt; cond; each_stmt)
 *
 * init_stmt    - Statement executed once at the start of the loop.
 * cond         - loop condition, like in while loop.
 * each_stmt    - executed at the end of each iteration.
 *
 * Each of those 3 parts can be empty
 * This example shows when each part executed.
 *
 */


int main() {

  int i = 0;

  for(std::cout << "#1\n"; std::cout << "#2\n"; std::cout << "#3\n") {
    std::cout << "loop body\n";

    // We use "break" to stop the loop, because we print text instead doing real loop condition in part #2
    if(i++ == 3)
      break;
  }
}
