//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_MENU_H
#define TETRISVS_MENU_H

#include "abstractview.h"
#include "../../lib/tge/input/abstractinput.h"

class Menu : public AbstractView {
private:
    AbstractInput *input;
    int prev_menu_item = 0;
    int menu_item = 0;
public:
    Menu(AbstractTerminal *terminal, AbstractInput *input);

    void Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;
};


#endif //TETRISVS_MENU_H
