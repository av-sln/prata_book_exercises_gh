// clmethods.cpp -- реализация методов заголовочного файла classes.h

#include <iostream>
#include <cstring>
#include "classes.h"

// Методы абстрактного базового класса baseABC
// Конструктор
baseABC::baseABC(const char* plb, int rt)
{
  int len = std::strlen(plb);
  label_ = new char[len + 1];
  std::strcpy(label_, plb);
  rating_ = rt;
}

// Конструктор копирования
baseABC::baseABC(const baseABC& rabc)
{
  int len = std::strlen(rabc.label_);
  label_ = new char[len + 1];
  std::strcpy(label_, rabc.label_);
  rating_ = rabc.rating_;
}

// Деструктор
baseABC::~baseABC()
{
  delete [] label_;
}

// Перегруженная операция присваивания
baseABC& baseABC::operator=(const baseABC& rabc)
{
  if (this == &rabc)
    return *this;
  delete [] label_;
  int len = std::strlen(rabc.label_);
  label_ = new char[len + 1];
  std::strcpy(label_, rabc.label_);
  rating_ = rabc.rating_;
  return *this;
}

// Вывод всех данных 
void baseABC::view() const
{
  std::cout << "Label is " << viewLabel() << std::endl
            << "Rating is " << viewRating() << std::endl;
}

// Методы класса baseDMA
// Конструктор
baseDMA::baseDMA(const char* plb, int rt)
  : baseABC(plb, rt) {}

// Вывод всех данных
void baseDMA::view() const
{
  baseABC::view();
}

// Методы класса lacksDMA
// Конструктор по умолчанию
lacksDMA::lacksDMA(const char* pcl, const char* plb, int rt)
 : baseABC(plb, rt)
{
  std::strcpy(color_, pcl);
}

// Конструктор с аргументами
lacksDMA::lacksDMA(const char* pcl, const baseABC& rabc)
  : baseABC(rabc)
{
  std::strcpy(color_, pcl);
}

// Вывод всех данных 
void lacksDMA::view() const
{
  baseABC::view();
  std::cout << "Color is " << color_ << std::endl;
}

// Методы класса hasDMA
// Конструктор по умолчанию
hasDMA::hasDMA(const char* pst, const char* plb, int rt)
  : baseABC(plb, rt)
{
  int len = std::strlen(pst);
  style_ = new char[len + 1];
  std::strcpy(style_, pst);
}

// Конструктор с аргументами
hasDMA::hasDMA(const char* pst, const baseABC& rabc)
  : baseABC(rabc)
{
  int len = std::strlen(pst);
  style_ = new char[len + 1];
  std::strcpy(style_, pst);
}

// Конструктор копирования
hasDMA::hasDMA(const hasDMA& rdma) : baseABC(rdma)
{
  int len = std::strlen(rdma.style_);
  style_ = new char[len + 1];
  std::strcpy(style_, rdma.style_);
}

// Деструктор
hasDMA::~hasDMA()
{
  delete [] style_;
}

// Перегруженная операция присваивания
hasDMA& hasDMA::operator=(const hasDMA& rdma)
{
  if (this == &rdma)
    return *this;
  baseABC::operator=(rdma);
  delete [] style_;
  int len = std::strlen(rdma.style_);
  style_ = new char[len + 1];
  std::strcpy(style_, rdma.style_);
  return *this;
}

// Вывод всех данных
void hasDMA::view() const
{
  baseABC::view();
  std::cout << "Style is " << style_ << std::endl;
}