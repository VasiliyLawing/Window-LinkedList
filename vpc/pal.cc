#include <vpc/pal.hh>


namespace Vpc {

Pal16::Pal16 ibmPc ( {
        0x0,        // black
        0x0000AA,   // blue
        0x00AA00,   // green
        0x00AAAA,   // cyan
        0xAA0000,   // red
        0xAA00AA,   // magenta
        0xAA5500,   // brown
        0xAAAAAA,   // light grey
        0x555555,   // dark grey
        0x5555FF,   // bright blue
        0x55FF55,   // bright green
        0x55FFFF,   // bright cyan
        0xFF5555,   // bright red
        0xFF55FF,   // bright magenta
        0xFFFF55,   // bright yellow
        0xFFFFFF    // white
};
);

}