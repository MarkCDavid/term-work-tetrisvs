//
// Created by Mark David on 17/04/2019.
//

#include "abstractcontroller.h"

void AbstractController::DropShape(Game* game)
{
    game->current_shape = game->repr_shape;
}

void AbstractController::MoveShape(Game* game, Shape::Movement move)
{
    game->current_shape.Move(move);
    TryRevert(game);
}

void AbstractController::RotateShape(Game* game, Shape::Rotation rotation)
{
    game->current_shape.Rotate(rotation);
    TryRevert(game);
}

void AbstractController::HoldShape(Game* game)
{
    game->HoldShape();
}

void AbstractController::TryRevert(Game* game)
{
    if (!game->board.IsValidPosition(game->current_shape))
        game->current_shape.Revert();
}
