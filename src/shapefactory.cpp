//
// Created by Mark David on 18/03/2019.
//

#include "shapefactory.h"
#include "random.h"
#include <chrono>


Shape ShapeFactory::Regular() {

    int choice = Random::GetRandom(0, 7);
    switch (choice) {
        case 0:
        default:
            return Shape(4, regular_shapes[0]);
        case 1:
            return Shape(2, regular_shapes[1]);
        case 2:
            return Shape(3, regular_shapes[2]);
        case 3:
            return Shape(3, regular_shapes[3]);
        case 4:
            return Shape(3, regular_shapes[4]);
        case 5:
            return Shape(3, regular_shapes[5]);
        case 6:
            return Shape(3, regular_shapes[6]);
    }
}

Shape ShapeFactory::Garbage(int level) {
    level = (level < 1) ? 1 : level;
    level = (level > 4) ? 4 : level;
    int choice = Random::GetRandom((level - 1) * 4, level * 4 - 1);
    switch (choice) {
        case 0:
        default:
            return Shape(3, garbage_shapes[0]);
        case 1:
            return Shape(3, garbage_shapes[1]);
        case 2:
            return Shape(3, garbage_shapes[2]);
        case 3:
            return Shape(3, garbage_shapes[3]);
        case 4:
            return Shape(3, garbage_shapes[4]);
        case 5:
            return Shape(3, garbage_shapes[5]);
        case 6:
            return Shape(4, garbage_shapes[6]);
        case 7:
            return Shape(4, garbage_shapes[7]);
        case 8:
            return Shape(4, garbage_shapes[8]);
        case 9:
            return Shape(3, garbage_shapes[9]);
        case 10:
            return Shape(3, garbage_shapes[10]);
        case 11:
            return Shape(4, garbage_shapes[11]);
        case 12:
            return Shape(4, garbage_shapes[12]);
        case 13:
            return Shape(5, garbage_shapes[13]);
        case 14:
            return Shape(5, garbage_shapes[14]);
        case 15:
            return Shape(4, garbage_shapes[15]);
    }
}

ShapeFactory::ShapeFactory() {

    regular_shapes = new char *[7];
    garbage_shapes = new char *[16];
    // ---------- I shape ----------
    regular_shapes[0] = new char[16]{' ', 'B', ' ', ' ',
                                     ' ', 'B', ' ', ' ',
                                     ' ', 'B', ' ', ' ',
                                     ' ', 'B', ' ', ' '};
    // ---------- O shape ----------
    regular_shapes[1] = new char[4]{'C', 'C',
                                    'C', 'C'};
    // ---------- T shape ----------
    regular_shapes[2] = new char[9]{'M', 'M', 'M',
                                    ' ', 'M', ' ',
                                    ' ', ' ', ' '};
    // ---------- J shape ----------
    regular_shapes[3] = new char[9]{' ', 'R', ' ',
                                    ' ', 'R', ' ',
                                    'R', 'R', ' '};
    // ---------- L shape ----------
    regular_shapes[4] = new char[9]{' ', 'Y', ' ',
                                    ' ', 'Y', ' ',
                                    ' ', 'Y', 'Y',};
    // ---------- S shape ----------
    regular_shapes[5] = new char[9]{' ', 'G', 'G',
                                    'G', 'G', ' ',
                                    ' ', ' ', ' '};
    // ---------- Z shape ----------
    regular_shapes[6] = new char[9]{'B', 'B', ' ',
                                    ' ', 'B', 'B',
                                    ' ', ' ', ' '};



    // ---------- Level 1 ----------
    garbage_shapes[0] = new char[9]{'R', 'R', 'R',
                                    'R', 'R', ' ',
                                    ' ', ' ', ' '};
    // ---------- Level 1 ----------
    garbage_shapes[1] = new char[9]{'R', 'R', 'R',
                                    ' ', 'R', ' ',
                                    ' ', 'R', ' '};
    // ---------- Level 1 ----------
    garbage_shapes[2] = new char[9]{' ', ' ', 'R',
                                    ' ', 'R', 'R',
                                    'R', 'R', ' '};
    // ---------- Level 1 ----------
    garbage_shapes[3] = new char[9]{'R', 'R', 'R',
                                    'R', ' ', ' ',
                                    'R', ' ', ' '};
    // ---------- Level 2 ----------
    garbage_shapes[4] = new char[9]{'G', 'G', ' ',
                                    ' ', 'G', ' ',
                                    ' ', 'G', 'G'};
    // ---------- Level 2 ----------
    garbage_shapes[5] = new char[9]{'G', ' ', 'G',
                                    'G', 'G', 'G',
                                    ' ', ' ', ' '};
    // ---------- Level 2 ----------
    garbage_shapes[6] = new char[16]{' ', ' ', ' ', ' ',
                                     'G', 'G', 'G', ' ',
                                     ' ', ' ', 'G', 'G',
                                     ' ', ' ', ' ', ' '};
    // ---------- Level 2 ----------
    garbage_shapes[7] = new char[16]{' ', 'G', ' ', ' ',
                                     ' ', 'G', ' ', ' ',
                                     ' ', 'G', 'G', ' ',
                                     ' ', 'G', ' ', ' '};

    // ---------- Level 3 ----------
    garbage_shapes[8] = new char[16]{'M', 'M', 'M', ' ',
                                     ' ', 'M', ' ', ' ',
                                     ' ', 'M', 'M', ' ',
                                     ' ', 'M', ' ', ' '};
    // ---------- Level 3 ----------
    garbage_shapes[9] = new char[9]{'M', 'M', 'M',
                                    'M', ' ', 'M',
                                    'M', 'M', 'M'};
    // ---------- Level 3 ----------
    garbage_shapes[10] = new char[9]{'M', ' ', ' ',
                                     'M', 'M', 'M',
                                     'M', 'M', ' '};
    // ---------- Level 3 ----------
    garbage_shapes[11] = new char[16]{' ', ' ', ' ', 'M',
                                      'M', 'M', ' ', 'M',
                                      ' ', 'M', 'M', 'M',
                                      ' ', 'M', ' ', ' '};
    // ---------- Level 4 ----------
    garbage_shapes[12] = new char[16]{' ', ' ', 'B', ' ',
                                      ' ', 'B', 'B', 'B',
                                      'B', 'B', 'B', ' ',
                                      'B', ' ', 'B', 'B'};
    // ---------- Level 4 ----------
    garbage_shapes[13] = new char[25]{'B', 'B', 'B', 'B', 'B',
                                      'B', 'B', 'B', 'B', 'B',
                                      'B', 'B', 'B', 'B', 'B',
                                      'B', 'B', 'B', 'B', 'B',
                                      'B', 'B', 'B', 'B', 'B'};
    // ---------- Level 4 ----------
    garbage_shapes[14] = new char[25]{' ', ' ', ' ', ' ', 'B',
                                      ' ', 'B', ' ', ' ', 'B',
                                      'B', 'B', 'B', 'B', 'B',
                                      ' ', 'B', ' ', ' ', 'B',
                                      ' ', 'B', ' ', ' ', ' '};
    // ---------- Level 4 ----------
    garbage_shapes[15] = new char[16]{'B', 'B', 'B', 'B',
                                      ' ', 'B', ' ', ' ',
                                      ' ', 'B', 'B', 'B',
                                      ' ', ' ', 'B', ' '};

}

ShapeFactory *ShapeFactory::Instance() {
    if (instance == nullptr)
        instance = new ShapeFactory();
    return instance;
}

ShapeFactory::~ShapeFactory() {
    delete instance;
}

