//
// Created by Mark David on 18/03/2019.
//
#include "menu.h"

int Menu::Update(float delta_time) {
    keyboard.Update();
    if (keyboard.GetKey(KEY_DOWN)) {
        prev_menu_item = menu_item;
        menu_item++;
        if (menu_item >= menu_option_count) menu_item = menu_option_count - 1;
        mvaddch(tOffset + 19 + (2 * prev_menu_item), lOffset + (117 / 5) - 2, ' ');
        mvaddch(tOffset + 19 + (2 * menu_item), lOffset + (117 / 5) - 2, '>');
    }
    if (keyboard.GetKey(KEY_UP)) {
        prev_menu_item = menu_item;
        menu_item--;
        if (menu_item < 0) menu_item = 0;
        mvaddch(tOffset + 19 + (2 * prev_menu_item), lOffset + (117 / 5) - 2, ' ');
        mvaddch(tOffset + 19 + (2 * menu_item), lOffset + (117 / 5) - 2, '>');
    }
    if (keyboard.GetKey('f')) {
        return 500 + menu_item;
    }
    keyboard.Flush();
    return 0;
}

void Menu::InitialDraw() {
    clear();
    std::string title_top =
            "#####################################################################################   ##########   ############### "
            "#*********************##********************##*********************##****************#  #********# ##***************#"
            "#*********************##********************##*********************##******######*****# #********##*****######******#"
            "#*****##*******##*****###******#########****##*****##*******##*****###*****#     #*****###******###*****#     #######"
            "######  #*****#  ######  #*****#       ############  #*****#  ######  #****#     #*****#  #****#  #*****#            "
            "        #*****#          #*****#                     #*****#          #****#     #*****#  #****#  #*****#            "
            "        #*****#          #******##########           #*****#          #****######*****#   #****#   #****####         "
            "        #*****#          #***************#           #*****#          #*************##    #****#    ##******#####    "
            "        #*****#          #***************#           #*****#          #****######*****#   #****#      ###********##  "
            "        #*****#          #******##########           #*****#          #****#     #*****#  #****#         ######****# "
            "        #*****#          #*****#                     #*****#          #****#     #*****#  #****#              #*****#"
            "        #*****#          #*****#       ######        #*****#          #****#     #*****#  #****#              #*****#"
            "      ##*******##      ##******########*****#      ##*******##      ##*****#     #*****###******#########     #*****#"
            "      #*********#      #********************#      #*********#      #******#     #*****##********##******######*****#"
            "      #*********#      #********************#      #*********#      #******#     #*****##********##***************## "
            "      ###########      ######################      ###########      ########     ################# ###############   ";
    std::string title_bottom =
            "#######           #######   ###########   "
            " #*****#         #*****#   #***********#  "
            "  #*****#       #*****#   #*************# "
            "   #*****#     #*****#   #******####*****#"
            "    #*****#   #*****#     #*****#  ###### "
            "     #*****# #*****#        #******#      "
            "      #*****#*****#            #******#   "
            "       #*********#       ######   #*****# "
            "        #*******#        #*****####******#"
            "         #*****#         #**************# "
            "          #***#           #***********##  "
            "           ###             ###########    ";

    int title_height = 28;
    int title_width = 117;

    std::vector<int> color_top = {Color::RED_BLACK, Color::GREEN_BLACK, Color::YELLOW_BLACK, Color::MAGENTA_BLACK,
                                  Color::CYAN_BLACK, Color::YELLOW_BLACK};
    std::vector<int> color_bottom = {Color::RED_BLACK, Color::YELLOW_BLACK};

    int width, height;
    getmaxyx(stdscr, height, width);


    tOffset = (height - title_height) / 2;
    lOffset = (width - title_width) / 2;

    DrawBigLetters(title_top, 6, {23, 22, 23, 20, 10, 19}, color_top, tOffset, lOffset);
    DrawBigLetters(title_bottom, 2, {25, 17}, color_bottom, tOffset + 16, lOffset + (title_width / 2));

    std::vector<std::string> menu_options = {
            "Player vs Player",
            "Player vs Computer",
            "Controls",
            "Exit Game",
    };

    DrawMenuOptions(menu_options, tOffset + 19, lOffset + (title_width / 5));
    mvaddch(tOffset + 19 + (2 * menu_item), lOffset + (117 / 5) - 2, '>');
}

void Menu::Draw() {

}

Menu::Menu() {}

void Menu::DrawBigLetters(std::string &letters, int letter_count, std::vector<unsigned int> offsets,
                          std::vector<int> color_id, int tOffset, int lOffset) {
    std::string portion;
    unsigned int offset = 0;
    int width = 0;
    for (int i = 0; i < letter_count; i++) width += offsets[i];
    int row_count = letters.size() / width;
    for (int row = 0; row < row_count; row++) {
        for (int letter = 0; letter < letter_count; letter++) {
            attron(COLOR_PAIR(color_id[letter]));
            portion = letters.substr(offset, offsets[letter]);
            mvprintw(tOffset + row, lOffset + (offset % width), portion.c_str());
            offset += offsets[letter];
            attroff(COLOR_PAIR(color_id[letter]));
        }
    }

}

void Menu::DrawMenuOptions(std::vector<std::string> menu_options, int tOffset, int lOffset, int step) {
    menu_option_count = menu_options.size();
    int offset = 0;
    for (auto &option: menu_options) {
        mvaddstr(tOffset + offset, lOffset, option.c_str());
        offset += step;
    }
}
