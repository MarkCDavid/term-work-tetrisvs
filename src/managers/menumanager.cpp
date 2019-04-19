//
// Created by Mark David on 19/04/2019.
//

#include "menumanager.h"

void MenuManager::Update()
{
    Keyboard::Instance()->Update();
    if (Keyboard::Instance()->GetKey(KEY_DOWN))
        data->ModifyCurrentItem(1);
    if (Keyboard::Instance()->GetKey(KEY_UP))
        data->ModifyCurrentItem(-1);
    if (Keyboard::Instance()->GetKey('f')) {
        switch (data->CurrentItem()) {
        case 0 : {

            auto* left_game = new Game(30, 20);
            auto* right_game = new Game(80, 20);
            auto* left_controller = new PlayerController(ControlScheme(1));
            auto* right_controller = new PlayerController(ControlScheme(2));
            auto* manager = new GameManager({{left_game, left_controller}, {right_game, right_controller}});
            auto* view = new GameView({left_game, right_game});
            TetrisVS::Instance()->Switch(manager, view);
            break;
        }
        default:
        case 1 : {

            auto* left_game = new Game(30, 0);
            auto* right_game = new Game(80, 0);
            auto* left_controller = new PlayerController(ControlScheme(1));
            auto* right_controller = new ComputerController(new NeuralScoring(), false);
            auto* manager = new GameManager({{left_game, left_controller}, {right_game, right_controller}});
            auto* view = new GameView({left_game, right_game});
            TetrisVS::Instance()->Switch(manager, view);
            break;
        }
        case 2 : {

            auto* left_game = new Game(30, 0);
            auto* right_game = new Game(80, 0);
            auto* left_controller = new PlayerController(ControlScheme(1));
            auto* right_controller = new ComputerController(new NeuralScoring(), true);
            auto* manager = new GameManager({{left_game, left_controller}, {right_game, right_controller}});
            auto* view = new GameView({left_game, right_game});
            TetrisVS::Instance()->Switch(manager, view);
            break;
        }
        case 3 :
            //TetrisVS::Instance()->Switch(new ControlsView());
            break;
        case 4 :TetrisVS::Instance()->StopGame();
            break;
        }

    }
    else {
        Keyboard::Instance()->Flush();
    }
}
MenuManager::MenuManager(MenuData* data)
        :data(data)
{

}
MenuManager::~MenuManager()
{
    delete data;
}