//
// Created by Mark David on 18/03/2019.
//

#include "game.h"
#include "../controllers/lcontroller.h"
#include "../controllers/rcontroller.h"


void Game::Update(float delta_time) {
    c_tick_time += delta_time;
    if (c_tick_time > tick_time) {
        c_tick_time = 0.0f;
        if (!l_board->current_shape->MoveDown(l_board)) {
            l_board->current_shape = shape_factory->Regular();
        }
        if (!r_board->current_shape->MoveDown(r_board)) {
            r_board->current_shape = shape_factory->Regular();
        }
    }
    l_controller->Apply(l_board);
    r_controller->Apply(r_board);
}


void Game::InitialDraw(AbstractTerminal *terminal) {
    DrawSeparatingLine(terminal);

    DrawBorders(terminal, l_board);
    DrawUpcomingBox(terminal, l_board);

    DrawBorders(terminal, r_board);
    DrawUpcomingBox(terminal, r_board);

}


void Game::Draw(AbstractTerminal *terminal) {
    ClearBoard(terminal, l_board);
    DrawBoard(terminal, l_board);
    DrawShape(terminal, l_board);

    ClearBoard(terminal, r_board);
    DrawBoard(terminal, r_board);
    DrawShape(terminal, r_board);
}

void Game::DrawBorders(AbstractTerminal *terminal, Board const *const board) {
    terminal->PutLines({{board->root_x,                    board->root_y},
                        {board->root_x,                    board->root_y + Board::Height},
                        {board->root_x + Board::Width + 1, board->root_y + Board::Height},
                        {board->root_x + Board::Width + 1, board->root_y}},
                       ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void Game::DrawSeparatingLine(AbstractTerminal *terminal) {
    int mid_point = terminal->GetWidth() / 2;
    terminal->PutLine(
            mid_point, 0,
            mid_point, terminal->GetHeight(),
            ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void Game::DrawUpcomingBox(AbstractTerminal *terminal, Board const *const board) {
    int box_size = 6;
    int mid_point = terminal->GetWidth() / 2;
    int dir = (board->root_x < mid_point) ? 1 : -1;
    int offset_x = (board->root_x < mid_point) ? 14 : -3;
    terminal->PutLines({{board->root_x + offset_x,                    board->root_y},
                        {board->root_x + offset_x + (box_size * dir), board->root_y},
                        {board->root_x + offset_x + (box_size * dir), board->root_y - box_size},
                        {board->root_x + offset_x,                    board->root_y - box_size},
                        {board->root_x + offset_x,                    board->root_y}},
                       ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void Game::DrawShape(AbstractTerminal *terminal, Board const *const board) {
    for (int i = 0; i < board->current_shape->shape_size; i++)
        for (int j = 0; j < board->current_shape->shape_size; j++) {
            if (board->current_shape->GetCharAt(i, j) != ' ') {
                terminal->PutAt(
                        board->root_x + board->current_shape->X() + i,
                        board->root_y + board->current_shape->Y() + j,
                        ' ',
                        FG_COLOR::BLACK,
                        board->current_shape->color);
            }
        }
}


void Game::DrawBoard(AbstractTerminal *terminal, Board const *const board) {
    for (int i = 1; i <= Board::Width; i++)
        for (int j = 1; j < Board::Height; j++) {
            char symbol = board->Get(i, j);
            if (symbol != ' ') {
                terminal->PutAt(
                        board->root_x + i,
                        board->root_y + j,
                        ' ',
                        FG_COLOR::BLACK,
                        GetColor(symbol));
            }
        }
}

void Game::ClearBoard(AbstractTerminal *terminal, Board const *const board) {
    for (int i = 1; i < Board::Width; i++)
        for (int j = 1; j < Board::Height; j++)
            terminal->PutAt(i, j, ' ', FG_COLOR::BLACK, BG_COLOR::BLACK);
}

BG_COLOR Game::GetColor(const char symbol) const {
    switch (symbol) {
        case 'C':
            return BG_COLOR::CYAN;
        case 'Y':
            return BG_COLOR::YELLOW;
        case 'M':
            return BG_COLOR::MAGENTA;
        case 'b':
            return BG_COLOR::DARK_BLUE;
        case 'y':
            return BG_COLOR::YELLOW;
        case 'G':
            return BG_COLOR::GREEN;
        case 'R':
            return BG_COLOR::RED;
        default:
            return BG_COLOR::WHITE;
    }
}

Game::Game(AbstractInput *input) {
    l_controller = new LController(input);
    r_controller = new RController(input);
}




