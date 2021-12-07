#pragma once

#include "e1.hh"
#include <iostream>


namespace Cpp1::Unit3::E3 {
  using namespace Cpp1::Unit3::E1 ;

  struct IntList {
    IntListNode* head;
  };

  void intListAddToHead(IntList* list, int data);
  void intListRemoveFromHead(IntList* list);
  void intListPrint(const IntList* list);
  IntList* intListCreate();
  void intListDestroy(IntList* list);
}
