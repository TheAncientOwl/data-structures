#pragma once

#include <vector>
#include "Vector.hpp"
#include "../Dummy/Dummy.hpp"

#include "../Timer/Timer.hpp"
#include "../ccolor/ccolor.hpp"

void vector_benchmark() {
  const int SIZE = 1000000;

  std::cout << ccolor::dark_blue << ">> No reserve:\n";
  {
    Timer timer;

    std::vector<Dummy> v;
    for (int i = 0; i < SIZE;i++)
      v.push_back(Dummy("qwerty", "qwerty", 11));

    std::cout << ccolor::dark_green << "> push-back    -> std::vector -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  {
    Timer timer;

    Vector<Dummy> v;
    for (int i = 0; i < SIZE; i++)
      v.pushBack(Dummy("qwerty", "qwerty", 11));

    std::cout << ccolor::dark_green << "> push-back    -> Vector      -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  // -----------------------

  {
    Timer timer;

    std::vector<Dummy> v;
    for (int i = 0; i < SIZE;i++)
      v.emplace_back("qwerty", "qwerty", 11);

    std::cout << ccolor::dark_green << "> emplace-back -> std::vector -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  {
    Timer timer;

    Vector<Dummy> v;
    for (int i = 0; i < SIZE; i++)
      v.emplaceBack("qwerty", "qwerty", 11);

    std::cout << ccolor::dark_green << "> emplace-back -> Vector      -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  // ------------------------------------------------------------------------------------------------------

  std::cout << ccolor::dark_blue << ">> Reserve:\n";
  {
    Timer timer;

    std::vector<Dummy> v;
    v.reserve(SIZE);
    for (int i = 0; i < SIZE;i++)
      v.push_back(Dummy("qwerty", "qwerty", 11));

    std::cout << ccolor::dark_green << "> push-back    -> std::vector -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  {
    Timer timer;

    Vector<Dummy> v;
    v.reserve(SIZE);
    for (int i = 0; i < SIZE; i++)
      v.pushBack(Dummy("qwerty", "qwerty", 11));

    std::cout << ccolor::dark_green << "> push-back    -> Vector      -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  // -----------------------

  {
    Timer timer;

    std::vector<Dummy> v;
    v.reserve(SIZE);
    for (int i = 0; i < SIZE;i++)
      v.emplace_back("qwerty", "qwerty", 11);

    std::cout << ccolor::dark_green << "> emplace-back -> std::vector -> " << timer.elapsedMilliseconds() << "ms\n";
  }

  {
    Timer timer;

    Vector<Dummy> v;
    v.reserve(SIZE);
    for (int i = 0; i < SIZE; i++)
      v.emplaceBack("qwerty", "qwerty", 11);

    std::cout << ccolor::dark_green << "> emplace-back -> Vector      -> " << timer.elapsedMilliseconds() << "ms\n";
  }

}
