//
// Created by Mark David on 19/04/2019.
//

#include "playercontroller.h"

PlayerController::PlayerController(ControlScheme scheme)
        :scheme(scheme)
{

}
void PlayerController::Update(Game* game)
{
    if (Keyboard::Instance()->GetKey(scheme.LEFT)) MoveShape(game, Shape::Movement::LEFT);
    if (Keyboard::Instance()->GetKey(scheme.RIGHT)) MoveShape(game, Shape::Movement::RIGHT);
    if (Keyboard::Instance()->GetKey(scheme.DOWN)) MoveShape(game, Shape::Movement::DOWN);
    if (Keyboard::Instance()->GetKey(scheme.DROP)) DropShape(game);
    if (Keyboard::Instance()->GetKey(scheme.ROTATECW)) RotateShape(game, Shape::Rotation::CLOCKWISE);
    if (Keyboard::Instance()->GetKey(scheme.ROTATECCW)) RotateShape(game, Shape::Rotation::COUNTERCLOCKWISE);
    if (Keyboard::Instance()->GetKey(scheme.HOLD)) HoldShape(game);
}
