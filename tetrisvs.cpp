//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "src/views/menu.h"
#include "src/views/gameview.h"
#include "src/views/scoreview.h"
#include "src/views/controlsview.h"


TetrisVS *TetrisVS::instance = nullptr;
ShapeFactory *ShapeFactory::instance = nullptr;
Keyboard *Keyboard::instance = nullptr;

int main() {
    while (TetrisVS::Instance()->GameRunning())
        TetrisVS::Instance()->Update();
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
    view = new Menu();
    view->InitialDraw();
}

TetrisVS::~TetrisVS() {
    delete view;
    endwin();
}


void TetrisVS::Update() {
    current_time = std::chrono::system_clock::now();
    auto delta_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - previous_time);
    previous_time = current_time;
    view->Update(delta_time.count());
    view->Draw();
    refresh();
}

void TetrisVS::Switch(AbstractView *new_view) {
    Keyboard::Instance()->Flush();
    delete view;
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
