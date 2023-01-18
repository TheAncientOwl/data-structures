#pragma once

#include "Vector.hpp"

#include <vector>

#include "../ccolor/ccolor.hpp"
#include "../Dummy/Dummy.hpp"

void vector_test() {
  std::cout << ccolor::light_green;

  // Vector<Dummy> v;
  // Vector<Dummy> v(20);
  Vector<Dummy> v(5, Dummy("qq", "qqq", 11));
  // Vector<Dummy> v1(v);
  // Vector<Dummy> v1(std::move(v));
  // Vector<Dummy> v1;
  // v1 = v;
  // v1 = std::move(v);

  // v.emplaceBack("wdawd", "dwewferfe", 22);

  // v.push_back(Dummy("bob", "the builder", 22));

  // Dummy d("q", "qq", 22);
  // for (int i = 0; i < 10;i++)
  //   v.push_back(Dummy("bob", "the builder", 22));

  std::cout << v[0] << '\n';
  std::cout << v.front() << '\n';
  std::cout << v.back() << '\n';

  std::cout << v.size() << " - " << v.capacity() << '\n';

  std::cout << "> END.\n" << ccolor::reset;
}
