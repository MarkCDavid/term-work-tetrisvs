#include <utility>

//
// Created by Mark David on 18/04/2019.
//

#include "gamemanager.h"

void GameManager::Update()
{
    Keyboard::Instance()->Update();
    for (auto gcp : games) { // gcp - game controller pair
        auto* game = gcp.paired;
        auto* controller = gcp.abstractController;

        if (game->IncreaseTick()) {
            EmplaceCheck(game);
            if (!game->board.IsValidPosition(game->current_shape)) {
                std::vector<std::map<int, int>> line_clears;
                char winner = ' ';
                for (auto gcp_winner: games) {
                    line_clears.push_back(gcp_winner.paired->GetLineClears());
                    if (game!=gcp_winner.paired)
                        winner = gcp_winner.paired->player_repr;
                }
                TetrisVS::Instance()->Switch(nullptr, new ScoreView(winner, line_clears[0], line_clears[1]));
            }
        }
        else {
            controller->Update(game);
        }
    }

    Keyboard::Instance()->Flush();
}

GameManager::GameManager(std::vector<ControllerPair<Game>> games)
        :games(std::move(games))
{

}
void GameManager::EmplaceCheck(Game* game)
{
    game->current_shape.Move(Shape::Movement::DOWN);
    if (!game->board.IsValidPosition(game->current_shape)) {
        game->current_shape.Revert();
        game->board.Place(game->current_shape);
        int cleared = game->board.Clear();
        if (cleared>0) {
            game->board.Cascade();
            for (auto gcp_garbage : games)
                if (game!=gcp_garbage.paired)
                    gcp_garbage.paired->PutGarbage(cleared);
            game->AddLineClear(cleared);
        }
        game->NextShape();
    }
}
