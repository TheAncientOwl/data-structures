#pragma once

#include <iostream>
#include <string>

class Dummy {
private:
  void setTag(const char* tag);

public:
  Dummy();
  Dummy(std::string name, const char* tag, uint16_t age);
  Dummy(const Dummy& other);
  Dummy(Dummy&& other) noexcept;
  Dummy& operator=(const Dummy& other);
  Dummy& operator=(Dummy&& other) noexcept;
  ~Dummy();

  friend std::ostream& operator<<(std::ostream& out, const Dummy& dummy);

private:
  std::string m_Name;
  char* m_Tag = nullptr;
  uint16_t m_Age;
};
