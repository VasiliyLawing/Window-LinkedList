#include "listUtils.hh"


bool compareListTo(const Cpp1::Unit3::IntList* list, const int* data, int size) {
  int counter = 0;

  for(const Cpp1::Unit3::IntListNode* p = list->head; p != nullptr; p = p->next, ++counter) {
    if(p->data != data[counter])
      return false;
  }

  return counter == size;
}
