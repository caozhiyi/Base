// Use of this source code is governed by a BSD 3-Clause License
// that can be found in the LICENSE file.

// Author: caozhiyi (caozhiyi5@gmail.com)

#ifndef COMMON_TIMER_TIMER
#define COMMON_TIMER_TIMER

#include <memory>
#include "timer_interface.h"

namespace fdan {

std::unique_ptr<Timer> MakeTimer50Ms();

std::unique_ptr<Timer> MakeTimer1Sec();

std::unique_ptr<Timer> MakeTimer1Min();

std::unique_ptr<Timer> MakeTimer1Hour();

}

#endif