#pragma once

#include <iostream>
#include <string_view>

namespace ccolor {
  std::ostream& light_blue(std::ostream& out);
  std::ostream& dark_blue(std::ostream& out);

  std::ostream& light_aqua(std::ostream& out);
  std::ostream& dark_aqua(std::ostream& out);

  std::ostream& light_green(std::ostream& out);
  std::ostream& dark_green(std::ostream& out);

  std::ostream& light_red(std::ostream& out);
  std::ostream& dark_red(std::ostream& out);

  std::ostream& dark_purple(std::ostream& out);
  std::ostream& light_purple(std::ostream& out);

  std::ostream& gold(std::ostream& out);
  std::ostream& yellow(std::ostream& out);

  std::ostream& light_gray(std::ostream& out);
  std::ostream& white(std::ostream& out);

  std::ostream& reset(std::ostream& out);
};
