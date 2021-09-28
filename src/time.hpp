#pragma once
#include <stdint.h>

class Time
{
    public:
    Time() {}

    void Update(uint32_t elapsed_time)
    {
        elapsed_time_ = elapsed_time;
        delta_time_ = elapsed_time_ - last_frame_;
        last_frame_ = elapsed_time_;
        framecount_++;
    }

    uint32_t GetDeltaTime()
    {
        return delta_time_;
    }

    uint32_t GetElapsedTime()
    {
        return elapsed_time_;
    }

    uint32_t GetFPS() {
        return static_cast<float>(framecount_)/(static_cast<float>(elapsed_time_)/1000.0f);
    }


private:
    uint32_t framecount_{0};
    uint32_t delta_time_{0};
    uint32_t elapsed_time_;
    uint32_t last_frame_{0};
};