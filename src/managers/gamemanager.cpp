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
            }
            game->NextShape();
            if (!game->board.IsValidPosition(game->current_shape)) {
                // GAME OVER MAN
            }
        }
        controller->Update(game);
    }

    Keyboard::Instance()->Flush();
}

GameManager::GameManager(std::vector<ControllerPair<Game>> games)
        :games(std::move(games))
{

}
