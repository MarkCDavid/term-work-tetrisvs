//
// Created by Mark David on 26/03/2019.
//

#include "ncurses.h"
#include "gameview.h"
#include "../color.h"

GameView::GameView() {
    shapeFactory = new ShapeFactory();
    int width, height;
    getmaxyx(stdscr, height, width);
    int x_step = width / 6;
    int y_step = height / 4;
    games = new Game *[2];
    games[0] = new Game(x_step, y_step, shapeFactory);
    games[1] = new Game(x_step * 4, y_step, shapeFactory);
}

GameView::~GameView() {
    delete games[0];
    delete games[1];
    delete games;
    delete shapeFactory;
}

void GameView::InitialDraw() {
    clear();
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        for (int i = -1; i <= Board::Width; i++) {
            for (int j = 0; j <= Board::Height; j++) {
                char board_char = cgame->board.GetSymbolAt(i, j);
                if (board_char != Board::EMPTY) {
                    attron(COLOR_PAIR(get_color(board_char)));
                    mvaddch(cgame->yOff + j, cgame->xOff + i, ' ');
                    attroff(COLOR_PAIR(get_color(board_char)));
                }
            }
        }
        for (int i = -1; i <= 5; i++) {
            for (int j = -1; j <= 5; j++) {
                if (i == -1 || j == -1 || i == 5 || j == 5) {
                    attron(COLOR_PAIR(FULL_WHITE));
                    mvaddch(cgame->yNOff + j, cgame->xNOff + i, ' ');
                    attroff(COLOR_PAIR(FULL_WHITE));
                }
            }
        }
        mvaddstr(cgame->yNOff - 2, cgame->xNOff, "NEXT");

        for (int i = -1; i <= 5; i++) {
            for (int j = -1; j <= 5; j++) {
                if (i == -1 || j == -1 || i == 5 || j == 5) {
                    attron(COLOR_PAIR(FULL_WHITE));
                    mvaddch(cgame->yHOff + j, cgame->xHOff + i, ' ');
                    attroff(COLOR_PAIR(FULL_WHITE));
                }
            }
        }
        mvaddstr(cgame->yHOff - 2, cgame->xHOff, "HOLD");
    }
}

void GameView::Draw() {
    DrawBoard();
    DrawShadow();
    DrawShape();
    DrawNext();
    DrawHold();
    DrawScore();
}

int GameView::Update(float delta_time) {
    keyboard.Update();
    c_tick_timer += delta_time;
    for (int game_index = 0; game_index < 2; game_index++) {
        Game *cgame = games[game_index];
        if (cgame->IncreaseTick(tick, delta_time)) {
            cgame->current_shape.Move(Shape::Movement::DOWN);
            if (!cgame->board.IsValidPosition(cgame->current_shape)) {
                cgame->current_shape.Revert();
                int cleared = cgame->board.Place(cgame->current_shape);
                if (cleared > 0) {
                    games[(game_index + 1) % 2]->PutGarbage(cleared);
                    cgame->AddScore(cleared);
                }

                cgame->NextShape();
                if (!cgame->board.IsValidPosition(cgame->current_shape)) {
                    return 1000 + game_index;
                }
            }
        }
    }

// P1 CONTROLS
    if (keyboard.GetKey('w')) {
        if (!games[0]->board.IsValidPosition(games[0]->repr_shape)) {
            return 1000;
        }
        int cleared = games[0]->board.Place(games[0]->repr_shape);
        if (cleared > 0) {
            games[1]->PutGarbage(cleared);
            games[0]->AddScore(cleared);
        }
        games[0]->NextShape();
    }
    if (keyboard.GetKey('s')) {
        games[0]->current_shape.Move(Shape::Movement::DOWN);
        if (!games[0]->board.IsValidPosition(games[0]->current_shape))
            games[0]->current_shape.Revert();
    }
    if (keyboard.GetKey('a')) {
        games[0]->current_shape.Move(Shape::Movement::LEFT);
        if (!games[0]->board.IsValidPosition(games[0]->current_shape))
            games[0]->current_shape.Revert();
    }
    if (keyboard.GetKey('d')) {
        games[0]->current_shape.Move(Shape::Movement::RIGHT);
        if (!games[0]->board.IsValidPosition(games[0]->current_shape))
            games[0]->current_shape.Revert();
    }
    if (keyboard.GetKey('z')) {
        games[0]->HoldShape();
    }
    if (keyboard.GetKey('x')) {
        games[0]->current_shape.Rotate(Shape::Rotation::COUNTERCLOCKWISE);
        if (!games[0]->board.IsValidPosition(games[0]->current_shape))
            games[0]->current_shape.Revert();
    }
    if (keyboard.GetKey('c')) {
        games[0]->current_shape.Rotate(Shape::Rotation::CLOCKWISE);
        if (!games[0]->board.IsValidPosition(games[0]->current_shape))
            games[0]->current_shape.Revert();
    }
// P2 CONTROLS
    if (keyboard.GetKey('o')) {
        if (!games[1]->board.IsValidPosition(games[1]->repr_shape)) {
            return 1001;
        }
        int cleared = games[1]->board.Place(games[1]->repr_shape);
        if (cleared > 0) {
            games[0]->PutGarbage(cleared);
            games[1]->AddScore(cleared);
        }
        games[1]->NextShape();
    }
    if (keyboard.GetKey('l')) {
        games[1]->current_shape.Move(Shape::Movement::DOWN);
        if (!games[1]->board.IsValidPosition(games[1]->current_shape))
            games[1]->current_shape.Revert();
    }
    if (keyboard.GetKey('k')) {
        games[1]->current_shape.Move(Shape::Movement::LEFT);
        if (!games[1]->board.IsValidPosition(games[1]->current_shape))
            games[1]->current_shape.Revert();
    }
    if (keyboard.GetKey(';')) {
        games[1]->current_shape.Move(Shape::Movement::RIGHT);
        if (!games[1]->board.IsValidPosition(games[1]->current_shape))
            games[1]->current_shape.Revert();
    }
    if (keyboard.GetKey(',')) {
        games[1]->HoldShape();
    }
    if (keyboard.GetKey('.')) {
        games[1]->current_shape.Rotate(Shape::Rotation::COUNTERCLOCKWISE);
        if (!games[1]->board.IsValidPosition(games[1]->current_shape))
            games[1]->current_shape.Revert();
    }
    if (keyboard.GetKey('/')) {
        games[1]->current_shape.Rotate(Shape::Rotation::CLOCKWISE);
        if (!games[1]->board.IsValidPosition(games[1]->current_shape))
            games[1]->current_shape.Revert();
    }


    keyboard.Flush();
    return 0;
}

