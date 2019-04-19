//
// Created by Mark David on 19/04/2019.
//

#include "menudata.h"

MenuData::MenuData()
{
    std::ifstream options;
    options.open("data/menu_options");
    std::string option;
    while (std::getline(options, option))
        menu_options.push_back(option);
    options.close();
}
int MenuData::PreviousItem() const
{
    return prev_item;
}
int MenuData::CurrentItem() const
{
    return curr_item;
}
std::vector<std::string> MenuData::Options() const
{
    return menu_options;
}
void MenuData::ModifyCurrentItem(int delta)
{
    prev_item = curr_item;
    curr_item += delta;
    if (curr_item>=static_cast<int>(menu_options.size()))
        curr_item = 0;
    if (curr_item<0)
        curr_item = menu_options.size()-1;
}
