//
// Created by Mark David on 16/04/2019.
//

#ifndef TETRISVS_RANDOM_H
#define TETRISVS_RANDOM_H

#include <chrono>
#include <random>

namespace Random {
    int GetRandom(int from, int to) {
        long long seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::minstd_rand0 prng(seed);
        std::uniform_int_distribution<int> dist(from, to);
        return dist(prng);
    }
}


#endif //TETRISVS_RANDOM_H


