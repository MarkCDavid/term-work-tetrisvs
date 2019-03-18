//
// Created by Mark David on 18/03/2019.
//

#include "lcontroller.h"
// TODO: Create an abstraction for Windows keycodes inside the game engine.
#include "windows.h"

void LController::Apply(Board *const board) {
    if (input->GetKeyDown('A')) LMove(board);
    if (input->GetKeyDown('D')) RMove(board);
    if (input->GetKeyDown('S')) Lower(board);
    if (input->GetKeyDown('W')) Drop(board);
    if (input->GetKeyDown('C')) LRotate(board);
    if (input->GetKeyDown('V')) RRotate(board);
    if (input->GetKeyDown(VK_LMENU)) Hold(board);
}

LController::LController(AbstractInput *input) : AbstractController(input) {

}


