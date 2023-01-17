#pragma once

#include <string>

#include <string_view>

class Dummy {
private:
  void setTag(const char* tag);

public:
  Dummy();
  Dummy(std::string_view name, const char* tag, uint8_t age);
  Dummy(const Dummy& other);
  Dummy(Dummy&& other) noexcept;
  Dummy& operator=(const Dummy& other);
  Dummy& operator=(Dummy&& other) noexcept;
  ~Dummy();

private:
  std::string m_Name;
  char* m_Tag = nullptr;
  uint8_t m_Age;
};
