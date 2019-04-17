
//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_MENU_H
#define TETRISVS_MENU_H

#include "../color.h"
#include "abstractview.h"
#include <vector>
#include <string>
#include "../keyboard.h"

class Menu : public AbstractView {
public:

    Menu();

    void Update(float delta_time) override;
    void InitialDraw() override;
    void Draw() override;

private:
    const int title_height = 28;
    const int title_width = 117;

    int prev_menu_item = 0;
    int menu_item = 0;
    int menu_option_count = 0;

    int tOffset = 0;
    int lOffset = 0;

    std::string title_top;
    std::string title_bottom;

    std::vector<int> color_top = {Color::RED_BLACK, Color::GREEN_BLACK, Color::YELLOW_BLACK,
                                  Color::MAGENTA_BLACK, Color::CYAN_BLACK, Color::YELLOW_BLACK};

    std::vector<int> color_bottom = {Color::RED_BLACK, Color::YELLOW_BLACK};

    std::vector<std::string> menu_options = {
            "Player vs Player",
            "Player vs Computer",
            "Player vs Hard Computer",
            "Controls",
            "Exit Game",
    };

    int WidthFromOffsets(std::vector<unsigned int> &offsets, int letter_count);

    void DrawBigLetters(std::string &letters, int letter_count, std::vector<unsigned int> offsets,
                        std::vector<int> color_id, int top_offset, int bot_offset);

    void DrawMenuOptions(int tOffset = 0, int lOffset = 0, int step = 2);

    void ReadFromFile(const char *file_path, std::string &read_to);


};


#endif //TETRISVS_MENU_H

