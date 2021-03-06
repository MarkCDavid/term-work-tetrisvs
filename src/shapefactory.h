//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_SHAPEFACTORY_H
#define TETRISVS_SHAPEFACTORY_H

#include <random>
#include "model/shape.h"

class ShapeFactory {
public:
    static ShapeFactory *Instance();

    Shape Regular();

    Shape Garbage(int level);

protected:
    ShapeFactory();

    ~ShapeFactory();

private:
    static ShapeFactory *instance;
    char **regular_shapes;
    char **garbage_shapes;

};


#endif //TETRISVS_SHAPEFACTORY_H
