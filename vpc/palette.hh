#pragma once


#include <cstdint>
#include <cassert>
#include <vector>
#include <initializer_list>


namespace Vpc {
    class Palette {
    public:
        using color24_t = std::uint32_t;

    private:
        std::vector<color24_t> m_colors;

    public:
        explicit Palette(std::initializer_list<color24_t> colors);

        color24_t operator[](int n) const {
            assert(n >= 0 && n < 16);
            return m_colors[n];
        }
    };

    namespace Palettes {
        extern Palette ibmPc;
    }
}
