//
// Created by Mark David on 27/03/2019.
//

#include "keyboard.h"

void Keyboard::Update() {
    int key;
    while ((key = getch()) != ERR) {
        keys.insert(key);
    }
}

void Keyboard::Flush() {
    keys.clear();
}

bool Keyboard::GetKey(int keycode) {
    return keys.find(keycode) != keys.end();
}
