
#include <sstream>

#include "tasks/old/tasks.h"
#include <lib/list2.hh>
#include <tests/lib/listUtils.hh>

#define CATCH_CONFIG_MAIN
#include <ext-libs/catch.hpp>


TEST_CASE("Level1 Unit3 Task2") {
  using namespace Cpp1::Unit3;

  IntList* list = intListCreate();

  SECTION("#1") {
    IntListNode* node1 = intListAddToHead(list, 10);
    intListRemove(list, node1);
    int expected[] = {};
    REQUIRE(compareListTo(list, expected, 0));
  }

  SECTION("#2") {
    intListAddToHead(list, 30);
    IntListNode* node = intListAddToHead(list, 20);
    intListAddToHead(list, 10);
    intListRemove(list, node);

    int expected[] = {10, 30};
    REQUIRE(compareListTo(list, expected, 2));
  }

  SECTION("#3") {
    intListAddToHead(list, 30);
    intListAddToHead(list, 20);
    IntListNode* node = intListAddToHead(list, 10);
    intListRemove(list, node);

    int expected[] = {20, 30};
    REQUIRE(compareListTo(list, expected, 2));
  }

  intListDestroy(list);
}

