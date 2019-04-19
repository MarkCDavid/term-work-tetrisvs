//
// Created by Mark David on 18/04/2019.
//

#ifndef TETRISVS_GAMEMANAGER_H
#define TETRISVS_GAMEMANAGER_H

#include "../managers/abstractmanager.h"
#include "../model/controllerpair.h"
#include "../keyboard.h"
#include <vector>

class GameManager: public AbstractManager {
public:
    GameManager(std::vector<ControllerPair<Game>> games);
    void Update() override;

private:
    std::vector<ControllerPair<Game>> games;
};

#endif //TETRISVS_GAMEMANAGER_H
