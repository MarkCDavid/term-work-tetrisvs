//
// Created by Mark David on 19/04/2019.
//

#ifndef TETRISVS_MENUDATA_H
#define TETRISVS_MENUDATA_H

#include <fstream>
#include <vector>
#include <string>

class MenuData {
public:
    MenuData();
    void ModifyCurrentItem(int delta);
    int PreviousItem() const;
    int CurrentItem() const;
    std::vector<std::string> Options() const;
private:
    int prev_item = 0;
    int curr_item = 0;
    std::vector<std::string> menu_options;
};

#endif //TETRISVS_MENUDATA_H
