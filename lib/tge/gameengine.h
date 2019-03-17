//
// Created by Mark David on 09/03/2019.
//

#ifndef TERMINAL_GAME_ENGINE_GAMEENGINE_H
#define TERMINAL_GAME_ENGINE_GAMEENGINE_H


#include "input/abstractinput.h"
#include "terminal/abstractterminal.h"
#include <windows.h>
#include <thread>
#include <chrono>

class GameEngine {

protected:
    AbstractInput *g_in;
    AbstractTerminal *g_terminal;

private:
    void GameThread();

public:

    ~GameEngine();

    GameEngine(AbstractInput *game_input, AbstractTerminal *game_terminal);

    void Launch();

    bool SetWindow(short width, short height, int pixel_size);

    bool GetKey(unsigned char keycode) const;

    bool GetKeyDown(unsigned char keycode) const;

    bool GetKeyUp(unsigned char keycode) const;

    virtual bool Start() = 0;

    virtual bool Update(float delta_time) = 0;

    virtual bool Exit() { return true; };


};


#endif //TERMINAL_GAME_ENGINE_GAMEENGINE_H
