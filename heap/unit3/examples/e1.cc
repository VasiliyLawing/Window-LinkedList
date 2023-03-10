#include "lib/list1.hh"
#include <iostream>



int main() {
  using namespace Cpp1::Unit3;

  IntListNode node3 = {30, nullptr};
  IntListNode node2 = {20, &node3};
  IntListNode node1 = {10, &node2};


  for(const IntListNode* p = &node1; p != nullptr; p = p->next) {
    std::cout << p->data << std::endl;
  }
}
