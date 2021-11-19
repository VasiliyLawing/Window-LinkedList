#include <sstream>
#include <ext-libs/catch2/catch.hpp>

#include <cpp1/level1/unit1/tasks/tasks.h>


TEST_CASE("Task1") {
  using namespace Cpp1::Unit1;

  const char* str = "0123456789abcdef";

  SECTION("search for existing in the middle") {
    REQUIRE(Task1::mySearchChar(str, '7') == 7);
    REQUIRE(Task1::mySearchChar(str, 'a') == 10);
    REQUIRE(Task1::mySearchChar(str, 'e') == 14);
  }

  SECTION("search on edges") {
    REQUIRE(Task1::mySearchChar(str, '0') == 0);
    REQUIRE(Task1::mySearchChar(str, 'f') == 15);
  }

  SECTION("search for not existing") {
    REQUIRE(Task1::mySearchChar(str, 'z') == -1);
    REQUIRE(Task1::mySearchChar(str, 'A') == -1);
  }

  SECTION("search in empty") {
    REQUIRE(Task1::mySearchChar("", 'z') == -1);
  }
}
