//
// Created by Mark David on 27/03/2019.
//

#include "keyboard.h"

void Keyboard::Update() {
    static int key;
    // if there are multiple keys pressed, getch returns
    // the keycode for all of them, one by one
    if (!active) return;
    while ((key = getch()) != ERR)
        keys.insert(key);
}

void Keyboard::Flush() {
    if (!active) return;
    keys.clear();
}

bool Keyboard::GetKey(int keycode) {
    if (!active) return false;
    return keys.find(keycode) != keys.end();
}

void Keyboard::TurnOff() {
    active = false;
}
