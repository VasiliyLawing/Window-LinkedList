#include <sstream>
#include <ext-libs/catch.hpp>

#include <tasks/tasks.h>
#include <examples/e3.hh>


TEST_CASE("Task1") {
  using namespace Cpp1::Unit3::Task1;

  IntList* list = intListCreate();

  SECTION("Test") {
    REQUIRE(7 == 7);
  }

  intListDestroy(list);
}
