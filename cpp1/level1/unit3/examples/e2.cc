#include "e1.hh"
#include <iostream>


namespace Cpp1::Unit3::E2 {
  using namespace Cpp1::Unit3::E1;

  IntListNode* createMyList() {
    IntListNode* node3 = new IntListNode{30, nullptr};
    IntListNode* node2 = new IntListNode{20, node3};
    IntListNode* node1 = new IntListNode{10, node2};

    return node1;
  }

  void printList(const IntListNode* head) {
    for(const IntListNode* node = head; node != nullptr; node = node->next) {
      std::cout << node->data << std::endl;
    }
  }

  void destroyList(const IntListNode* head) {
    for(const IntListNode* node = head; node != nullptr;) {
      const IntListNode* next = node->next;
      delete node;
      node = next;
    }
  }
}

int main() {
  using namespace Cpp1::Unit3::E2;

  const IntListNode* node = createMyList();
  printList(node);
  destroyList(node);
}
