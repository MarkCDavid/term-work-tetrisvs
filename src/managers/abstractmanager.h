//
// Created by Mark David on 18/04/2019.
//

#ifndef TETRISVS_ABSTRACTMANAGER_H
#define TETRISVS_ABSTRACTMANAGER_H

#include "../views/abstractview.h"

class AbstractManager {
public:
    virtual void Update() = 0;
    virtual ~AbstractManager() = default;
};

#endif //TETRISVS_ABSTRACTMANAGER_H
