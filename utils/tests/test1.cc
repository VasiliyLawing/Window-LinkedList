#include <sstream>
#include <ext-libs/catch.hpp>
#include <iostream>
#include <stdio.h>
#include <boost/process.hpp>


void runTask(int level, int unit, int task) {
  std::ostringstream os;
  os
    << "cmake-build-debug/cpp1/"
    << "level" << level
    << "/unit" << unit
    << "/"
    << "level" << level << "_unit" << unit << "_task" << task;

  std::cerr << "Opening: " << os.str();

  FILE* p = popen(os.str().c_str(), "r");
//  std::ifstream is(p);
}


TEST_CASE("Utils1") {
  SECTION("Sec1") {
    runTask(1, 2, 1);

    REQUIRE(7 == 7);
  }
}
