//
// Created by Mark David on 17/04/2019.
//

#include "abstractcontroller.h"

void AbstractController::DropShape(Board &board) {
    game->current_shape = game->repr_shape;
}

void AbstractController::MoveShape(Board &board, Shape::Movement move) {
    game->current_shape.Move(move);
    TryRevert();
}

void AbstractController::RotateShape(Board &board, Shape::Rotation rotation) {
    game->current_shape.Rotate(rotation);
    TryRevert();
}

void AbstractController::TryRevert() {
    if (!game->board.IsValidPosition(game->current_shape))
        game->current_shape.Revert();
}
