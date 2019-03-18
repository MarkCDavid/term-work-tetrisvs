//
// Created by Mark David on 18/03/2019.
//

#include "shapefactory.h"
#include <random>
#include <ctime>


Shape *ShapeFactory::Regular() {

    int choice = rand() % 7;
    switch (choice) {
        case 0:
            return new Shape(BG_COLOR::CYAN, 4, regular_shapes[0]);
        case 1:
            return new Shape(BG_COLOR::YELLOW, 2, regular_shapes[1]);
        case 2:
            return new Shape(BG_COLOR::MAGENTA, 3, regular_shapes[2]);
        case 3:
            return new Shape(BG_COLOR::DARK_BLUE, 3, regular_shapes[3]);
        case 4:
            return new Shape(BG_COLOR::DARK_YELLOW, 3, regular_shapes[4]);
        case 5:
            return new Shape(BG_COLOR::GREEN, 3, regular_shapes[5]);
        case 6:
            return new Shape(BG_COLOR::RED, 3, regular_shapes[6]);
        default:
            return nullptr;
    }
}

Shape *ShapeFactory::Garbage(int level) {
    return nullptr;
}

ShapeFactory::ShapeFactory() {
    srand((unsigned) time(0));
    regular_shapes = new char *[7];
    // ---------- I shape ----------
    regular_shapes[0] = new char[16]{' ', 'C', ' ', ' ',
                                     ' ', 'C', ' ', ' ',
                                     ' ', 'C', ' ', ' ',
                                     ' ', 'C', ' ', ' '};
    // ---------- O shape ----------
    regular_shapes[1] = new char[4]{'Y', 'Y',
                                    'Y', 'Y'};
    // ---------- T shape ----------
    regular_shapes[2] = new char[9]{'M', 'M', 'M',
                                    ' ', 'M', ' ',
                                    ' ', ' ', ' '};
    // ---------- J shape ----------
    regular_shapes[3] = new char[9]{' ', 'b', ' ',
                                    ' ', 'b', ' ',
                                    'b', 'b', ' '};
    // ---------- L shape ----------
    regular_shapes[4] = new char[9]{' ', 'y', ' ',
                                    ' ', 'y', ' ',
                                    ' ', 'y', 'y',};
    // ---------- S shape ----------
    regular_shapes[5] = new char[9]{' ', 'G', 'G',
                                    'G', 'G', ' ',
                                    ' ', ' ', ' '};
    // ---------- Z shape ----------
    regular_shapes[6] = new char[9]{'R', 'R', ' ',
                                    ' ', 'R', 'R',
                                    ' ', ' ', ' '};
}