void GameView::DrawShape() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        Board &board = cgame->board;
        Shape &shape = cgame->current_shape;
        for (int i = 0; i < shape.Size(); i++) {
            for (int j = 0; j < shape.Size(); j++) {
                char shape_char = shape.GetSymbolAt(i, j);
                if (shape_char != Board::EMPTY) {
                    attron(COLOR_PAIR(get_color(shape_char)));
                    mvaddch(cgame->yOff + shape.Y() + j, cgame->xOff + shape.X() + i, ' ');
                    attroff(COLOR_PAIR(get_color(shape_char)));
                }
            }
        }
    }
}

void GameView::DrawBoard() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        for (int i = 0; i < Board::Width; i++) {
            for (int j = 0; j < Board::Height; j++) {
                char board_char = cgame->board.GetSymbolAt(i, j);
                attron(COLOR_PAIR(get_color(board_char)));
                mvaddch(cgame->yOff + j, cgame->xOff + i, ' ');
                attroff(COLOR_PAIR(get_color(board_char)));
            }
        }
    }
}

void GameView::DrawShadow() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        Board &board = cgame->board;
        cgame->repr_shape = cgame->current_shape;
        Shape &shape = cgame->repr_shape;
        while (board.IsValidPosition(shape))
            shape.Move(Shape::Movement::DOWN);
        shape.Revert();
        for (int i = 0; i < shape.Size(); i++) {
            for (int j = 0; j < shape.Size(); j++) {
                char shape_char = shape.GetSymbolAt(i, j);
                if (shape_char != Board::EMPTY) {
                    attron(COLOR_PAIR(CYAN_BLACK));
                    mvaddch(cgame->yOff + shape.Y() + j, cgame->xOff + shape.X() + i, '#');
                    attroff(COLOR_PAIR(CYAN_BLACK));
                }
            }
        }
    }
}

void GameView::DrawHold() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        if (cgame->hold_shape.Size() == -1)
            continue;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char s_char = cgame->hold_shape.GetSymbolAt(i, j);
                if (s_char != Board::EMPTY && i < cgame->hold_shape.Size() && j < cgame->hold_shape.Size()) {
                    attron(COLOR_PAIR(get_color(s_char)));
                    mvaddch(cgame->yHOff + j, cgame->xHOff + i, ' ');
                    attroff(COLOR_PAIR(get_color(s_char)));
                } else {
                    attron(COLOR_PAIR(FULL_BLACK));
                    mvaddch(cgame->yHOff + j, cgame->xHOff + i, ' ');
                    attroff(COLOR_PAIR(FULL_BLACK));
                }
            }
        }
    }
}

void GameView::DrawNext() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char s_char = cgame->next_shape.GetSymbolAt(i, j);
                if (s_char != Board::EMPTY && i < cgame->next_shape.Size() && j < cgame->next_shape.Size()) {
                    attron(COLOR_PAIR(get_color(s_char)));
                    mvaddch(cgame->yNOff + j, cgame->xNOff + i, ' ');
                    attroff(COLOR_PAIR(get_color(s_char)));
                } else {
                    attron(COLOR_PAIR(FULL_BLACK));
                    mvaddch(cgame->yNOff + j, cgame->xNOff + i, ' ');
                    attroff(COLOR_PAIR(FULL_BLACK));
                }
            }
        }
    }
}

void GameView::DrawScore() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        int score = cgame->ClearedLines();
        std::string score_str = "Score: " + std::to_string(score);
        mvaddstr(cgame->yNOff + 8, cgame->xNOff, score_str.c_str());
    }
}

void GameView::GetScore(std::map<int, int> &lscore, std::map<int, int> &rscore) {
    lscore = games[0]->GetLineClears();
    rscore = games[1]->GetLineClears();
}
