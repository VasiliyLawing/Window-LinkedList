#include <iostream>


namespace Cpp1::Unit3 {

  struct IntListNode {
    int data;
    IntListNode* next;
  };

  struct IntList {
    IntListNode* head = 0;
  };

  void intListAddToHead(IntList* list, int data) {
    IntListNode* newNode = new IntListNode;
    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;
  }

  void intListRemoveFromHead(IntList* list) {
    if(list->head == nullptr)
      return;

    IntListNode* newHead = list->head->next;
    delete list->head;
    list->head = newHead;
  }

  void intListPrint(const IntList* list) {
    for(const IntListNode* node = list->head; node != nullptr; node = node->next) {
      std::cout << node->data << std::endl;
    }
  }
}


int main() {
  using namespace Cpp1::Unit3;

  IntList list;

  std::cout << "#1:" << std::endl;
  intListPrint(&list);

  for(int i = 10; i > 0; --i) {
    intListAddToHead(&list, i);
  }
  std::cout << std::endl;

  std::cout << "#2:" << std::endl;
  intListPrint(&list);
  std::cout << std::endl;


  std::cout << "#3:" << std::endl;
  while (list.head != nullptr) {
    intListRemoveFromHead(&list);
    intListPrint(&list);
    std::cout << std::endl;
  }
}
