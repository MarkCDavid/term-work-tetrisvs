//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_RCONTROLLER_H
#define TETRISVS_RCONTROLLER_H

#include "abstractcontroller.h"

class RController : public AbstractController {
public:
    explicit RController(AbstractInput *input);

    void Apply(Board *const board) override;
};


#endif //TETRISVS_RCONTROLLER_H
