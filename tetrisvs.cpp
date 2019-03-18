//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "lib/tge/input/Win32Input.h"
#include "lib/tge/terminal/CMDTerminal.h"

TetrisVS::TetrisVS() :
        GameEngine(new Win32Input(), new CMDTerminal()) {}


bool TetrisVS::Start() {
    game = new Game(g_terminal, g_in);
    game->InitialDraw();
    return true;
}

bool TetrisVS::Update(float delta_time) {
    game->Update(delta_time);
    game->Draw();
    return true;
}

bool TetrisVS::Exit() {

    return GameEngine::Exit();
}

int main() {
    GameEngine *engine = new TetrisVS();
    engine->SetWindow(81, 50, 20);
    engine->Launch();
}
