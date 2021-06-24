// Use of this source code is governed by a BSD 3-Clause License
// that can be found in the LICENSE file.

// Author: caozhiyi (caozhiyi5@gmail.com)

#ifndef COMMON_TIMER_TIMER_SOLT
#define COMMON_TIMER_TIMER_SOLT

#include <cstdint>
#include "timer_interface.h"

namespace fdan {

// Inherit this class to add to timer.
// don't call any function in this class, 
// they internal used by timer.
class TimerSolt {
public:
    TimerSolt();
    ~TimerSolt() {}

private:
    enum TIMER_SOLT_FLAG: uint32_t {
        TSF_IN_TIMER = (uint32_t)1 << 30,
        TSF_ALWAYS   = (uint32_t)1 << 31,
    };

    // timer out call back
    virtual void OnTimer() = 0;

    void SetInterval(uint32_t interval);
    uint32_t GetTotalInterval();
    uint32_t GetLeftInterval();

    void ResetTime();
    uint32_t TimePass(uint32_t time);

    void SetInTimer();
    bool IsInTimer();
    void RmInTimer();

    void SetAlways();
    bool IsAlways();
    void RmAlways();

private:
    friend class TimerContainer;
    friend class TimerCombinContainer;
    friend class TimerIntegerContainer;

    uint32_t _total_interval;
    uint32_t _left_interval;
};

}

#endif