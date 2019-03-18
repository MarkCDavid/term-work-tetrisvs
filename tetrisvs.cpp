//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "lib/tge/input/Win32Input.h"
#include "lib/tge/terminal/CMDTerminal.h"

TetrisVS::TetrisVS() :
        GameEngine(new Win32Input(), new CMDTerminal()) {}


bool TetrisVS::Start() {
    current_view = new Game(g_terminal, g_in);
    current_view->InitialDraw();
    return true;
}

bool TetrisVS::Update(float delta_time) {
//    int message = current_view->Update(delta_time);
//    current_view->Draw();
//    switch(message){
//        case 0:
//            delete current_view;
//            current_view = new Game(g_terminal, g_in);
//            current_view->InitialDraw();
//            break;
//        case 4:
//            delete current_view;
//            current_view = new Controls(g_terminal, g_in);
//            current_view->InitialDraw();
//            break;
//        case 11:
//            delete current_view;
//            current_view = new Menu(g_terminal, g_in);
//            current_view->InitialDraw();
//            break;
//        default:
//            break;
//    }
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
