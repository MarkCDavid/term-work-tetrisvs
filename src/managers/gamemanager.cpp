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

        controller->Update(game);
        if (game->IncreaseTick()) {
            game->UpdateOld();
            game->current_shape.Move(Shape::Movement::DOWN);
            if (!game->board.IsValidPosition(game->current_shape)) {
                Emplace(game);
                if (!game->board.IsValidPosition(game->current_shape)) {
                    GameOver(game);
                    return;
                }
            }
        }
    }

    Keyboard::Instance()->Flush();
}

GameManager::GameManager(std::vector<ControllerPair<Game>> games)
        :games(std::move(games))
{

}
void GameManager::Emplace(Game *game)
{
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

void GameManager::GameOver(Game *game) {
    std::vector<std::map<int, int>> line_clears;
    char winner = ' ';
    char loser = ' ';
    for (auto gcp: games) {
        line_clears.push_back(gcp.paired->GetLineClears());
        if (game!=gcp.paired)
            winner = gcp.paired->player_repr;
        else
            loser = gcp.paired->player_repr;

    }
    TetrisVS::Instance()->Switch(nullptr, new ScoreView(winner, loser, line_clears[0], line_clears[1]));
}
