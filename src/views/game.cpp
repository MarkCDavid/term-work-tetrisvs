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
    static int max = 10;
    for (int i = 0; i < max; i++)
        if (cleared < game_speed[i])
            return (i + 1);
    return max + 1;
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

float Game::GetScore(Board &cboard) {
    // Implementation from https://codemyroad.wordpress.com/2013/04/14/tetris-ai-the-near-perfect-player/
    float a = -0.510066;
    float b = 0.760666;
    float c = -0.356630;
    float d = -0.184483;

    int lines = CompleteLines(cboard);
    int holes = HoleCount(cboard);
    auto height_bumpiness = AggregateHeightAndBumpiness(cboard);
    int height = height_bumpiness.first;
    int bumpiness = height_bumpiness.second;

    return a * height + b * lines + c * holes + d * bumpiness;
}

std::pair<int, int> Game::AggregateHeightAndBumpiness(Board &cboard) {
    std::vector<int> heights;
    heights.resize(10);
    int height = 0;

    for (int col = 0; col < 10; col++) {
        for (int row = 0; row < Board::Height; row++) {
            char bchar = cboard.GetSymbolAt(col, row);
            if (bchar != Symbols::EMPTY) {
                heights[col] = Board::Height - row;
                height += heights[col];
                break;
            }
        }
    }
    int bumpiness = 0;
    for (int i = 0; i < 9; i++)
        bumpiness += std::abs(heights[i] - heights[i + 1]);
    return std::make_pair(height, bumpiness);
}

int Game::CompleteLines(Board &cboard) {
    int clear = 0;
    for (int row = 0; row < Board::Height; row++) {
        bool is_clear = true;
        for (int col = 0; col < 10; col++) {
            char bchar = cboard.GetSymbolAt(col, row);
            if (bchar == Symbols::EMPTY) {
                is_clear = false;
                break;
            }
        }
        clear += is_clear;
    }
    return clear;
}

int Game::HoleCount(Board &cboard) {
    int hole_count = 0;
    for (int row = 0; row < Board::Height; row++) {
        for (int col = 0; col < 10; col++) {
            char bchar = cboard.GetSymbolAt(col, row);
            if (bchar == Symbols::EMPTY) {
                for (int i = row; i > 0; i--) {
                    char char_top = cboard.GetSymbolAt(col, i);
                    if (char_top != Symbols::EMPTY) {
                        hole_count++;
                        break;
                    }
                }
            }
        }
    }
    return hole_count;
}
