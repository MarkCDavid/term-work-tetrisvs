//
// Created by Mark David on 18/03/2019.
//

#include "abstractcontroller.h"

void AbstractController::RMove(Board *const board) {
    board->current_shape->Move(board, 1);
}

void AbstractController::LMove(Board *const board) {
    board->current_shape->Move(board, -1);
}

void AbstractController::RRotate(Board *const board) {
    board->current_shape->Rotate(board, 1);
}

void AbstractController::LRotate(Board *const board) {
    board->current_shape->Rotate(board, -1);
}

void AbstractController::Lower(Board *const board) {
    board->current_shape->MoveDown(board);
}

void AbstractController::Drop(Board *const board) {
    board->current_shape->DropDown(board);
}

void AbstractController::Hold(Board *const board) {

}
