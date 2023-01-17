#include "Dummy.hpp"

#include <iostream>

int main() {
  Dummy d0;
  Dummy d1("Bob", "The Builder", 35);
  Dummy d2(d1);
  Dummy d3;
  d3 = d1;
  Dummy d4(std::move(d2));
  Dummy d5;
  d5 = std::move(d5);
  std::cout << "----------------------------\n";
  return 0;
}
