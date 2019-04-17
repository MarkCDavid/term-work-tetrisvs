//
// Created by Mark David on 27/03/2019.
//

#ifndef TETRISVS_SCOREVIEW_H
#define TETRISVS_SCOREVIEW_H

#include "abstractview.h"
#include "../keyboard.h"
#include <map>

class ScoreView : public AbstractView {
public:
    ScoreView(char winner, std::map<int, int> l_player_score, std::map<int, int> r_player_score);

    void Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;

private:
    char winner;
    std::map<int, int> l_player_score;
    std::map<int, int> r_player_score;
};


#endif //TETRISVS_SCOREVIEW_H
