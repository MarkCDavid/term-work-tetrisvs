//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "lib/tge/input/Win32Input.h"
#include "lib/tge/terminal/CMDTerminal.h"

int main() {
    GameEngine *game = new TetrisVS();
    game->SetWindow(81, 50, 10);
    game->Launch();
}

bool TetrisVS::Start() {
    left_board = new Board(14, 10);
    right_board = new Board(g_terminal->GetWidth() - 26, 10);
    DrawSeparatingLine();
    DrawBorders(left_board);
    DrawUpcomingBox(left_board);
    DrawBorders(right_board);
    DrawUpcomingBox(right_board);
    left_board->current_shape = new Shape(BG_COLOR::RED, 5, 0, 4, new char[16]
            {' ', 'F', ' ', ' ',
             ' ', 'F', ' ', ' ',
             ' ', 'F', ' ', ' ',
             ' ', 'F', ' ', ' ',});
    return true;
}

bool TetrisVS::Update(float delta_time) {

    ClearShape(left_board);
    current_tick_time += delta_time * 20;
    if (current_tick_time > tick_time) {
        current_tick_time = 0.0f;
        if (left_board->current_shape->MoveDown(left_board)) {
            delete left_board->current_shape;
            left_board->current_shape = new Shape(BG_COLOR::GREEN, 5, 0, 4, new char[16]
                    {'F', ' ', ' ', 'F',
                     ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ',
                     'F', ' ', ' ', 'F',});
        }

    }

    if (g_in->GetKeyDown('D')) left_board->current_shape->Move(left_board, 1);
    else if (g_in->GetKeyDown('A')) left_board->current_shape->Move(left_board, -1);
    if (g_in->GetKeyDown('S')) left_board->current_shape->MoveDown(left_board);
    if (g_in->GetKeyDown('E')) left_board->current_shape->Rotate(left_board, 1);
    else if (g_in->GetKeyDown('Q')) left_board->current_shape->Rotate(left_board, -1);
    DrawShape(left_board);
    DrawBoard(left_board);
    return true;
}

TetrisVS::TetrisVS() : GameEngine(new Win32Input(), new CMDTerminal()) {


}

bool TetrisVS::Exit() {
    delete left_board;
    delete right_board;
    return GameEngine::Exit();
}

void TetrisVS::DrawBorders(Board const *const board) {
    g_terminal->PutLines({
                                 {board->root_x,                    board->root_y},
                                 {board->root_x,                    board->root_y + Board::Height},
                                 {board->root_x + Board::Width + 1, board->root_y + Board::Height},
                                 {board->root_x + Board::Width + 1, board->root_y}}, ' ', FG_COLOR::WHITE,
                         BG_COLOR::WHITE);
}

void TetrisVS::DrawSeparatingLine() {
    int mid_point = g_terminal->GetWidth() / 2;
    g_terminal->PutLine(mid_point, 0, mid_point, g_terminal->GetHeight(), ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void TetrisVS::DrawUpcomingBox(Board const *const board) {
    int box_size = 6;
    int mid_point = g_terminal->GetWidth() / 2;
    int dir = (board->root_x < mid_point) ? 1 : -1;
    int offset_x = (board->root_x < mid_point) ? 14 : -3;
    g_terminal->PutLines({
                                 {board->root_x + offset_x,                    board->root_y},
                                 {board->root_x + offset_x + (box_size * dir), board->root_y},
                                 {board->root_x + offset_x + (box_size * dir), board->root_y - box_size},
                                 {board->root_x + offset_x,                    board->root_y - box_size},
                                 {board->root_x + offset_x,                    board->root_y}
                         }, ' ', FG_COLOR::WHITE,
                         BG_COLOR::WHITE);
}

void TetrisVS::DrawShape(Board const *const board) {
    for (int i = 0; i < board->current_shape->shape_size; i++)
        for (int j = 0; j < board->current_shape->shape_size; j++) {
            if (board->current_shape->GetCharAt(i, j) != ' ') {
                g_terminal->PutAt(
                        board->root_x + board->current_shape->X() + i,
                        board->root_y + board->current_shape->Y() + j,
                        ' ',
                        FG_COLOR::BLACK,
                        board->current_shape->color);
            }
        }
}

void TetrisVS::ClearShape(Board const *const board) {
    for (int i = 0; i < board->current_shape->shape_size; i++)
        for (int j = 0; j < board->current_shape->shape_size; j++) {
            if (board->current_shape->GetCharAt(i, j) != ' ') {
                g_terminal->PutAt(
                        board->root_x + board->current_shape->X() + i,
                        board->root_y + board->current_shape->Y() + j,
                        ' ',
                        FG_COLOR::BLACK,
                        BG_COLOR::BLACK);
            }
        }
}

void TetrisVS::DrawBoard(Board const *const board) {
    for (int i = 0; i < Board::Width; i++)
        for (int j = 0; j < Board::Height; j++) {
            char symbol = board->Get(i, j);
            if (symbol != ' ' && symbol != 'X') {
                g_terminal->PutAt(
                        board->root_x + i,
                        board->root_y + j,
                        'X',
                        FG_COLOR::BLACK,
                        BG_COLOR::BLUE);
            }
        }
}

