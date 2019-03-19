//
// Created by Mark David on 19/03/2019.
//

#ifndef TETRISVS_ENDGAME_H
#define TETRISVS_ENDGAME_H

#include <sstream>
#include "abstractview.h"

class EndGame : public AbstractView {
private:
    AbstractInput *input;
    int *l_score = new int[5]{};
    int *r_score = new int[5]{};
    char loser = '-';
    std::stringstream s;

    std::string Convert(std::string title, int l_score, int r_score);

public:

    EndGame(AbstractTerminal *terminal, AbstractInput *input, int *l_score, int *r_score, char loser);

    int Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;
};


#endif //TETRISVS_ENDGAME_H
