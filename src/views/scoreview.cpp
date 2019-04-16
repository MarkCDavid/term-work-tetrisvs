//
// Created by Mark David on 27/03/2019.
//

#include "ncurses.h"
#include "scoreview.h"
#include "menu.h"
#include "../../tetrisvs.h"
#include <utility>

void ScoreView::Update(float delta_time) {
    keyboard.Update();
    if (keyboard.GetKey('f')) {
        TetrisVS::Instance()->Switch(new Menu());
        return;
    }
    keyboard.Flush();
}

void ScoreView::InitialDraw() {
    clear();
    int x_root = 0;
    int y_root = 0;
    std::string win_str = (winner == 'l') ? "Player 1 is winner!" : "Player 2 is winner!";
    mvaddstr(y_root, x_root, win_str.c_str());
    mvaddstr(y_root + 2, x_root, "------Player 1 scores------");
    mvaddstr(y_root + 3, x_root, ("Pentris: " + std::to_string(l_player_score[5])).c_str());
    mvaddstr(y_root + 4, x_root, ("Tetris: " + std::to_string(l_player_score[4])).c_str());
    mvaddstr(y_root + 5, x_root, ("Triple: " + std::to_string(l_player_score[3])).c_str());
    mvaddstr(y_root + 6, x_root, ("Double: " + std::to_string(l_player_score[2])).c_str());
    mvaddstr(y_root + 7, x_root, ("Single: " + std::to_string(l_player_score[1])).c_str());
    mvaddstr(y_root + 9, x_root, "------Player 2 scores------");
    mvaddstr(y_root + 10, x_root, ("Pentris: " + std::to_string(r_player_score[5])).c_str());
    mvaddstr(y_root + 11, x_root, ("Tetris: " + std::to_string(r_player_score[4])).c_str());
    mvaddstr(y_root + 12, x_root, ("Triple: " + std::to_string(r_player_score[3])).c_str());
    mvaddstr(y_root + 13, x_root, ("Double: " + std::to_string(r_player_score[2])).c_str());
    mvaddstr(y_root + 14, x_root, ("Single: " + std::to_string(r_player_score[1])).c_str());
    mvaddstr(y_root + 18, x_root, "Press F t-o go back to the menu.");

}

void ScoreView::Draw() {

}

ScoreView::ScoreView(char winner, std::map<int, int> l_player_score, std::map<int, int> r_player_score) : winner(
        winner), l_player_score(std::move(l_player_score)), r_player_score(std::move(r_player_score)) {

}

