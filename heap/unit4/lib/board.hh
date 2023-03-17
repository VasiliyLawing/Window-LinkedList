#pragma once

#include <iostream>


namespace Cpp1::Level1::Unit4  {
  enum class Cell {empty, X, O};

  enum class Error {
    ok,
    outOfLimits,
    occupied
  };

  class Board {
    Cell* m_data;
    int   m_size;

  public:
    Board(int size);
    ~Board();

    int size() const {return m_size;}

    bool isOutOfLimits(int x, int y) const;

    Error get(int x, int y, Cell* pCell) const;
    Error set(int x, int y, Cell cell);
  };


  const char* cellAsCstr(Cell cell);
  void print(std::ostream& os, const Board& board);
}
