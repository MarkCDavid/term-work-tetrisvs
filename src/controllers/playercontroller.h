//
// Created by Mark David on 19/04/2019.
//

#ifndef TETRISVS_SRC_CONTROLLERS_PLAYERCONTROLLER_H_
#define TETRISVS_SRC_CONTROLLERS_PLAYERCONTROLLER_H_

#include "controlscheme.h"
#include "abstractcontroller.h"
#include "../keyboard.h"

class PlayerController: public AbstractController {
public:
    explicit PlayerController(ControlScheme scheme);
    void Update(Game* game) override;

private:
    const ControlScheme scheme;
};

#endif //TETRISVS_SRC_CONTROLLERS_PLAYERCONTROLLER_H_
