#include <sstream>
#define CATCH_CONFIG_MAIN
#include <ext-libs/catch.hpp>

#include <tasks/tasks.h>


TEST_CASE("Level1 Unit2 Task2") {
  using namespace Cpp1::Unit2;

  SECTION("Replace one") {
    char str[] = "012a45678";

    SECTION("Replace in the middle") {
        REQUIRE(Task2::replaceChar(str, 'a', 'A') == 1);
        REQUIRE(strcmp(str, "012A45678") == 0);
    }

    SECTION("Replace at the beginning") {
      REQUIRE(Task2::replaceChar(str, '0', 'z') == 1);
      REQUIRE(std::string(str) == "z12a45678");
    }

    SECTION("Replace at the end") {
      REQUIRE(Task2::replaceChar(str, '8', 'e') == 1);
      REQUIRE(std::string(str) == "012a4567e");
    }
  }

  SECTION("Replace multiple") {
    char str[] = "012aaa678";
    REQUIRE(Task2::replaceChar(str, 'a', 'A') == 3);
    REQUIRE(std::string(str) == "012AAA678");
  }

  SECTION("Test that memory after \\0 is safe") {
    char str[] = "012aaa678\x00Q";
    REQUIRE(Task2::replaceChar(str, 'a', 'A') == 3);
    REQUIRE(str[10] == 'Q');
  }
}
