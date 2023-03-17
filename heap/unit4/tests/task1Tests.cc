#define CATCH_CONFIG_MAIN
#include <ext-libs/catch.hpp>
#include <cpp1/level1/unit4/lib/board.hh>
#include <sstream>


using namespace Cpp1::Level1::Unit4;


// You can use it for experiments
/*
void experement() {
  Board board(3);

  board.set(0, 0, Cell::O);
  board.set(1, 1, Cell::O);
  board.set(2, 2, Cell::O);

  board.set(1, 0, Cell::X);
  board.set(1, 2, Cell::X);


  print(std::cout, board);
}
*/


TEST_CASE("Level1 Unit4 Task1") {
  using namespace Cpp1::Level1::Unit4;

  SECTION("Constructing") {
    SECTION("3x3 board") {
      Board board(3);
      REQUIRE(board.size() == 3);

      REQUIRE_FALSE(board.isOutOfLimits(0, 0));
      REQUIRE_FALSE(board.isOutOfLimits(2, 2));
      REQUIRE(board.isOutOfLimits(3, 3));
    }

    SECTION("5x5 board") {
      Board board(5);
      REQUIRE(board.size() == 5);

      REQUIRE_FALSE(board.isOutOfLimits(0, 0));
      REQUIRE_FALSE(board.isOutOfLimits(4, 4));
      REQUIRE(board.isOutOfLimits(5, 5));

      for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board.size(); ++x) {
          Cell cell;
          Error error = board.get(x, y, &cell);

          REQUIRE(error == Error::ok);
          REQUIRE(cell == Cell::empty);
        }
      }
    }
  }

  SECTION("Board::isOutOfLimits") {
    SECTION("3x3") {
      Board board(3);

      REQUIRE_FALSE(board.isOutOfLimits(0, 0));
      REQUIRE_FALSE(board.isOutOfLimits(2, 2));
      REQUIRE(board.isOutOfLimits(3, 3));
    }

    SECTION("5x5") {
      Board board(5);

      REQUIRE_FALSE(board.isOutOfLimits(0, 0));
      REQUIRE_FALSE(board.isOutOfLimits(4, 4));
      REQUIRE(board.isOutOfLimits(5, 5));
    }
  }

  SECTION("Board::set limits") {
    Board board(5);
    Error error = board.set(5, 5, Cell::X);
    REQUIRE(error == Error::outOfLimits);

    error = board.set(4, 4, Cell::X);
    REQUIRE(error == Error::ok);
  }

  SECTION("Board::set and Board::get") {
    Board board(3);

    Cell cell;
    Error error = board.get(1, 1, &cell);
    REQUIRE(error == Error::ok);
    REQUIRE(cell == Cell::empty);

    error = board.set(1, 1, Cell::X);
    REQUIRE(error == Error::ok);

    error = board.get(1, 1, &cell);
    REQUIRE(error == Error::ok);
    REQUIRE(cell == Cell::X);
  }

  SECTION("print") {
    Board board(3);

    board.set(0, 0, Cell::O);
    board.set(1, 1, Cell::O);
    board.set(2, 2, Cell::O);

    board.set(1, 0, Cell::X);
    board.set(1, 2, Cell::X);


    std::ostringstream os;
    print(os, board);

    std::string expectedStr =
      "-------------\n"
      "| O | X |   |\n"
      "-------------\n"
      "|   | O |   |\n"
      "-------------\n"
      "|   | X | O |\n"
      "-------------\n"
    ;

    REQUIRE(expectedStr == os.str());
  }
}
