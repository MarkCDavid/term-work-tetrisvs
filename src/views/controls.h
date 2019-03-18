//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_CONTROLS_H
#define TETRISVS_CONTROLS_H

#include "abstractview.h"

class Controls : public AbstractView {
private:
    AbstractInput *input;
public:

    Controls(AbstractTerminal *terminal, AbstractInput *input);

    int Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;
};


#endif //TETRISVS_CONTROLS_H
