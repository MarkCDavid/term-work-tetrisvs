//
// Created by Mark David on 13/03/2019.
//

#ifndef TERMINALGAMEENGINE_TERMINALCOLOR_H
#define TERMINALGAMEENGINE_TERMINALCOLOR_H

#ifdef WIN32
enum class FG_COLOR { // Using scoped enumerations, to differentiate between FG and BG colors.
    BLACK = 0x0000,
    DARK_BLUE = 0x0001,
    DARK_GREEN = 0x0002,
    DARK_CYAN = 0x0003,
    DARK_RED = 0x0004,
    DARK_MAGENTA = 0x0005,
    DARK_YELLOW = 0x0006,
    GREY = 0x0007,
    DARK_GREY = 0x0008,
    BLUE = 0x0009,
    GREEN = 0x000A,
    CYAN = 0x000B,
    RED = 0x000C,
    MAGENTA = 0x000D,
    YELLOW = 0x000E,
    WHITE = 0x000F,

};

enum class BG_COLOR {
    BLACK = 0x0000,
    DARK_BLUE = 0x0010,
    DARK_GREEN = 0x0020,
    DARK_CYAN = 0x0030,
    DARK_RED = 0x0040,
    DARK_MAGENTA = 0x0050,
    DARK_YELLOW = 0x0060,
    GREY = 0x0070,
    DARK_GREY = 0x0080,
    BLUE = 0x0090,
    GREEN = 0x00A0,
    CYAN = 0x00B0,
    RED = 0x00C0,
    MAGENTA = 0x00D0,
    YELLOW = 0x00E0,
    WHITE = 0x00F0,
};
#endif

#endif //TERMINALGAMEENGINE_TERMINALCOLOR_H
