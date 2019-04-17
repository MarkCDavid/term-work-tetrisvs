//
// Created by Mark David on 26/03/2019.
//

#include "game.h"


Game::Game(int xOffset, int yOffset, ShapeFactory *shapeFactory) : xOff(xOffset), yOff(yOffset), xNOff(xOff + 14),
                                                                   yNOff(yOff), xHOff(xOffset - 9), yHOff(yOff),
                                                                   shapeFactory(shapeFactory) {
    current_shape = shapeFactory->Regular();
    next_shape = shapeFactory->Regular();
    repr_shape = current_shape;
}

void Game::NextShape() {
    hold_changed = false;
    current_shape = next_shape;
    if (garbage_shapes.empty())
        next_shape = shapeFactory->Regular();
    else {
        next_shape = garbage_shapes.front();
        garbage_shapes.pop();
    }
}

void Game::HoldShape() {
    if (hold_changed) return;
    hold_changed = true;
    if (hold_shape.Size() == -1) {
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
    garbage_shapes.push(shapeFactory->Garbage(level));
}

void Game::AddScore(int clear) {
    cleared += clear;
    line_clears[clear]++;
}

int Game::SpeedModifier() {
    for (int i = 0; i < 10; i++)
        if (cleared < game_speed[i]) return (i + 1);
    return 11;
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

int Game::GetScore(Shape &shape) {
    int score = 0;

    int shape_rows = 0;
    for (int row = shape.Y(); row < shape.Y() + shape.Size(); row++) {
        for (int col = shape.X(); col < shape.X() + shape.Size(); col++) {
            char s_char = shape.GetSymbolAt(col, row);
            if (s_char != Symbols::EMPTY) {
                shape_rows++;
                break;
            }
        }
    }

    // Clearing lines is good.
    int cleared_lines = 0;
    for (int row = shape.Y(); row < shape.Y() + shape.Size(); row++) {
        bool row_clear = true;
        for (int col = 0; col < 10 && row_clear; col++) {
            if (col < shape.X() && col >= shape.X() + shape.Size() && board.GetSymbolAt(col, row) == Symbols::EMPTY)
                row_clear = false;
            else if (shape.GetSymbolAt(col - shape.X(), row - shape.Y()) == Symbols::EMPTY)
                row_clear = false;
        }
        if (row_clear) {
            cleared_lines++;
            score += 80 * cleared_lines * (Board::Height - row);
        }
        if (cleared_lines >= 4) score += 10000000;
    }

    // Share as many edges as possible.
    for (int row = shape.Y(); row < shape.Y() + shape.Size(); row++) {
        for (int col = shape.X(); col < shape.X() + shape.Size(); col++) {
            char s_char = shape.GetSymbolAt(col - shape.X(), row - shape.Y());
            if (s_char != Symbols::EMPTY) {
                score += 1000 * (board.GetSymbolAt(col + 1, row) != Symbols::EMPTY);
                score += 1000 * (board.GetSymbolAt(col - 1, row) != Symbols::EMPTY);
                score += 1000 * (board.GetSymbolAt(col, row + 1) != Symbols::EMPTY);
                score += 1000 * (board.GetSymbolAt(col, row - 1) != Symbols::EMPTY);
                // Try not to leave shadows;
                char lower_char = shape.GetSymbolAt(col - shape.X(), row - shape.Y() + 1);
                score -= 4000 * (Board::Height - row) *
                         (board.GetSymbolAt(col, row + 1) == Symbols::EMPTY && lower_char == Symbols::EMPTY);
            }
        }
    }

    // Try not to build on top of holes, if we leave behind something.
    for (int row = shape.Y(); row < shape.Y() + shape.Size(); row++) {
        for (int col = shape.X(); col < shape.X() + shape.Size(); col++) {
            char s_char = shape.GetSymbolAt(col - shape.X(), row - shape.Y());
            if (s_char != Symbols::EMPTY) {
                for (int row_check = row; row_check < Board::Height; row_check++) {
                    char b_char = board.GetSymbolAt(col, row_check);
                    if (b_char == Symbols::EMPTY)
                        score -= 500;
                }
            }
        }
    }

    // Prefer building lower
    score += 5000 * shape.Y();
    return score;
}
