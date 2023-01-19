#pragma once
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <cstring>
#include <iostream>

template<typename T>
class Vector {
public:
  Vector();
  Vector(std::size_t capacity);
  Vector(std::size_t size, T&& value);
  Vector(const Vector& other);
  Vector(Vector&& other) noexcept;
  Vector<T>& operator=(const Vector<T>& rhs);
  Vector<T>& operator=(Vector<T>&& rhs) noexcept;
  ~Vector();

  void reserve(std::size_t capacity);
  void resize(std::size_t newCapacity);

  void pushBack(const T& value);
  void pushBack(T&& value);

  template<typename... Args>
  T& emplaceBack(Args&&... args);

  void popBack();

  T& operator[](int index);
  const T& operator[](int index) const;

  T& front();
  const T& front() const;

  T& back();
  const T& back() const;

  std::size_t capacity() const;
  std::size_t size() const;
  bool empty() const;

  void swap(Vector<T>& other);

private:
  T* allocateData(std::size_t capacity);
  void deallocateData();
  void rawResize();
  void throwIfEmpty();
  void expandIfNecessary();

private:
  T* m_Data = nullptr;
  std::size_t m_Capacity;
  std::size_t m_Size;
};

template<typename T>
inline Vector<T>::Vector()
  : m_Data(this->allocateData(0)), m_Capacity(0), m_Size(0) {}

template<typename T>
inline Vector<T>::Vector(std::size_t capacity)
  : m_Data(this->allocateData(capacity)), m_Capacity(capacity), m_Size(0) {}

template<typename T>
inline Vector<T>::Vector(std::size_t size, T&& value)
  : m_Data(this->allocateData(size)), m_Capacity(size), m_Size(size) {
  for (std::size_t i = 0; i < size;i++)
    m_Data[i] = value;
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
  : m_Data(this->allocateData(other.m_Capacity)), m_Capacity(other.m_Capacity), m_Size(other.m_Size) {
  for (std::size_t i = 0; i < m_Size;i++)
    m_Data[i] = other.m_Data[i];
}

template<typename T>
inline Vector<T>::Vector(Vector&& other) noexcept
  : m_Data(other.m_Data), m_Capacity(other.m_Capacity), m_Size(other.m_Size) {
  m_Data = nullptr;
  m_Capacity = 0;
  m_Size = 0;
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
  if (this == &rhs) return *this;

  m_Size = rhs.m_Size;
  m_Capacity = rhs.m_Capacity;

  this->deallocateData();
  this->allocateData(m_Capacity);

  for (std::size_t i = 0; i < m_Size;i++)
    m_Data[i] = rhs.m_Data[i];

  return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) noexcept {
  if (this == &rhs) return *this;

  m_Data = rhs.m_Data;
  m_Capacity = rhs.m_Capacity;
  m_Size = rhs.m_Size;

  rhs.m_Data = nullptr;
  rhs.m_Capacity = 0;
  rhs.m_Size = 0;

  return *this;
}

template<typename T>
inline Vector<T>::~Vector() {
  this->deallocateData();
}

template<typename T>
inline void Vector<T>::rawResize() {
  T* newData = this->allocateData(m_Capacity);

  for (std::size_t i = 0; i < m_Size; i++)
    new(&newData[i]) T(std::move(m_Data[i]));

  this->deallocateData();

  m_Data = newData;
}

template<typename T>
inline void Vector<T>::throwIfEmpty() {
  if (m_Size == 0)
    throw std::runtime_error("the vectory is empty");
}

template<typename T>
inline void Vector<T>::expandIfNecessary() {
  if (m_Size == m_Capacity)
    this->reserve(m_Capacity == 0 ? 10 : (m_Capacity * 2));
}

template<typename T>
inline void Vector<T>::reserve(std::size_t capacity) {
  if (m_Capacity >= capacity) return;

  if (m_Capacity == 0) {
    m_Capacity = capacity;
    m_Data = this->allocateData(m_Capacity);
    return;
  }

  m_Capacity = capacity;
  this->rawResize();
}

template<typename T>
inline void Vector<T>::resize(std::size_t newCapacity) {
  if (newCapacity == m_Capacity) return;

  if (newCapacity > m_Capacity) {
    this->reserve(newCapacity);
    return;
  }

  m_Capacity = newCapacity;
  m_Size = newCapacity;
  this->rawResize();
}

template<typename T>
inline void Vector<T>::pushBack(const T& value) {
  this->expandIfNecessary();

  new(&m_Data[m_Size++]) T(value);
}

template<typename T>
inline void Vector<T>::pushBack(T&& value) {
  this->expandIfNecessary();

  new(&m_Data[m_Size++]) T(std::forward<T>(value));
}

template<typename T>
inline std::size_t Vector<T>::capacity() const {
  return m_Capacity;
}

template<typename T>
inline std::size_t Vector<T>::size() const {
  return m_Size;
}

template<typename T>
inline bool Vector<T>::empty() const {
  return m_Size == 0;
}

template<typename T>
inline void Vector<T>::swap(Vector<T>& other) {
  std::swap(m_Data, other.m_Data);
  std::swap(m_Capacity, other.m_Capacity);
  std::swap(m_Size, other.m_Size);
}

template<typename T>
inline T* Vector<T>::allocateData(std::size_t capacity) {
  return (T*) malloc(capacity * sizeof(T));
}

template<typename T>
inline void Vector<T>::deallocateData() {
  if (m_Data != nullptr) {
    for (std::size_t i = 0; i < m_Size; i++)
      m_Data[i].~T();
    free(m_Data);
    m_Data = nullptr;
  }
}

template<typename T>
inline void Vector<T>::popBack() {
  this->throwIfEmpty();

  m_Data[m_Size - 1].~T();
  m_Size--;
}

template<typename T>
inline T& Vector<T>::operator[](int index) {
  if (index < 0 || index > m_Size)
    throw std::out_of_range("index out of bounds");

  return m_Data[index];
}

template<typename T>
inline const T& Vector<T>::operator[](int index) const {
  if (index < 0 || index > m_Size)
    throw std::out_of_range("index out of bounds");

  return m_Data[index];
}

template<typename T>
inline T& Vector<T>::front() {
  this->throwIfEmpty();

  return m_Data[0];
}

template<typename T>
inline const T& Vector<T>::front() const {
  this->throwIfEmpty();

  return m_Data[0];
}

template<typename T>
inline T& Vector<T>::back() {
  this->throwIfEmpty();

  return m_Data[m_Size - 1];
}

template<typename T>
inline const T& Vector<T>::back() const {
  this->throwIfEmpty();

  return m_Data[m_Size - 1];
}

template<typename T>
template<typename ...Args>
inline T& Vector<T>::emplaceBack(Args && ...args) {
  this->expandIfNecessary();

  new(&m_Data[m_Size])T(std::forward<Args>(args)...);

  return m_Data[m_Size++];
}
