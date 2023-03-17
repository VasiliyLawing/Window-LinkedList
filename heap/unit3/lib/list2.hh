#pragma once

#include "lib/list1.hh"
#include <iostream>


namespace Cpp1::Unit3 {

  struct IntList {
    IntListNode* head;
  };

  IntListNode* intListAddToHead(IntList* list, int data);
  void intListRemoveFromHead(IntList* list);
  void intListPrint(const IntList* list);
  IntList* intListCreate();
  void intListDestroy(IntList* list);
}
