#pragma once

#include <vpc/base.hh>

#include <iostream>


namespace Vpc {

    using ascii_t = std::uint8_t;
    using keyCode_t = std::uint16_t;


    class KeyModifiers {
        using mask_t = std::uint8_t;

        enum {
            shiftMask = 1,
            ctrlMask = 1<<1,
            altMask = 1<<2,
            winMask = 1<<3
        };

        mask_t m_mask;

    public:
        KeyModifiers(bool isShift, bool isCtrl, bool isAlt, bool isWin);

        bool isShift() const {return (m_mask & shiftMask) != 0;}
        bool isCtrl() const {return (m_mask & ctrlMask) != 0;}
        bool isAlt() const {return (m_mask & altMask) != 0;}
        bool isWin() const {return (m_mask & winMask) != 0;}
    };

    std::ostream& operator<< (std::ostream& os, KeyModifiers modifiers);

    std::ostream& operator<< (std::ostream& os, const Key& key);
}