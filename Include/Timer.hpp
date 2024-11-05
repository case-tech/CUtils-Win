// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#include <chrono>
#include <iostream>

namespace CUtils
{
    class Timer
    {
    public:
        Timer();
        void   Start();
        void   Stop();
        void   Reset();
        double Elapsed()      const;
        void   PrintElapsed() const;

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime_;
        std::chrono::time_point<std::chrono::high_resolution_clock> endTime_;
        bool isRunning_;
    };
}