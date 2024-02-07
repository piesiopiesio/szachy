#include "cclock.h"
#include <iostream>
#include <chrono>
#include <thread>

CClock::CClock() {
    std::cout << "Creating a chess clock.\n";
}

CClock::~CClock() {
    std::cout << "Destroying the chess clock.\n";
}

void CClock::startTimer(int player) {
    playerTimers[player] = std::chrono::system_clock::now();
    std::cout << "Player " << player + 1 << "'s timer started.\n";
}

void CClock::stopTimer(int player) {
    auto endTime = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - playerTimers[player]);
    std::cout << "Player " << player + 1 << "'s timer stopped. Elapsed time: " << duration.count() << " seconds.\n";
}
