//
// Created by Mark David on 18/04/2019.
//

#include "gametime.h"

GameTime* GameTime::Instance()
{
    if (instance==nullptr)
        instance = new GameTime();
    return instance;
}

float GameTime::DeltaTime()
{
    return delta_time;
}

void GameTime::Refresh()
{
    current_time = std::chrono::system_clock::now();
    delta_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time-previous_time).count();
    previous_time = current_time;
}
