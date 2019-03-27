//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_SHAPEFACTORY_H
#define TETRISVS_SHAPEFACTORY_H

#include <random>
#include "model/shape.h"

class ShapeFactory {
public:
    ShapeFactory();
    Shape Regular();
    Shape Garbage(int level);

private:


    char **regular_shapes;
    char **garbage_shapes;

    int GetRandom(int from, int to);
};


#endif //TETRISVS_SHAPEFACTORY_H
