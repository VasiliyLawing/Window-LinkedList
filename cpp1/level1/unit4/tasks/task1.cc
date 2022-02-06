#include <cpp1/level1/unit4/lib/board.hh>


namespace Cpp1::Level1::Unit4 {

    Board::Board(int size) {
        m_size = size;
        m_data = new Cell[size * size];
        for (int i = 0; i < size * size; i++) {
            m_data[i] = Cell::empty;
        }
    }

    Board::~Board() {
        delete[] m_data;
    }

    bool Board::isOutOfLimits(int x, int y) const {
        if (x < 0 || y < 0)
            return true;
        if (x >= m_size || y >= m_size)
            return true;

        return false;
    }

    Error Board::get(int x, int y, Cell *pCell) const {

        if (y >= m_size || x >= m_size || x < 0 || y < 0) {
            return Error::outOfLimits;
        } else {
            int index = x + y * m_size;

            if (m_data[index] == Cell::X) {
                *pCell = Cell::X;
                return Error::ok;
            }
//y:2
//x:0
            if (m_data[index] == Cell::O) {
                *pCell = Cell::O;
                return Error::ok;
            }
            if (m_data[index] == Cell::empty) {
                *pCell = Cell::empty;
                return Error::ok;
            }

            return Error::ok;
        }
    }


    Error Board::set(int x, int y, Cell cell) {
        if (y >= m_size || x >= m_size || x < 0 || y < 0) {
            return Error::outOfLimits;

        } else {
            int index = x + y * m_size;
            m_data[index] = cell;
            return Error::ok;
        }

    }

    const char *cellAsCstr(Cell cell) {
        if (cell==Cell::empty) {
            return " ";
        }
        if (cell == Cell::X) {
            return "X";
        }
        if (cell == Cell::O) {
            return "O";
        }

    }
    void print(std::ostream &os, const Board &board) {
        //Width
        Cell cell;

        std::string cells;
        std::string skeleton;
        for (int y = 0; y < board.size(); y++) {
            skeleton += "\n-------------\n";
            for (int x = 0; x < board.size(); x++) {
                board.get(x,y,&cell);
                skeleton+="| ";
                skeleton += cellAsCstr(cell);
                skeleton+=" ";

                if (x == board.size() - 1) {
                    skeleton += "|";
                }

            }
        }
        skeleton += "\n-------------\n";

        os << skeleton;



        //
//        os <<
//
//           "| " << cells[0] << " | " << cells[1] <<  " |  "  << cells[2] <<  " |\n"
//           "-------------\n"
//           "| " << cells[3] << " | " << cells[4] <<  " | "  << cells[5] <<  " |\n"
//           "-------------\n"
//           "| " << cells[6] << " | " << cells[7] <<  " | "  << cells[8] <<  " |\n"
//           "-------------\n";
//


    } // Cpp1::Level1::Unit4
}