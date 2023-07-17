//#include <cpp1/level1/unit2/tasks/tasks.h>
#include <lib/list2.hh>


namespace Cpp1::Unit3 {
  void intListRemove(IntList* list, IntListNode* node) {
    IntListNode* prev = nullptr;

    for(IntListNode* p = list->head; p != nullptr; p = p->next) {
      if(p->next == node) {
        prev = p;
        break;
      }
    }

    if(prev)
      prev->next = node->next;

    if(list->head == node)
      list->head = node->next;

    delete node;
  }
}
