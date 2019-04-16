//
// Created by Mark David on 27/03/2019.
//

#ifndef TETRISVS_KEYBOARD_H
#define TETRISVS_KEYBOARD_H

#include <ncurses.h>
#include <set>

class Keyboard {
public:
    void Update();
    void Flush();
    bool GetKey(int keycode);
private:
    std::set<int> keys;
};


#endif //TETRISVS_KEYBOARD_H
