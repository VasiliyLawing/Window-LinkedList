#include <vpc/display.hh>
#include <iostream>


int main() {
    {
        Display display("Virtual display", 1929, 1080);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    std::cerr << "the end" << std::endl;
}
