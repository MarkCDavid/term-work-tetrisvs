//
// Created by Mark David on 16/04/2019.
//

#ifndef TETRISVS_RANDOM_H
#define TETRISVS_RANDOM_H

#include <chrono>
#include <random>

class Random {
public:
    static int GetRandom(int from, int to) {
        static long long call = 0;
        call++;
        long long seed = std::chrono::system_clock::now().time_since_epoch().count()+call;
        std::mt19937 prng(seed);
        std::uniform_int_distribution<int> dist(from, to);
        return dist(prng);
    }
};


#endif //TETRISVS_RANDOM_H


