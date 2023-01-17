#include "ccolor.hpp"

namespace ccolor {
  std::ostream& dark_blue(std::ostream& out) {
    out << "\e[0;94m"; return out;
  }

  std::ostream& dark_green(std::ostream& out) {
    out << "\e[0;32m"; return out;
  }

  std::ostream& dark_aqua(std::ostream& out) {
    out << "\e[4;36m"; return out;
  }

  std::ostream& dark_red(std::ostream& out) {
    out << "\e[0;31m"; return out;
  }

  std::ostream& dark_purple(std::ostream& out) {
    out << "\e[0;35m"; return out;
  }

  std::ostream& gold(std::ostream& out) {
    out << "\e[0;93m"; return out;
  }

  std::ostream& light_gray(std::ostream& out) {
    out << "\e[0;97m"; return out;
  }

  std::ostream& light_blue(std::ostream& out) {
    out << "\e[0;36m"; return out;
  }

  std::ostream& light_green(std::ostream& out) {
    out << "\e[0;92m"; return out;
  }

  std::ostream& light_aqua(std::ostream& out) {
    out << "\e[0;96m"; return out;
  }

  std::ostream& light_red(std::ostream& out) {
    out << "\e[0;91m"; return out;
  }

  std::ostream& light_purple(std::ostream& out) {
    out << "\e[0;95m"; return out;
  }

  std::ostream& yellow(std::ostream& out) {
    out << "\e[0;33m"; return out;
  }

  std::ostream& white(std::ostream& out) {
    out << "\e[0;37m"; return out;
  }

  std::ostream& reset(std::ostream& out) {
    out << "\e[0m"; return out;
  }
}
