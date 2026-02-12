#include "Clock.h"

Clock::Clock(bool StartImmediatly)
{
    if (StartImmediatly) {
        Start();
    }
}

void Clock::Start()
{
    Restart();
}

float Clock::Restart()
{
    std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
    std::chrono::duration<float> Duration = Actual - TimeStart;

    TimeStart = Actual;
    LastCallElpased = Actual;

    return Duration.count();
}

float Clock::GetElapsedTime()
{
    std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
    std::chrono::duration<float> Duration = Actual - LastCallElpased;

    LastCallElpased = Actual;
    return Duration.count();
}

float Clock::TimeSinceStart()
{
    std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
    std::chrono::duration<float> Duration = Actual - TimeStart;
    return Duration.count();
}
