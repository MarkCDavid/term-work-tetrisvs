//
// Created by Mark David on 26/03/2019.
//

#include "game.h"


Game::Game(int xOffset, int yOffset) : xOff(xOffset), yOff(yOffset), xNOff(xOff + 14),
                                       yNOff(yOff), xHOff(xOffset - 9), yHOff(yOff) {
    current_shape = ShapeFactory::Instance()->Regular();
    next_shape = ShapeFactory::Instance()->Regular();
    repr_shape = current_shape;
}

void Game::NextShape() {
    hold_changed = false;
    current_shape = next_shape;
    if (garbage_shapes.empty())
        next_shape = ShapeFactory::Instance()->Regular();
    else {
        next_shape = garbage_shapes.front();
        garbage_shapes.pop();
    }
}

void Game::HoldShape() {
    if (hold_changed)
        return;
    hold_changed = true;
    if (hold_shape.Size() == -1) { // TODO: Do proper checking for shape.
        hold_shape = current_shape;
        hold_shape.SetPos(5, 0);
        NextShape();
    } else {
        Shape temp = hold_shape;
        hold_shape = current_shape;
        hold_shape.SetPos(5, 0);
        current_shape = temp;
    }
}

void Game::PutGarbage(int level) {
    garbage_shapes.push(ShapeFactory::Instance()->Garbage(level));
}

void Game::AddLineClear(int clear) {
    cleared += clear;
    line_clears[clear]++;
}

int Game::SpeedModifier() {
    for (int i = 0; i < game_speed.size(); i++)
        if (cleared < game_speed[i])
            return (i + 1);
    return game_speed.size() + 1;
}

bool Game::IncreaseTick(float max, float delta_time) {
    tick += delta_time * SpeedModifier();
    if (tick > max) {
        tick = 0.0f;
        return true;
    }
    return false;
}

int Game::ClearedLines() {
    return cleared;
}

std::map<int, int> Game::GetLineClears() {
    return line_clears;
}
