//
// Created by Mark David on 18/03/2019.
//

#include "rcontroller.h"
// TODO: Create an abstraction for Windows keycodes inside the game engine.
#include "windows.h"

void RController::Apply(Board *const board) {
    if (input->GetKeyDown(VK_LEFT)) LMove(board);
    if (input->GetKeyDown(VK_RIGHT)) RMove(board);
    if (input->GetKeyDown(VK_DOWN)) Lower(board);
    if (input->GetKeyDown(VK_UP)) Drop(board);
    if (input->GetKeyDown('>')) LRotate(board);
    if (input->GetKeyDown('?')) RRotate(board);
    if (input->GetKeyDown(VK_RCONTROL)) Drop(board);
}

RController::RController(AbstractInput *input) : AbstractController(input) {

}


