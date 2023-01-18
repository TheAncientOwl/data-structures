#include "Timer.hpp"

Timer::Timer(): start(std::chrono::high_resolution_clock::now()) {}

int64_t Timer::elapsedMilliseconds() const {
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = end - start;

  return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}
