#pragma once


// H
class View {
    struct {
        int row;
        int col;
    } m_cursor;

public:
    virtual ~View() {}

    void setCursor(int row, int col) {
        m_cursor.row = row;
        m_cursor.col = col;
    }

    void print(const char* text);

protected:
    virtual void setChar(int row, int col, char ch) = 0;
};


// C
void View::print(const char* text) {
    for(const char* p = text; *p != 0; ++p) {
        setChar(m_cursor.row, m_cursor.col, *p);

        if(m_cursor.col < 80)
            m_cursor.col++;
        else {
            m_cursor.col = 0;
            m_cursor.row++;
        }
    }
}



class Upstate {

};