//
// Created by Mark David on 18/03/2019.
//
#include <fstream>
#include <cmath>
#include "menu.h"
#include "gameview.h"
#include "controlsview.h"
#include "../symbols.h"
#include "../../tetrisvs.h"

void Menu::Update(float delta_time) {
    keyboard.Update();
    if (keyboard.GetKey(KEY_DOWN)) {
        prev_menu_item = menu_item;
        menu_item++;
        if (menu_item >= menu_option_count) menu_item = menu_option_count - 1;

    }
    if (keyboard.GetKey(KEY_UP)) {
        prev_menu_item = menu_item;
        menu_item--;
        if (menu_item < 0) menu_item = 0;
    }
    if (keyboard.GetKey('f')) {
        switch (menu_item) {
            case 0 :
                TetrisVS::Instance()->Switch(new GameView());
                break;
            default:
            case 1 :
                TetrisVS::Instance()->Switch(new Menu());
                break;
            case 2 :
                TetrisVS::Instance()->Switch(new ControlsView());
                break;
            case 3 :
                TetrisVS::Instance()->StopGame();
                break;


        }

    } else {
        keyboard.Flush();
    }
}

void Menu::InitialDraw() {
    clear();
    DrawBigLetters(title_top, 6, {23, 22, 23, 20, 10, 19}, color_top, tOffset, lOffset);
    DrawBigLetters(title_bottom, 2, {25, 17}, color_bottom, tOffset + 16, lOffset + (title_width / 2));
    DrawMenuOptions(tOffset + 19, lOffset + (title_width / 5));
    mvaddch(tOffset + 19 + (2 * menu_item), lOffset + (117 / 5) - 2, Symbols::PROMPT);
}

void Menu::Draw() {
    mvaddch(tOffset + 19 + (2 * prev_menu_item), lOffset + (117 / 5) - 2, Symbols::EMPTY);
    mvaddch(tOffset + 19 + (2 * menu_item), lOffset + (117 / 5) - 2, Symbols::PROMPT);
}

Menu::Menu() {
    ReadFromFile("logo/top", title_top);
    ReadFromFile("logo/bot", title_bottom);
    menu_option_count = menu_options.size();
    int width, height;
    getmaxyx(stdscr, height, width);
    tOffset = (height - title_height) / 2;
    lOffset = (width - title_width) / 2;
}

void Menu::DrawBigLetters(std::string &letters, int letter_count, std::vector<unsigned int> offsets,
                          std::vector<int> color_id, int top_offset, int bot_offset) {
    std::string portion;
    unsigned int offset = 0;
    int width = WidthFromOffsets(offsets, letter_count);
    int row_count = std::ceil(letters.size() / (float) width);
    for (int row = 0; row < row_count; row++) {
        for (int letter = 0; letter < letter_count; letter++) {
            attron(COLOR_PAIR(color_id[letter]));
            portion = letters.substr(offset, offsets[letter]);
            mvprintw(top_offset + row, bot_offset + (offset % width), portion.c_str());
            offset += offsets[letter];
            attroff(COLOR_PAIR(color_id[letter]));
        }
    }
}

void Menu::DrawMenuOptions(int tOffset, int lOffset, int step) {
    int offset = 0;
    for (auto &option: menu_options) {
        mvaddstr(tOffset + offset, lOffset, option.c_str());
        offset += step;
    }
}

void Menu::ReadFromFile(const char *file_path, std::string &read_to) {
    std::ifstream logo_file;
    logo_file.open(file_path);
    read_to.assign(std::istreambuf_iterator<char>(logo_file), std::istreambuf_iterator<char>());
    logo_file.close();
}

int Menu::WidthFromOffsets(std::vector<unsigned int> &offsets, int letter_count) {
    int width = 0;
    for (int i = 0; i < letter_count; i++)
        width += offsets[i];
    return width;
}
