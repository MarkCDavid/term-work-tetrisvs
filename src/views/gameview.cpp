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
{
    int width, height;
    getmaxyx(stdscr, height, width);
    int x_step = width/(3*games.size());
    int y_step = height / 4;
    for (int i = 0; i<games.size(); i++)
        gameboards.emplace_back(games[i], BoardOffsets(x_step*(1+3*i), y_step));
}

void GameView::InitialDraw() {
    clear();
    DrawBoard();
    for (auto& game_offset_pair : gameboards) {
        BoardOffsets& offsets = game_offset_pair.second;
        for (int i = -1; i <= 5; i++) {
            for (int j = -1; j <= 5; j++) {
                if (i == -1 || j == -1 || i == 5 || j == 5) {
                    attron(COLOR_PAIR(FULL_WHITE));
                    mvaddch(offsets.yNOff+j, offsets.xNOff+i, ' ');
                    mvaddch(offsets.yHOff+j, offsets.xHOff+i, ' ');
                    attroff(COLOR_PAIR(FULL_WHITE));
                }
            }
        }
        mvaddstr(offsets.yNOff-2, offsets.xNOff, "NEXT");
        mvaddstr(offsets.yHOff-2, offsets.xHOff, "HOLD");
    }
}

void GameView::Draw() {
    CoverShape();
    CoverShadow();
    DrawBoard();
    DrawShadow();
    DrawShape();
    DrawNext();
    DrawHold();
    DrawScore();
    ResetUpdated();
}

void GameView::Update()
{

}

void GameView::DrawShape() {
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        Board& board = game->board;
        Shape& shape = game->current_shape;
        for (int i = 0; i < shape.Size(); i++) {
            for (int j = 0; j < shape.Size(); j++) {
                char shape_char = shape.GetSymbolAt(i, j);
                if (shape_char != Symbols::EMPTY) {
                    attron(COLOR_PAIR(get_color(shape_char)));
                    mvaddch(offsets.yOff+shape.Y()+j, offsets.xOff+shape.X()+i, ' ');
                    attroff(COLOR_PAIR(get_color(shape_char)));
                }

            }
        }
    }
}

void GameView::DrawBoard() {
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        if (!game->board.IsUpdated()) continue;
        for (int i = -1; i<=Board::Width; i++) {
            for (int j = 0; j<=Board::Height; j++) {
                char board_char = game->board.GetSymbolAt(i, j);
                attron(COLOR_PAIR(get_color(board_char)));
                mvaddch(offsets.yOff+j, offsets.xOff+i, ' ');
                attroff(COLOR_PAIR(get_color(board_char)));
            }
        }
    }
}

void GameView::DrawShadow() {
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
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
                    mvaddch(offsets.yOff+shape.Y()+j, offsets.xOff+shape.X()+i, '#');
                    attroff(COLOR_PAIR(CYAN_BLACK));
                }
            }
        }
    }
}

void GameView::DrawHold() {
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        if (game->hold_shape.Size()==-1)
            continue;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char s_char = game->hold_shape.GetSymbolAt(i, j);
                if (s_char!=Symbols::EMPTY && i<game->hold_shape.Size() && j<game->hold_shape.Size()) {
                    attron(COLOR_PAIR(get_color(s_char)));
                    mvaddch(offsets.yHOff+j, offsets.xHOff+i, ' ');
                    attroff(COLOR_PAIR(get_color(s_char)));
                } else {
                    attron(COLOR_PAIR(FULL_BLACK));
                    mvaddch(offsets.yHOff+j, offsets.xHOff+i, ' ');
                    attroff(COLOR_PAIR(FULL_BLACK));
                }
            }
        }
    }
}

void GameView::DrawNext() {
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char s_char = game->next_shape.GetSymbolAt(i, j);
                if (s_char!=Symbols::EMPTY && i<game->next_shape.Size() && j<game->next_shape.Size()) {
                    attron(COLOR_PAIR(get_color(s_char)));
                    mvaddch(offsets.yNOff+j, offsets.xNOff+i, ' ');
                    attroff(COLOR_PAIR(get_color(s_char)));
                } else {
                    attron(COLOR_PAIR(FULL_BLACK));
                    mvaddch(offsets.yNOff+j, offsets.xNOff+i, ' ');
                    attroff(COLOR_PAIR(FULL_BLACK));
                }
            }
        }
    }
}

void GameView::DrawScore() {
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        int score = game->ClearedLines();
        std::string score_str = "Score: " + std::to_string(score);
        mvaddstr(offsets.yNOff+8, offsets.xNOff, score_str.c_str());
    }
}
void GameView::CoverShape()
{
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        Board& board = game->board;
        Shape& shape = game->prev_shape;
        if (!game->GetOld()) continue;
        for (int i = 0; i<shape.Size(); i++) {
            for (int j = 0; j<shape.Size(); j++) {
                if (shape.GetSymbolAt(i, j)!=Symbols::EMPTY) {
                    attron(COLOR_PAIR(Color::FULL_BLACK));
                    mvaddch(offsets.yOff+shape.Y()+j, offsets.xOff+shape.X()+i, ' ');
                    attroff(COLOR_PAIR(Color::FULL_BLACK));
                }
            }
        }
    }
}

void GameView::CoverShadow()
{
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        Board& board = game->board;
        Shape& shape = game->repr_shape;
        if (!game->GetOld()) continue;
        for (int i = 0; i<shape.Size(); i++) {
            for (int j = 0; j<shape.Size(); j++) {
                char b_char = board.GetSymbolAt(shape.X()+i, shape.Y()+j);
                char s_char = shape.GetSymbolAt(i, j);
                if (s_char!=Symbols::EMPTY && b_char==Symbols::EMPTY) {
                    attron(COLOR_PAIR(Color::FULL_BLACK));
                    mvaddch(offsets.yOff+shape.Y()+j, offsets.xOff+shape.X()+i, ' ');
                    attroff(COLOR_PAIR(Color::FULL_BLACK));
                }
            }
        }
    }
}
void GameView::ResetUpdated()
{
    for (auto& game_offset_pair : gameboards) {
        Game* game = game_offset_pair.first;
        BoardOffsets& offsets = game_offset_pair.second;
        Board& board = game->board;
        game->ResetOld();
        board.ResetUpdate();
    }
}
