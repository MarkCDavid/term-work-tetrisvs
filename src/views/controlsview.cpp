//
// Created by Mark David on 27/03/2019.
//

#include "controlsview.h"


int ControlsView::Update(float delta_time) {
    keyboard.Update();
    if (keyboard.GetKey('f')) {
        return 1100;
    };
    keyboard.Flush();
    return 0;
}

void ControlsView::InitialDraw() {
    clear();
    int x_root = 0;
    int y_root = 0;

    mvaddstr(y_root + 0, x_root, "------Player 1 controls------");
    mvaddstr(y_root + 1, x_root, "Move left: A");
    mvaddstr(y_root + 2, x_root, "Move right: D");
    mvaddstr(y_root + 3, x_root, "Drop: W");
    mvaddstr(y_root + 4, x_root, "Move down: S");
    mvaddstr(y_root + 5, x_root, "Rotate (CCW): X");
    mvaddstr(y_root + 6, x_root, "Rotate (CW): C");
    mvaddstr(y_root + 7, x_root, "Hold: Z");
    mvaddstr(y_root + 9, x_root, "------Player 2 controls------");
    mvaddstr(y_root + 10, x_root, "Move left: K");
    mvaddstr(y_root + 11, x_root, "Move right: O");
    mvaddstr(y_root + 12, x_root, "Drop: ;");
    mvaddstr(y_root + 13, x_root, "Move down: L");
    mvaddstr(y_root + 14, x_root, "Rotate (CCW): .");
    mvaddstr(y_root + 15, x_root, "Rotate (CW): /");
    mvaddstr(y_root + 16, x_root, "Hold: ,");
    mvaddstr(y_root + 19, x_root, "Press F to return to menu.");

}

void ControlsView::Draw() {

}
