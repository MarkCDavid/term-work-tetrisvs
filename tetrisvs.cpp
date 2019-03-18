//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "lib/tge/input/Win32Input.h"
#include "lib/tge/terminal/CMDTerminal.h"

int main() {
    GameEngine *game = new TetrisVS();
    game->SetWindow(81, 50, 10);
    game->Launch();
}

bool TetrisVS::Start() {
    return true;
}

bool TetrisVS::Update(float delta_time) {
    return true;
}

TetrisVS::TetrisVS() :
        GameEngine(new Win32Input(), new CMDTerminal()) {}

bool TetrisVS::Exit() {

    return GameEngine::Exit();
}




