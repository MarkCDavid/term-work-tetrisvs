
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
    int Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;

private:
    Keyboard keyboard;
    int prev_menu_item = 0;
    int menu_item = 0;
    int menu_option_count = 0;
    int tOffset;
    int lOffset;

    void
    DrawBigLetters(std::string &letters, int letter_count, std::vector<unsigned int> offsets, std::vector<int> color_id,
                   int tOffset = 0,
                   int lOffset = 0);

    void DrawMenuOptions(std::vector<std::string> menu_options, int tOffset = 0, int lOffset = 0, int step = 2);


};


#endif //TETRISVS_MENU_H

