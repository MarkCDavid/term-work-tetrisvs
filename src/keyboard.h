//
// Created by Mark David on 27/03/2019.
//

#ifndef TETRISVS_KEYBOARD_H
#define TETRISVS_KEYBOARD_H

#ifdef _WIN32
#include "../lib/curses.h"
#endif
#ifdef __linux__
#include <ncurses.h>
#endif
#include <set>

class Keyboard {
public:
    static Keyboard *Instance();
    void Update();
    void Flush();
    bool GetKey(int keycode);
private:
    static Keyboard *instance;
    std::set<int> keys;
};


#endif //TETRISVS_KEYBOARD_H
