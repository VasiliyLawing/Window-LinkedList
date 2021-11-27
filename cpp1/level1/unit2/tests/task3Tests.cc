#include <sstream>
#include <ext-libs/catch.hpp>

#include <tasks/tasks.h>


TEST_CASE("Task3") {
  using namespace Cpp1::Unit2;


  SECTION("Reverse even number of chars") {
    char str[] = "0123456789";

    Task3::reverseStr(str);
    REQUIRE(std::string(str) == "9876543210");
  }

  SECTION("Reverse odd number of chars") {
    char str[] = "012345678";

    Task3::reverseStr(str);
    REQUIRE(std::string(str) == "876543210");
  }

  SECTION("Reverse one chars") {
    char str[] = "1";

    Task3::reverseStr(str);
    REQUIRE(std::string(str) == "1");
  }

  SECTION("Reverse an empty string") {
    char str[] = "";

    Task3::reverseStr(str);
    REQUIRE(std::string(str) == "");
  }

  SECTION("Check memory after \\0") {
    char str[] = "0123456789\x00Q";

    Task3::reverseStr(str);
    REQUIRE(std::string(str) == "9876543210");
    REQUIRE(str[11] == 'Q');
  }
}
