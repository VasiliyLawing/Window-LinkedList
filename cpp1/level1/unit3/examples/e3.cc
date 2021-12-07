#include "lib/list2.hh"
#include <iostream>


int main() {
  using namespace Cpp1::Unit3;

  IntList* list = intListCreate();

  std::cout << "#1:" << std::endl;
  intListPrint(list);

  for(int i = 10; i > 0; --i) {
    intListAddToHead(list, i);
  }
  std::cout << std::endl;

  std::cout << "#2:" << std::endl;
  intListPrint(list);
  std::cout << std::endl;


  std::cout << "#3:" << std::endl;
  while (list->head != nullptr) {
    intListRemoveFromHead(list);
    intListPrint(list);
    std::cout << std::endl;
  }

  intListDestroy(list);
}
