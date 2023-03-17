#pragma once


#include <cstdint>
#include <cassert>


namespace Vpc {
    class Pal16 {
    public:
        using color24_t = std::uint32_t;

    private:
        color24_t m_colors[16];

    public:
        explicit Pal16(const color24_t* colors);

        color24_t operator[](int n) const {
            assert(n >= 0 && n < 16);
            return m_colors[n];
        }
    };
}
