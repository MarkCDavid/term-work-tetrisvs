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
    int choice = (level - 1) * 4 + (rand() % 4);
    switch (choice) {
        case 0:
            return new Shape(BG_COLOR::DARK_RED, 3, garbage_shapes[0]);
        case 1:
            return new Shape(BG_COLOR::DARK_RED, 3, garbage_shapes[1]);
        case 2:
            return new Shape(BG_COLOR::DARK_RED, 3, garbage_shapes[2]);
        case 3:
            return new Shape(BG_COLOR::DARK_RED, 3, garbage_shapes[3]);
        case 4:
            return new Shape(BG_COLOR::DARK_GREEN, 3, garbage_shapes[4]);
        case 5:
            return new Shape(BG_COLOR::DARK_GREEN, 3, garbage_shapes[5]);
        case 6:
            return new Shape(BG_COLOR::DARK_GREEN, 4, garbage_shapes[6]);
        case 7:
            return new Shape(BG_COLOR::DARK_GREEN, 4, garbage_shapes[7]);
        case 8:
            return new Shape(BG_COLOR::DARK_GREY, 4, garbage_shapes[8]);
        case 9:
            return new Shape(BG_COLOR::DARK_GREY, 4, garbage_shapes[9]);
        case 10:
            return new Shape(BG_COLOR::DARK_GREY, 3, garbage_shapes[10]);
        case 11:
            return new Shape(BG_COLOR::DARK_GREY, 3, garbage_shapes[11]);
        case 12:
            return new Shape(BG_COLOR::GREY, 4, garbage_shapes[12]);
        case 13:
            return new Shape(BG_COLOR::GREY, 4, garbage_shapes[13]);
        case 14:
            return new Shape(BG_COLOR::GREY, 3, garbage_shapes[14]);
        case 15:
            return new Shape(BG_COLOR::GREY, 3, garbage_shapes[15]);
        default:
            return nullptr;
    }
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


    garbage_shapes = new char *[16];
    // ---------- Level 1 ----------
    garbage_shapes[0] = new char[9]{' ', 'n', 'n',
                                    'n', 'n', ' ',
                                    ' ', 'n', ' '};
    // ---------- Level 1 ----------
    garbage_shapes[1] = new char[9]{'n', 'n', 'n',
                                    ' ', 'n', ' ',
                                    ' ', 'n', ' '};
    // ---------- Level 1 ----------
    garbage_shapes[2] = new char[9]{' ', ' ', 'n',
                                    'n', 'n', 'n',
                                    'n', ' ', ' '};
    // ---------- Level 1 ----------
    garbage_shapes[3] = new char[9]{' ', 'n', ' ',
                                    'n', 'n', 'n',
                                    ' ', 'n', ' '};
    // ---------- Level 2 ----------
    garbage_shapes[4] = new char[9]{'N', ' ', ' ',
                                    'N', 'N', ' ',
                                    ' ', 'N', 'N'};
    // ---------- Level 2 ----------
    garbage_shapes[5] = new char[9]{'N', ' ', 'N',
                                    'N', 'N', 'N',
                                    ' ', ' ', ' '};
    // ---------- Level 2 ----------
    garbage_shapes[6] = new char[16]{' ', ' ', ' ', ' ',
                                     'N', 'N', 'N', ' ',
                                     ' ', ' ', 'N', 'N',
                                     ' ', ' ', ' ', ' '};
    // ---------- Level 2 ----------
    garbage_shapes[7] = new char[16]{' ', 'N', ' ', ' ',
                                     ' ', 'N', ' ', ' ',
                                     ' ', 'N', 'N', ' ',
                                     ' ', 'N', ' ', ' '};
    // ---------- Level 3 ----------
    garbage_shapes[8] = new char[16]{' ', 'v', 'v', ' ',
                                     ' ', 'v', ' ', ' ',
                                     ' ', 'v', 'v', ' ',
                                     ' ', 'v', ' ', ' '};
    // ---------- Level 3 ----------
    garbage_shapes[9] = new char[9]{'v', 'v', ' ',
                                    'v', 'v', ' ',
                                    'v', 'v', ' '};
    // ---------- Level 3 ----------
    garbage_shapes[10] = new char[9]{' ', 'v', ' ',
                                     'v', 'v', 'v',
                                     'v', 'v', ' '};
    // ---------- Level 3 ----------
    garbage_shapes[11] = new char[16]{' ', ' ', ' ', ' ',
                                      'v', 'v', ' ', 'v',
                                      ' ', 'v', 'v', 'v',
                                      ' ', ' ', ' ', ' '};
    // ---------- Level 4 ----------
    garbage_shapes[12] = new char[16]{' ', ' ', 'V', ' ',
                                      ' ', 'V', 'V', ' ',
                                      'V', 'V', ' ', ' ',
                                      'V', ' ', ' ', ' '};
    // ---------- Level 4 ----------
    garbage_shapes[13] = new char[25]{'V', 'V', 'V', 'V', 'V',
                                      'V', 'V', 'V', 'V', 'V',
                                      'V', 'V', 'V', 'V', 'V',
                                      'V', 'V', 'V', 'V', 'V',
                                      'V', 'V', 'V', 'V', 'V'};
    // ---------- Level 4 ----------
    garbage_shapes[13] = new char[25]{' ', ' ', ' ', ' ', ' ',
                                      ' ', 'V', ' ', ' ', 'V',
                                      'V', 'V', 'V', 'V', 'V',
                                      ' ', 'V', ' ', ' ', 'V',
                                      ' ', ' ', ' ', ' ', ' '};
    // ---------- Level 4 ----------
    garbage_shapes[15] = new char[16]{'V', 'V', 'V', 'V',
                                      ' ', 'V', ' ', ' ',
                                      ' ', 'V', 'V', ' ',
                                      ' ', ' ', 'V', ' '};

}
