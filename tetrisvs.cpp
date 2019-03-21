//
// Created by Mark David on 13/03/2019.
//
#include "lib/curses/curses.h"
#include "src/views/abstractview.h"
#include "src/views/menu.h"


int main() {

    AbstractView *current_view = new Menu();
    initscr();
    resize_term(50, 150);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    current_view->InitialDraw();
    attroff(COLOR_PAIR(1));
    refresh();
    getch();
    endwin();

    return 0;
}
