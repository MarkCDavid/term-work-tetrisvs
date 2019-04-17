//
// Created by Mark David on 27/03/2019.
//

#ifndef TETRISVS_CONTROLSVIEW_H
#define TETRISVS_CONTROLSVIEW_H

#include "abstractview.h"
#include "../keyboard.h"

class ControlsView : public AbstractView {
public:
    void Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;
};


#endif //TETRISVS_CONTROLSVIEW_H
