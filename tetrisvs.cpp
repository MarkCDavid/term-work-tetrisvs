//
// Created by Mark David on 13/03/2019.
//
#include "tetrisvs.h"
#include "src/views/menu.h"
#include "src/views/gameview.h"
#include "src/views/scoreview.h"
#include "src/views/controlsview.h"
#include <chrono>


int main() {

    initscr(); // Initialize the screen
    resize_term(50, 150); // Set the size
    curs_set(0); // Turn off the cursor
    keypad(stdscr, TRUE); // Add other button detection
    noecho(); // Dont print anything after pressing
    timeout(1); // set non blocking getch
    start_color(); // Start coloring
    init_color_pairs(); // Initialize the pairs.

    AbstractView *view = new Menu();
    view->InitialDraw();
    auto last = std::chrono::system_clock::now();
    auto current = std::chrono::system_clock::now();
    bool game_running = true;
    while (game_running) {
        current = std::chrono::system_clock::now();
        auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(current - last);
        last = current;
        int event_id = view->Update(difference.count());
        view->Draw();
        refresh();
        switch (event_id) {
            case 500: // Player vs Player
            {
                delete view;
                view = new GameView();
                view->InitialDraw();
                break;
            }
            case 501: // Player vs Computer
            {
                delete view;
                view = new Menu();
                view->InitialDraw();
                break;
            }
            case 502: // Controls
            {
                delete view;
                view = new ControlsView();
                view->InitialDraw();
                break;
            }
            case 503: // Quit Game
            {
                game_running = false;
                break;
            }
            case 1000: // Player 1 lost.
            {
                auto *game = dynamic_cast<GameView *>(view);
                std::map<int, int> lscore;
                std::map<int, int> rscore;
                game->GetScore(lscore, rscore);
                AbstractView *new_view = new ScoreView('r', lscore, rscore);
                delete view;
                view = new_view;
                view->InitialDraw();
                break;
            }
            case 1001: // Player 2 lost.
            {
                auto *game = dynamic_cast<GameView *>(view);
                std::map<int, int> lscore;
                std::map<int, int> rscore;
                game->GetScore(lscore, rscore);
                AbstractView *new_view = new ScoreView('l', lscore, rscore);
                delete view;
                view = new_view;
                view->InitialDraw();
                break;
            }
            case 1100: // Return to menu.
                delete view;
                view = new Menu();
                view->InitialDraw();
                break;
            default:
                break;
        }
    }

    endwin();
    return 0;
}
