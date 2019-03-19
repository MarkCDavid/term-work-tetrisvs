//
// Created by Mark David on 19/03/2019.
//

#include "endgame.h"

#include <windows.h>

EndGame::EndGame(AbstractTerminal *terminal, AbstractInput *input, int *l_score, int *r_score, char loser)
        : AbstractView(terminal), input(input), l_score(l_score), r_score(r_score), loser(loser) {
}

int EndGame::Update(float delta_time) {
    if (input->GetKeyDown(VK_RETURN)) {
        return 90;
    }
    return -1;
}

void EndGame::InitialDraw() {
    ClearScreen();
    int menu_left = terminal->GetWidth() / 5;
    int menu_top = terminal->GetHeight() / 3;

    std::stringstream s;


    terminal->PutStringAt(menu_left, menu_top, R"( GAME OVER )", FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 1, (loser == 'l') ? R"( RIGHT PLAYER WINS)" : R"( LEFT PLAYER WINS )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 2, R"( ######################################################## )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 3, R"( #                          ##                          # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 4, Convert("PENTRIS", l_score[4], r_score[4]).c_str(), FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 5, Convert("TETRIS", l_score[3], r_score[3]).c_str(), FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 6, Convert("TRIPLE", l_score[2], r_score[2]).c_str(), FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 7, Convert("DOUBLE", l_score[1], r_score[1]).c_str(), FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 8, Convert("SINGLE", l_score[0], r_score[0]).c_str(), FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 9, R"( #                          ##                          # )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top + 10, R"( ######################################################## )",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);

}

void EndGame::Draw() {

}

std::string EndGame::Convert(std::string title, int l_score, int r_score) {

    static int width = 29;
    s.str(std::string());
    s << " # " << title << ": " << l_score;
    int whitespace = width - s.str().length() - 2;
    for (int i = 0; i < whitespace + 1; i++) {
        s << ' ';
    }
    s << "## " << title << ": " << r_score;
    whitespace = (width * 2) - s.str().length() - 2;
    for (int i = 0; i < whitespace; i++) {
        s << ' ';
    }
    s << "# ";
    return s.str();
}
