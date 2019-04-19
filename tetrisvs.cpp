//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "src/gametime.h"
#include "src/views/menu.h"
#include "src/views/gameview.h"
#include "src/views/scoreview.h"
#include "src/views/controlsview.h"
#include "src/managers/menumanager.h"


TetrisVS *TetrisVS::instance = nullptr;
ShapeFactory *ShapeFactory::instance = nullptr;
Keyboard *Keyboard::instance = nullptr;
GameTime* GameTime::instance = nullptr;

int main() {
    while (TetrisVS::Instance()->GameRunning()) {
        GameTime::Instance()->Refresh();
        TetrisVS::Instance()->Update();
    }
}


TetrisVS::TetrisVS() {
    initscr(); // Initialize the screen
    resize_term(50, 150); // Set the size
    curs_set(0); // Turn off the cursor
    keypad(stdscr, TRUE); // Add other button detection
    noecho(); // Dont print anything after pressing
    timeout(1); // set non blocking getch
    start_color(); // Start coloring
    init_color_pairs(); // Initialize the pairs.
    auto* data = new MenuData();
    Switch(new MenuManager(data), new Menu(data));
}

TetrisVS::~TetrisVS() {
    delete view;
    delete manager;
    endwin();
}


void TetrisVS::Update() {
    manager->Update();
    view->Update();
    view->Draw();
    refresh();
}

void TetrisVS::Switch(AbstractManager* new_manager, AbstractView* new_view)
{
    Keyboard::Instance()->Flush();
    delete view;
    delete manager;
    manager = new_manager;
    view = new_view;
    view->InitialDraw();
}

TetrisVS *TetrisVS::Instance() {
    if (instance == nullptr)
        instance = new TetrisVS();
    return instance;
}

bool TetrisVS::GameRunning() {
    return game_running;
}

void TetrisVS::StopGame() {
    game_running = false;
}
