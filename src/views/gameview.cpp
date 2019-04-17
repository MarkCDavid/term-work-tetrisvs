//
// Created by Mark David on 26/03/2019.
//

#include "ncurses.h"
#include "gameview.h"
#include "scoreview.h"
#include "../color.h"
#include "../symbols.h"
#include "../../tetrisvs.h"

GameView::GameView(bool bot, bool hard) : bot(bot), hard(hard) {
    int width, height;
    getmaxyx(stdscr, height, width);
    int x_step = width / 6;
    int y_step = height / 4;
    games = new Game *[2];
    games[0] = new Game(x_step, y_step);
    games[1] = new Game(x_step * 4, y_step);
}

GameView::~GameView() {
    delete games[0];
    delete games[1];
    delete games;
}

void GameView::InitialDraw() {
    clear();
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        for (int i = -1; i <= Board::Width; i++) {
            for (int j = 0; j <= Board::Height; j++) {
                char board_char = cgame->board.GetSymbolAt(i, j);
                if (board_char != Symbols::EMPTY) {
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

void GameView::Update(float delta_time) {
    Keyboard::Instance()->Update();
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
                    cgame->AddLineClear(cleared);
                }

                cgame->NextShape();
                cgame->scored = false;
                cgame->score = -1e9;
                if (!cgame->board.IsValidPosition(cgame->current_shape)) {
                    TetrisVS::Instance()->Switch(
                            new ScoreView((game_index == 0) ? (bot) ? 'c' : 'r' : 'l', games[0]->GetLineClears(),
                                          games[1]->GetLineClears()));
                    return;
                }
            }
        }
    }

// P1 CONTROLS
    if (Keyboard::Instance()->GetKey('w')) DropShape(0);
    if (Keyboard::Instance()->GetKey('s')) MoveShape(0, Shape::Movement::DOWN);
    if (Keyboard::Instance()->GetKey('a')) MoveShape(0, Shape::Movement::LEFT);
    if (Keyboard::Instance()->GetKey('d')) MoveShape(0, Shape::Movement::RIGHT);
    if (Keyboard::Instance()->GetKey('z')) games[0]->HoldShape();
    if (Keyboard::Instance()->GetKey('x')) RotateShape(0, Shape::Rotation::COUNTERCLOCKWISE);
    if (Keyboard::Instance()->GetKey('c')) RotateShape(0, Shape::Rotation::CLOCKWISE);
// P2 CONTROLS
    if (!bot) {
        if (Keyboard::Instance()->GetKey('o'))DropShape(1);
        if (Keyboard::Instance()->GetKey('l'))MoveShape(1, Shape::Movement::DOWN);
        if (Keyboard::Instance()->GetKey('k'))MoveShape(1, Shape::Movement::LEFT);
        if (Keyboard::Instance()->GetKey(';'))MoveShape(1, Shape::Movement::RIGHT);
        if (Keyboard::Instance()->GetKey(','))games[1]->HoldShape();
        if (Keyboard::Instance()->GetKey('.'))RotateShape(1, Shape::Rotation::COUNTERCLOCKWISE);
        if (Keyboard::Instance()->GetKey('/'))RotateShape(1, Shape::Rotation::CLOCKWISE);
    } else {
        if (!games[1]->scored) {
            games[1]->scored = true;
            for (int col = -1; col < 10; col++) {
                for (int rot = 0; rot < 4; rot++) {
                    Board cboard = games[1]->board;

                    Shape check = games[1]->current_shape;
                    check.SetPos(col, 0);
                    check.SetRot(rot);
                    if (!cboard.IsValidPosition(check)) continue;
                    while (cboard.IsValidPosition(check))
                        check.Move(Shape::Movement::DOWN);
                    check.Revert();
                    cboard.Place(check);
                    if (hard) {
                        for (int col_c = -1; col_c < 10; col_c++) {
                            for (int rot_c = 0; rot_c < 4; rot_c++) {
                                Board hcboard = cboard;
                                Shape check_next = games[1]->next_shape;
                                check_next.SetPos(col_c, 0);
                                check_next.SetRot(rot_c);
                                if (!hcboard.IsValidPosition(check_next)) continue;
                                while (hcboard.IsValidPosition(check_next))
                                    check_next.Move(Shape::Movement::DOWN);
                                check_next.Revert();
                                hcboard.Place(check_next);

                                float score = games[1]->GetScore(hcboard);
                                if (score > games[1]->score) {
                                    games[1]->score = score;
                                    games[1]->best_move = check;
                                }
                            }
                        }
                    } else {
                        float score = games[1]->GetScore(cboard);
                        if (score > games[1]->score) {
                            games[1]->score = score;
                            games[1]->best_move = check;
                        }
                    }
                }
            }
        }
        int move_delta = games[1]->current_shape.X() - games[1]->best_move.X();
        int rot_delta = games[1]->current_shape.GetRot() - games[1]->best_move.GetRot();
        if (rot_delta != 0) {
            if (move_delta > 0) RotateShape(1, Shape::Rotation::COUNTERCLOCKWISE);
            else RotateShape(1, Shape::Rotation::CLOCKWISE);
        }
        if (rot_delta == 0 && move_delta != 0) {
            if (move_delta > 0) MoveShape(1, Shape::Movement::LEFT);
            else MoveShape(1, Shape::Movement::RIGHT);
        }

        if (move_delta == 0 && rot_delta == 0 && (hard) ? std::cos(c_tick_timer) < 0.5f : std::cos(c_tick_timer) > 0) {
            //DropShape(1);
            MoveShape(1, Shape::Movement::DOWN);
        }

    }
    Keyboard::Instance()->Flush();
}

void GameView::DrawShape() {
    for (int gameIndex = 0; gameIndex < 2; gameIndex++) {
        Game *cgame = games[gameIndex];
        Board &board = cgame->board;
        Shape &shape = cgame->current_shape;
        for (int i = 0; i < shape.Size(); i++) {
            for (int j = 0; j < shape.Size(); j++) {
                char shape_char = shape.GetSymbolAt(i, j);
                if (shape_char != Symbols::EMPTY) {
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
                if (shape_char != Symbols::EMPTY) {
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
                if (s_char != Symbols::EMPTY && i < cgame->hold_shape.Size() && j < cgame->hold_shape.Size()) {
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
                if (s_char != Symbols::EMPTY && i < cgame->next_shape.Size() && j < cgame->next_shape.Size()) {
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

void GameView::DropShape(int board) {
    if (!games[board]->board.IsValidPosition(games[board]->repr_shape)) {
        TetrisVS::Instance()->Switch(new ScoreView((board == 0) ? 'r' : 'l', games[board]->GetLineClears(),
                                                   games[(board + 1) % 2]->GetLineClears()));
        return;
    }
    int cleared = games[board]->board.Place(games[board]->repr_shape);
    if (cleared > 0) {
        games[(board + 1) % 2]->PutGarbage(cleared);
        games[board]->AddLineClear(cleared);
    }
    games[board]->scored = false;
    games[board]->score = -1e9;
    games[board]->NextShape();
}

void GameView::MoveShape(int board, Shape::Movement move) {
    games[board]->current_shape.Move(move);
    if (!games[board]->board.IsValidPosition(games[board]->current_shape))
        games[board]->current_shape.Revert();
}

void GameView::RotateShape(int board, Shape::Rotation rotation) {
    games[board]->current_shape.Rotate(rotation);
    if (!games[board]->board.IsValidPosition(games[board]->current_shape))
        games[board]->current_shape.Revert();
}
