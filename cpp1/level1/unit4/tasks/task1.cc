#include <cpp1/level1/unit4/lib/board.hh>


namespace Cpp1::Level1::Unit4 {

Board::Board(int size) {
    m_size = size;
    m_data = new Cell[size * size];
}

Board::~Board() {
    delete[] m_data;
}

bool Board::isOutOfLimits(int x, int y) const {
    if (x < 0 || y < 0) {
        return true;
    }
    if (x >= m_size || y >= m_size) {
        return true;
    }
    return false;
}

Error Board::get(int x, int y, Cell *pCell) const {

    if (y >= m_size || x >= m_size || x < 0 || y < 0) {
        return Error::outOfLimits;
    } else {
        int index = x + y * m_size;

            if (m_data[index] == Cell::X) {
                std::cout << "X : " << std::endl;
                *pCell = Cell::X;
                return Error::ok;
            }

//y:2
//x:0
            if (m_data[index] == Cell::O) {
                std::cout << "O"  << std::endl;
                *pCell = Cell::O;
                return Error::ok;

            }
            *pCell = Cell::empty;
            return Error::ok;
    }
}





Error Board::set(int x, int y, Cell cell) {
    if (y >= m_size || x >= m_size || x < 0 || y < 0) {
        return Error::outOfLimits;

    } else {
        int index = x + y*m_size;

        m_data[index] = cell;
        return Error::ok;
    }

}

const char* cellAsCstr(Cell cell) {

    return "X";
}

void print(std::ostream& os, const Board& board) {
    os << "hello\n";
}

} // Cpp1::Level1::Unit4