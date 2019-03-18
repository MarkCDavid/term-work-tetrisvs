//
// Created by Mark David on 18/03/2019.
//

#include "menu.h"
#include "windows.h"

void Menu::Update(float delta_time) {
    if (input->GetKeyDown(VK_UP)) {
        prev_menu_item = menu_item;
        menu_item--;
        if (menu_item < 0) menu_item = 0;
    } else if (input->GetKeyDown(VK_DOWN)) {
        prev_menu_item = menu_item;
        menu_item++;
        if (menu_item > 5) menu_item = 5;
    }
}

void Menu::InitialDraw() {
    int menu_left = terminal->GetWidth() / 5;
    int menu_top = terminal->GetHeight() / 3;
    terminal->PutStringAt(menu_left, menu_top - 11, R"(##############################################)",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 10, R"(#|__   __|| ___/#|__   __||  __  /#|_||  ___/#)",
                          FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 9, R"(####| |###| |#######| |###| |#/ /##| |#\ \####)", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 8, R"(####| |###|  _/#####| |###|  __ \##| |##\ \###)", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 7, R"(####| |###| |#######| |###| |##\ \#| |###\ \##)", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 6, R"(####|_|###|_____\###|_|###|_|###\_\|_||_____|#)", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 5, R"(##############################################)", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 4, R"(              ###\  \/  /#/  __/###           )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 3, R"(              ####\    /##\  \#####           )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 2, R"(              #####\__/#/____/#####           )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left, menu_top - 1, R"(              #####################           )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left * 2, menu_top + 5, R"( Player vs Player )", FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left * 2, menu_top + 7, R"( Player vs Easy Computer )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left * 2, menu_top + 9, R"( Player vs Medium Computer )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left * 2, menu_top + 11, R"( Player vs Hard Computer )", FG_COLOR::WHITE,
                          BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left * 2, menu_top + 13, R"( Controls )", FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutStringAt(menu_left * 2, menu_top + 15, R"( Exit )", FG_COLOR::WHITE, BG_COLOR::BLACK);
}

void Menu::Draw() {
    int menu_left = terminal->GetWidth() / 5;
    int menu_top = terminal->GetHeight() / 3;
    terminal->PutAt(menu_left * 2 - 2, menu_top + 5 + (prev_menu_item * 2), ' ', FG_COLOR::WHITE, BG_COLOR::BLACK);
    terminal->PutAt(menu_left * 2 - 2, menu_top + 5 + (menu_item * 2), '>', FG_COLOR::WHITE, BG_COLOR::BLACK);
}

Menu::Menu(AbstractTerminal *terminal, AbstractInput *input) : AbstractView(terminal), input(input) {

}
