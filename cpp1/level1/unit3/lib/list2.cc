#include "lib/list2.hh"
#include <iostream>


namespace Cpp1::Unit3 {
  IntListNode* intListAddToHead(IntList* list, int data) {
    IntListNode* newNode = new IntListNode;
    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;

    return newNode;
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

  IntList* intListCreate() {
    IntList* list = new IntList;
    list->head = nullptr;

    return list;
  }

  void intListDestroy(IntList* list) {
    while (list->head != nullptr)
      intListRemoveFromHead(list);

    delete list;
  }
}
