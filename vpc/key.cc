#include <vpc/key.hh>

#include <iostream>


namespace Vpc {
    KeyModifiers::KeyModifiers(bool isShift, bool isCtrl, bool isAlt, bool isWin) {
        m_mask = 0;

        if(isShift)
            m_mask |= shiftMask;

        if(isCtrl)
            m_mask |= ctrlMask;

        if(isAlt)
            m_mask |= altMask;

        if(isWin)
            m_mask |= isWin;
    }

    std::ostream& operator<< (std::ostream& os, KeyModifiers modifiers) {
        os << "[";

        if(modifiers.isShift())
            os << "S";

        if(modifiers.isCtrl())
            os << "C";

        if(modifiers.isAlt())
            os << "A";

        if(modifiers.isWin())
            os << "W";

        os << "]";

        return os;
    }
}