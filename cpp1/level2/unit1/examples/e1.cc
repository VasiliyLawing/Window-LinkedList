#include <iostream>
#include <cassert>

// New subjects to research:
// C++ constructors, destructors
// C++ operator[]
// C++ reference


// H File
class MyArray {
    int*    m_data;
    int     m_size;

public:
    MyArray(int size);
    ~MyArray();

    int size() const {return m_size;}

    int operator[] (int index) const {
        assert(index >= 0 && index < size());
        return m_data[index];
    }

    int& operator[] (int index)  {
        assert(index >= 0 && index < size());
        return m_data[index];
    }
};


// C File
MyArray::MyArray(int size) {
    m_data = new int[size];
    m_size = size;

    std::cout << "Memory allocated" << std::endl;
}

MyArray::~MyArray() {
    delete [] m_data;
    std::cout << "Memory destroyed" << std::endl;
}


static void arrayTest() {
    MyArray ar(5);

    for (int i = 0; i < ar.size(); ++i) {
        ar[i] = i * 10;
    }

    for(int i = 0; i < ar.size(); ++i) {
        std::cout << ar[i] << " ";
    }

    std::cout << std::endl;
}


int main() {
    std::cout << "About to start array test" << std::endl;
    arrayTest();
    std::cout << "array test finished" << std::endl;
}
