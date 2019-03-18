//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_LCONTROLLER_H
#define TETRISVS_LCONTROLLER_H

#include "abstractcontroller.h"


class LController : public AbstractController {

public:
    explicit LController(AbstractInput *input);

    void Apply(Board *const board) override;
};


#endif //TETRISVS_LCONTROLLER_H
