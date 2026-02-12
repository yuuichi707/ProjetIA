#pragma once
#include <chrono>
#include <vector>


class Clock {
public:
    Clock() = default;
    Clock(bool StartImmediatly);

    void Start();
    float Restart();
    float GetElapsedTime();
    float TimeSinceStart();

private:
    std::chrono::time_point<std::chrono::steady_clock> TimeStart;
    std::chrono::time_point<std::chrono::steady_clock> LastCallElpased;
};