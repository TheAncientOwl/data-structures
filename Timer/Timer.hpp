#pragma once

#include <chrono>

class Timer {
private:
  std::chrono::_V2::system_clock::time_point start;

public:
  Timer();

  int64_t elapsedMilliseconds() const;
};
