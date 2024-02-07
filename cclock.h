#ifndef CCLOCK_H
#define CCLOCK_H


#include <chrono>

class CClock {
public:
    CClock();
    virtual ~CClock();

    void startTimer(int player);
    void stopTimer(int player);
    // Add more functions for time-related operations as needed

private:
    std::chrono::time_point<std::chrono::system_clock> playerTimers[2];
};

#endif // CCLOCK_H
