#include <cpp1/level1/unit2/tasks/tasks.h>
#include <lib/list2.hh>


namespace Cpp1::Unit3 {
  IntListNode* intListInsertAfter(IntListNode* after, int data) {
    IntListNode* newNode = new IntListNode{data, after->next};
    after->next = newNode;

    return newNode;
  }

}
