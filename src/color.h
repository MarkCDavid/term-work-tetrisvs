//
// Created by Mark David on 26/03/2019.
//
#ifndef TETRISVS_COLOR_H
#define TETRISVS_COLOR_H

#ifdef _WIN32
#include "../lib/curses.h"
#endif
#ifdef __linux__
#include <ncurses.h>
#endif



enum Color {
    RED_BLACK = 1,
    GREEN_BLACK = 2,
    YELLOW_BLACK = 3,
    MAGENTA_BLACK = 4,
    CYAN_BLACK = 5,
    FULL_BLUE = 6,
    FULL_RED = 7,
    FULL_YELLOW = 8,
    FULL_MAGENTA = 9,
    FULL_CYAN = 10,
    FULL_GREEN = 11,
    FULL_WHITE = 12,
    FULL_BLACK = 13

};

static void init_color_pairs() {
    init_pair(Color::RED_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(Color::GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(Color::YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(Color::MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(Color::CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);

    init_pair(Color::FULL_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(Color::FULL_RED, COLOR_RED, COLOR_RED);
    init_pair(Color::FULL_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(Color::FULL_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(Color::FULL_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(Color::FULL_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(Color::FULL_WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(Color::FULL_BLACK, COLOR_BLACK, COLOR_BLACK);

}

static int get_color(const char symbol) {
    switch (symbol) {
        case 'B':
            return Color::FULL_BLUE;
        case 'C':
            return Color::FULL_CYAN;
        case 'M':
            return Color::FULL_MAGENTA;
        case 'R':
            return Color::FULL_RED;
        case 'G':
            return Color::FULL_GREEN;
        case 'Y':
            return Color::FULL_YELLOW;
        case ' ':
            return Color::FULL_BLACK;
        case 'X':
        default:
            return Color::FULL_WHITE;
    }
}


#endif //TETRISVS_COLOR_H
