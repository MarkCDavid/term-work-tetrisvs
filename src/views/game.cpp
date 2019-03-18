//
// Created by Mark David on 18/03/2019.
//

#include "game.h"
#include "../controllers/lcontroller.h"
#include "../controllers/rcontroller.h"


void Game::Update(float delta_time) {
    c_tick_time += delta_time * 10;
    if (c_tick_time > tick_time) {
        c_tick_time = 0.0f;

        if (l_board->current_shape->MoveDown(l_board)) {
            int garbage_level = RemoveRows(l_board);
            if (garbage_level > 0) { PutGarbage(r_shapes, garbage_level); }
            delete l_board->current_shape;
            l_board->current_shape = GetNext(l_shapes);
        }
        if (r_board->current_shape->MoveDown(r_board)) {
            int garbage_level = RemoveRows(r_board);
            if (garbage_level > 0) { PutGarbage(l_shapes, garbage_level); }
            delete r_board->current_shape;
            r_board->current_shape = GetNext(r_shapes);
        }
    }
    l_controller->Apply(l_board);
    r_controller->Apply(r_board);
}


void Game::InitialDraw() {
    DrawSeparatingLine();

    DrawBorders(l_board);
    DrawUpcomingBox(l_board);
    DrawHoldBox(l_board);

    DrawBorders(r_board);
    DrawUpcomingBox(r_board);
    DrawHoldBox(r_board);

}

void Game::Draw() {
    ClearBoard(l_board);
    DrawBoard(l_board);
    DrawShape(l_board);
    DrawUpcoming(l_board, l_shapes.front());

    ClearBoard(r_board);
    DrawBoard(r_board);
    DrawShape(r_board);
    DrawUpcoming(r_board, r_shapes.front());
}

