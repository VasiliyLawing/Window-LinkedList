#pragma once

#include <vpc/base.hh>

namespace Vpc {

    using ascii_t = std::uint8_t;
    using keyCode_t = std::uint16_t;

    class Key {
        ascii_t     m_ascii;
        keyCode_t   m_code;

    public:
        Key() {
            m_ascii = 0;
            m_code  = 0;
        }

        Key(ascii_t ascii, keyCode_t code) {
            m_ascii = ascii;
            m_code  = code;
        }

        Key(const Key& key) = default;

        ascii_t getAscii() const;
        keyCode_t getCode() const;
    };

}