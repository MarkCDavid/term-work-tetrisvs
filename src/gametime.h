//
// Created by Mark David on 18/04/2019.
//

#ifndef TETRISVS_GAMETIME_H
#define TETRISVS_GAMETIME_H

#include <chrono>

class GameTime {
public:
    static GameTime* Instance();
    float DeltaTime();
    void Refresh();
protected:
    GameTime() = default;

private:
    static GameTime* instance;
    float delta_time;
    std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point previous_time = std::chrono::system_clock::now();
};

#endif //TETRISVS_GAMETIME_H
