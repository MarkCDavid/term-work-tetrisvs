//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_SHAPEFACTORY_H
#define TETRISVS_SHAPEFACTORY_H

#include "shape.h"

class ShapeFactory {
private:
    char **regular_shapes;
    char **garbage_shapes;
public:
    ShapeFactory();

    Shape Regular();

    Shape Garbage(int level);
};


#endif //TETRISVS_SHAPEFACTORY_H
