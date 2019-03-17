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
    DrawBoard(left_board);
    DrawUpcomingBox(left_board);
    DrawBoard(right_board);
    DrawUpcomingBox(right_board);
    return true;
}

bool TetrisVS::Update(float delta_time) {
    return true;
}

TetrisVS::TetrisVS() : GameEngine(new Win32Input(), new CMDTerminal()) {


}

bool TetrisVS::Exit() {
    delete left_board;
    delete right_board;
    return GameEngine::Exit();
}

void TetrisVS::DrawBoard(Board const *const board) {
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

