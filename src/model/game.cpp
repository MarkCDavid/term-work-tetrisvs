//
// Created by Mark David on 26/03/2019.
//

#include "game.h"

Game::Game(char player_repr)
        :player_repr(player_repr)
{
    current_shape = GetRegular();
    next_shape = GetRegular();
    repr_shape = current_shape;
}

void Game::NextShape() {
    hold_changed = false;
    current_shape = next_shape;
    next_shape = GetNextShape();
}

void Game::HoldShape() {
    if (hold_changed) return;
    hold_changed = true;

    static Shape hold_switch;
    if (hold_shape.Size() == -1) hold_switch = GetNextShape(); // TODO: Do proper checking for shape.
    else hold_switch = hold_shape;

    hold_shape = current_shape;
    hold_shape.SetPos(5, 0);
    current_shape = hold_switch;
}

void Game::PutGarbage(int level) {
    garbage_shapes.push(ShapeFactory::Instance()->Garbage(level));
}

void Game::AddLineClear(int clear) {
    cleared += clear;
    line_clears[clear]++;
}

float Game::CurrentTickLength()
{
    for (auto speed : game_speed)
        if (cleared<speed.first)
            return speed.second;
    return game_speed[game_speed.size()-1].second;
}

bool Game::IncreaseTick()
{
    tick += GameTime::Instance()->DeltaTime();
    if (tick>CurrentTickLength())
        ResetTick();
    return tick == 0.0f;
}

int Game::ClearedLines() {
    return cleared;
}

std::map<int, int> Game::GetLineClears() {
    return line_clears;
}

Shape Game::GetRegular() {
    return ShapeFactory::Instance()->Regular();
}

Shape Game::GetGarbage() {
    Shape next = garbage_shapes.front();
    garbage_shapes.pop();
    return next;
}

Shape Game::GetNextShape() {
    if (garbage_shapes.empty()) return GetRegular();
    else return GetGarbage();
}

void Game::ResetTick()
{
    tick = 0.0f;
}

