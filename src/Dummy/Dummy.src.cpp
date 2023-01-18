#include "Dummy.hpp"

#define DUMMY_LOG

#include <cstring>

#ifdef DUMMY_LOG
#include <iostream>
#include "../ccolor/ccolor.hpp"

std::ostream& log_format(std::ostream& out) {
  std::cout << ccolor::light_gray << "[" << ccolor::light_green << "Dummy" << ccolor::light_gray << "] ";

  return out;
}
#endif

void Dummy::setTag(const char* tag) {
  if (tag == nullptr) {
    m_Tag = nullptr;
  } else {
    if (m_Tag != nullptr) delete[] m_Tag;

    m_Tag = new char[strlen(tag)];
    strcpy(m_Tag, tag);
  }
}

Dummy::Dummy(): m_Name(""), m_Tag(nullptr), m_Age(0) {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Default Constructor.\n";
#endif
}

Dummy::Dummy(std::string name, const char* tag, uint16_t age): m_Name(std::move(name)), m_Age(age) {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Param Constructor.\n";
#endif
  this->setTag(tag);
}

Dummy::Dummy(const Dummy& other): m_Name(other.m_Name), m_Age(other.m_Age) {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Copy Constructor.\n";
#endif

  this->setTag(other.m_Tag);
}

Dummy::Dummy(Dummy&& other) noexcept
  : m_Name(std::move(other.m_Name)), m_Age(std::move(other.m_Age)) {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Move Constructor.\n";
#endif

  m_Tag = other.m_Tag;
  other.m_Tag = nullptr;
}

Dummy& Dummy::operator=(const Dummy& other) {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Copy Assignment Operator.\n";
#endif
  if (this == &other) return *this;

  m_Name = other.m_Name;
  m_Age = other.m_Age;
  this->setTag(other.m_Tag);

  return *this;
}

Dummy& Dummy::operator=(Dummy&& other) noexcept {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Move Assignment Operator.\n";
#endif
  if (this == &other) return *this;

  m_Name = std::move(other.m_Name);
  m_Age = std::move(other.m_Age);
  m_Tag = other.m_Tag;
  other.m_Tag = nullptr;

  return *this;
}

Dummy::~Dummy() {
#ifdef DUMMY_LOG
  std::cout << log_format << ccolor::light_green << "Desctructor.\n";
#endif
  if (m_Tag != 0)
    delete[] m_Tag;
}

std::ostream& operator<<(std::ostream& out, const Dummy& dummy) {
  std::cout << log_format << ccolor::gold << "name(" << dummy.m_Name << ") tag(" << (dummy.m_Tag ? dummy.m_Tag : "nullptr") << ") age(" << dummy.m_Age << ")";

  return out;
}