void Game::DrawBorders(Board const *const board) {
    terminal->PutLines({{board->root_x,                    board->root_y},
                        {board->root_x,                    board->root_y + Board::Height},
                        {board->root_x + Board::Width + 1, board->root_y + Board::Height},
                        {board->root_x + Board::Width + 1, board->root_y}},
                       ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void Game::DrawSeparatingLine() {
    int mid_point = terminal->GetWidth() / 2;
    terminal->PutLine(
            mid_point, 0,
            // FIXME: Error inside the game engine, if no -1, it draw random stuff on rboard.
            mid_point, terminal->GetHeight() - 1,
            ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void Game::DrawUpcomingBox(Board const *const board) {
    int box_size = 6;
    int mid_point = terminal->GetWidth() / 2;
    int dir = (board->root_x < mid_point) ? 1 : -1;
    int offset_x = (board->root_x < mid_point) ? 14 : -3;
    int text_pos = (board->root_x + offset_x + board->root_x + offset_x + (box_size * dir)) / 2;
    terminal->PutStringAt(text_pos - 2, board->root_y + 2, "NEXT", FG_COLOR::GREY, BG_COLOR::BLACK);
    terminal->PutLines({{board->root_x + offset_x,                    board->root_y},
                        {board->root_x + offset_x + (box_size * dir), board->root_y},
                        {board->root_x + offset_x + (box_size * dir), board->root_y - box_size},
                        {board->root_x + offset_x,                    board->root_y - box_size},
                        {board->root_x + offset_x,                    board->root_y}},
                       ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}

void Game::DrawHoldBox(Board const *const board) {
    int box_size = 6;
    int mid_point = terminal->GetWidth() / 2;
    int dir = (board->root_x < mid_point) ? -1 : 1;
    int offset_x = (board->root_x < mid_point) ? -3 : 14;
    int text_pos = (board->root_x + offset_x + board->root_x + offset_x + (box_size * dir)) / 2;
    terminal->PutStringAt(text_pos - 2, board->root_y + 2, "HOLD", FG_COLOR::GREY, BG_COLOR::BLACK);
    terminal->PutLines({{board->root_x + offset_x,                    board->root_y},
                        {board->root_x + offset_x + (box_size * dir), board->root_y},
                        {board->root_x + offset_x + (box_size * dir), board->root_y - box_size},
                        {board->root_x + offset_x,                    board->root_y - box_size},
                        {board->root_x + offset_x,                    board->root_y}},
                       ' ', FG_COLOR::WHITE, BG_COLOR::WHITE);
}


void Game::DrawShape(Board const *const board) {
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

void Game::DrawBoard(Board const *const board) {
    for (int i = 1; i <= Board::Width; i++)
        for (int j = 0; j < Board::Height; j++) {
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

void Game::ClearBoard(Board const *const board) {
    for (int i = 1; i <= Board::Width; i++)
        for (int j = 0; j < Board::Height; j++)
            terminal->PutAt(board->root_x + i, board->root_y + j, ' ', FG_COLOR::BLACK, BG_COLOR::BLACK);
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
            return BG_COLOR::DARK_YELLOW;
        case 'G':
            return BG_COLOR::GREEN;
        case 'R':
            return BG_COLOR::RED;
        case 'V':
            return BG_COLOR::GREY;
        case 'v':
            return BG_COLOR::DARK_GREY;
        case 'N':
            return BG_COLOR::DARK_GREEN;
        case 'n':
            return BG_COLOR::DARK_RED;
        case ' ':
            return BG_COLOR::BLACK;
        default:
            return BG_COLOR::WHITE;
    }
}

Game::Game(AbstractTerminal *terminal, AbstractInput *input) : AbstractView(terminal) {
    shape_factory = new ShapeFactory();
    int xstep = terminal->GetWidth() / 6;
    int ystep = terminal->GetHeight() / 5;
    int l_offset = xstep;
    int r_offset = terminal->GetWidth() - xstep - (Board::Width + 2);
    l_board = new Board(l_offset, ystep);
    r_board = new Board(r_offset, ystep);
    l_board->current_shape = GetNext(l_shapes);
    r_board->current_shape = GetNext(r_shapes);
    l_controller = new LController(input);
    r_controller = new RController(input);
}

int Game::RemoveRows(Board *board) {
    int removed_lines = 0;
    for (int i = Board::Height - 1; i >= 0; i--) {
        bool line_full = true;
        for (int j = 1; j <= Board::Width; j++) {
            char symbol = board->Get(j, i);
            if (symbol == ' ' || symbol == 'X') {
                line_full = false;
                break;
            }
        }
        if (line_full) {
            removed_lines++;
            for (int y = i; y > 0; y--) {
                for (int x = 1; x <= Board::Width; x++) {
                    char from = board->Get(x, y - 1);
                    if (y - 1 == 0) from = ' ';
                    board->Put(x, y, from);
                }
            }
            i++;
        }
    }
    return (removed_lines > 4) ? 4 : removed_lines;
}

void Game::DrawUpcoming(Board const *const board, Shape *next) {
    int mid_point = terminal->GetWidth() / 2;
    int offset_x = (board->root_x < mid_point) ? 15 : -8;
    int offset_y = -5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            terminal->PutAt(board->root_x + offset_x + i, board->root_y + offset_y + j, ' ', FG_COLOR::BLACK,
                            BG_COLOR::BLACK);
        }
    }
    for (int i = 0; i < next->shape_size; i++) {
        for (int j = 0; j < next->shape_size; j++) {
            char symbol = next->GetCharAt(i, j);
            terminal->PutAt(board->root_x + offset_x + i, board->root_y + offset_y + j, ' ', FG_COLOR::BLACK,
                            GetColor(symbol));
        }
    }
}

void Game::DrawHold(Board const *const board) {

}

Shape *Game::GetNext(std::queue<Shape *> &shape_queue) {
    if (shape_queue.empty()) {
        shape_queue.push(shape_factory->Regular());
        return shape_factory->Regular();
    } else {
        Shape *next_shape = shape_queue.front();
        shape_queue.pop();
        if (shape_queue.empty())
            shape_queue.push(shape_factory->Regular());
        return next_shape;
    }
}

void Game::PutGarbage(std::queue<Shape *> &shape_queue, int level) {
    shape_queue.push(shape_factory->Garbage(level));
}




