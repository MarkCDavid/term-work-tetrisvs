//
// Created by Mark David on 19/04/2019.
//

#ifndef TETRISVS_MENUMANAGER_H
#define TETRISVS_MENUMANAGER_H

#include "abstractmanager.h"
#include "gamemanager.h"
#include "../views/gameview.h"
#include "../controllers/playercontroller.h"
#include "../controllers/controlscheme.h"
#include "../controllers/computercontroller.h"
#include "../model/scoring/neuralscoring.h"
#include "../keyboard.h"
#include "../../tetrisvs.h"
#include "../model/menudata.h"

class MenuManager: public AbstractManager {
public:
    explicit MenuManager(MenuData* data);
    ~MenuManager() override;
    void Update() override;

private:
    MenuData* data;

    std::vector<std::string> menu_options;
};

#endif //TETRISVS_MENUMANAGER_H
