//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_ABSTRACTVIEW_H
#define TETRISVS_ABSTRACTVIEW_H

#include "../../lib/tge/terminal/abstractterminal.h"
#include "../../lib/tge/input/abstractinput.h"

class AbstractView {
public:
    AbstractView(AbstractTerminal *terminal) : terminal(terminal) {}

    virtual int Update(float delta_time) = 0;

    virtual void InitialDraw() = 0;

    virtual void Draw() = 0;

    void ClearScreen() {
        terminal->InitEmptyBuffer();
        terminal->Draw();
    }

    virtual ~AbstractView() {};

protected:
    AbstractTerminal *terminal;
};


#endif //TETRISVS_ABSTRACTVIEW_H
