//
// Created by Mark David on 26/03/2019.
//

#include "ncurses.h"
#include "gameview.h"
#include "scoreview.h"
#include "../color.h"
#include "../symbols.h"
#include "../../tetrisvs.h"

GameView::GameView(std::vector<Game*> games)
        :games(games)
{
    int width, height;
    getmaxyx(stdscr, height, width);
    int x_step = width / 6;
    int y_step = height / 4;
}

void GameView::InitialDraw() {
    clear();
    DrawBoard();
    for (auto game : games) {
        for (int i = -1; i <= 5; i++) {
            for (int j = -1; j <= 5; j++) {
                if (i == -1 || j == -1 || i == 5 || j == 5) {
                    attron(COLOR_PAIR(FULL_WHITE));
                    mvaddch(game->yNOff+j, game->xNOff+i, ' ');
                    mvaddch(game->yHOff+j, game->xHOff+i, ' ');
                    attroff(COLOR_PAIR(FULL_WHITE));
                }
            }
        }
        mvaddstr(game->yNOff-2, game->xNOff, "NEXT");
        mvaddstr(game->yHOff-2, game->xHOff, "HOLD");
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

void GameView::Update()
{

}

void GameView::DrawShape() {
    for (auto game: games) {
        Board& board = game->board;
        Shape& shape = game->current_shape;
        for (int i = 0; i < shape.Size(); i++) {
            for (int j = 0; j < shape.Size(); j++) {
                char shape_char = shape.GetSymbolAt(i, j);
                if (shape_char != Symbols::EMPTY) {
                    attron(COLOR_PAIR(get_color(shape_char)));
                    mvaddch(game->yOff+shape.Y()+j, game->xOff+shape.X()+i, ' ');
                    attroff(COLOR_PAIR(get_color(shape_char)));
                }
            }
        }
    }
}

void GameView::DrawBoard() {
    for (auto game: games) {
        for (int i = -1; i<=Board::Width; i++) {
            for (int j = 0; j<=Board::Height; j++) {
                char board_char = game->board.GetSymbolAt(i, j);
                attron(COLOR_PAIR(get_color(board_char)));
                mvaddch(game->yOff+j, game->xOff+i, ' ');
                attroff(COLOR_PAIR(get_color(board_char)));
            }
        }
    }
}

void GameView::DrawShadow() {
    for (auto game: games) {
        Board& board = game->board;
        game->repr_shape = game->current_shape;
        Shape& shape = game->repr_shape;
        while (board.IsValidPosition(shape))
            shape.Move(Shape::Movement::DOWN);
        shape.Revert();
        for (int i = 0; i < shape.Size(); i++) {
            for (int j = 0; j < shape.Size(); j++) {
                char shape_char = shape.GetSymbolAt(i, j);
                if (shape_char != Symbols::EMPTY) {
                    attron(COLOR_PAIR(CYAN_BLACK));
                    mvaddch(game->yOff+shape.Y()+j, game->xOff+shape.X()+i, '#');
                    attroff(COLOR_PAIR(CYAN_BLACK));
                }
            }
        }
    }
}

void GameView::DrawHold() {
    for (auto game: games) {
        if (game->hold_shape.Size()==-1)
            continue;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char s_char = game->hold_shape.GetSymbolAt(i, j);
                if (s_char!=Symbols::EMPTY && i<game->hold_shape.Size() && j<game->hold_shape.Size()) {
                    attron(COLOR_PAIR(get_color(s_char)));
                    mvaddch(game->yHOff+j, game->xHOff+i, ' ');
                    attroff(COLOR_PAIR(get_color(s_char)));
                } else {
                    attron(COLOR_PAIR(FULL_BLACK));
                    mvaddch(game->yHOff+j, game->xHOff+i, ' ');
                    attroff(COLOR_PAIR(FULL_BLACK));
                }
            }
        }
    }
}

void GameView::DrawNext() {
    for (auto game: games) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char s_char = game->next_shape.GetSymbolAt(i, j);
                if (s_char!=Symbols::EMPTY && i<game->next_shape.Size() && j<game->next_shape.Size()) {
                    attron(COLOR_PAIR(get_color(s_char)));
                    mvaddch(game->yNOff+j, game->xNOff+i, ' ');
                    attroff(COLOR_PAIR(get_color(s_char)));
                } else {
                    attron(COLOR_PAIR(FULL_BLACK));
                    mvaddch(game->yNOff+j, game->xNOff+i, ' ');
                    attroff(COLOR_PAIR(FULL_BLACK));
                }
            }
        }
    }
}

void GameView::DrawScore() {
    for (auto game: games) {
        int score = game->ClearedLines();
        std::string score_str = "Score: " + std::to_string(score);
        mvaddstr(game->yNOff+8, game->xNOff, score_str.c_str());
    }
}