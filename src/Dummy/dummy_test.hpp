#pragma once

#include "Dummy.hpp"

void dummy_test() {
  Dummy d0;
  std::cout << d0 << "\n\n";

  Dummy d1("Bob", "The Builder", 35);
  std::cout << d1 << "\n\n";

  Dummy d2(d1);
  std::cout << d2 << "\n\n";

  Dummy d3;
  d3 = d1;
  std::cout << d3 << "\n\n";

  Dummy d4(std::move(d2));
  std::cout << d2 << '\n';
  std::cout << d4 << "\n\n";

  Dummy d5;
  d5 = std::move(d3);
  std::cout << d3 << '\n';
  std::cout << d4 << '\n';

  std::cout << "----------------------------\n";
}
