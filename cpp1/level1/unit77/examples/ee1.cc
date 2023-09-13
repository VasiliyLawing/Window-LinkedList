#include <iostream>


class Dummy {
public:
    Dummy() {
        std::cerr << "Ctor" << std::endl;
    }

    ~Dummy() {
        std::cerr << "Dtor" << std::endl;
    }
};

int main() {
    std::cerr << "Start" << std::endl;
    Dummy* dummy = new Dummy();

    delete dummy;
    std::cerr << "Finished" << std::endl;
}
