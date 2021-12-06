#include <sstream>
#include <ext-libs/catch.hpp>
#include <iostream>
#include <stdio.h>
#include <boost/process.hpp>


void runTask(int level, int unit, int task) {
  std::ostringstream os;
  os
    << "../../cmake-build-debug/cpp1/"
    << "level" << level
    << "/unit" << unit
    << "/"
    << "level" << level << "_unit" << unit << "_task" << task;

  std::string cmd = os.str();

  std::cerr << "Opening: " << cmd;

  using namespace boost::process;

  ipstream pipe_stream;
  child c(cmd, std_out > pipe_stream);

}


TEST_CASE("Utils1") {
  SECTION("Sec1") {
    runTask(1, 1, 1);

    REQUIRE(7 == 7);
  }
}
