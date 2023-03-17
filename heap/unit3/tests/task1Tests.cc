#include <sstream>

#include "tasks/old/tasks.h"
#include <lib/list2.hh>

#define CATCH_CONFIG_MAIN
#include <ext-libs/catch.hpp>
#include <tests/lib/listUtils.hh>


TEST_CASE("Level1 Unit3 Task1") {
  using namespace Cpp1::Unit3;

  IntList* list = intListCreate();

  SECTION("#1") {
    IntListNode* node1 = intListAddToHead(list, 10);
    intListInsertAfter(node1, 20);
    int expected[] = {10, 20};
    REQUIRE(compareListTo(list, expected, 2));
  }

  SECTION("#2") {
    IntListNode* node1 = intListAddToHead(list, 10);
    intListInsertAfter(node1, 30);
    intListInsertAfter(node1, 20);
    int expected[] = {10, 20, 30};
    REQUIRE(compareListTo(list, expected, 3));
  }

  intListDestroy(list);
}
