//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_SHAPEFACTORY_H
#define TETRISVS_SHAPEFACTORY_H

#include <random>
#include "shape.h"

class ShapeFactory {
private:
    std::random_device rd;


    char **regular_shapes;
    char **garbage_shapes;
public:
    GetRandom(int from, int to);
    ShapeFactory();

    Shape Regular();

    Shape Garbage(int level);
};


#endif //TETRISVS_SHAPEFACTORY_H
