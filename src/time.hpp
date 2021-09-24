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
    }

    uint32_t GetDeltaTime()
    {
        return delta_time_;
    }

private:
    uint32_t delta_time_;
    uint32_t elapsed_time_;
    uint32_t last_frame_;
};