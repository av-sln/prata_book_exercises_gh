// methods.cpp -- определения метотодов классов Port и VintagePort

#include <iostream>
#include <cstring>
#include "port.h"
#include "vintageport.h"

// Методы класса Port
// Конструктор класса
Port::Port(const char* p_brd, const char* p_stl, int btl)
{
  int len = std::strlen(p_brd);
  brand_ = new char[len + 1];
  std::strcpy(brand_, p_brd);
  std::strcpy(style_, p_stl);
  bottles_ = btl;
}

// Конструктор копирования
Port::Port(const Port& r_prt)
{
  int len = std::strlen(r_prt.brand_);
  brand_ = new char[len + 1];
  std::strcpy(brand_, r_prt.brand_);
  std::strcpy(style_, r_prt.style_);
  bottles_ = r_prt.bottles_;
}

// Перегрузка операций
// Операция присваивания operator=()
Port& Port::operator=(const Port& r_prt)
{
  if (this == &r_prt)
    return *this;
  delete [] brand_;
  int len = std::strlen(r_prt.brand_);
  brand_ = new char[len + 1];
  std::strcpy(brand_, r_prt.brand_);
  std::strcpy(style_, r_prt.style_);
  bottles_ = r_prt.bottles_;
  return *this;
}

// Перегрузка составных операторов
// Перегрузка operator+=()
Port& Port::operator+=(int btl)
{
  if (btl < 0) {
    std::cout << "The number of bottles can't be negative!\n"
              << "You have to enter a positive number!\n"
              << "The operation is aborted!\n";
    return *this;
  }
  bottles_ += btl;
  return *this;
}

// Перегрузка operator-=()
Port& Port::operator-=(int btl)
{
  if (btl < 0) {
    std::cout << "The number of bottles can't be negative!\n"
              << "You have to enter a positive number!\n"
              << "The operation is aborted!\n";
    return *this;
  } else if (bottles_ < btl) {
    std::cout << "You can't sell more than you have!\n"
              << "Please enter a correctly number!\n"
              << "The operation is aborted!\n";
    return *this;
  }
  bottles_ -= btl;
  return *this;
}

// Вывод всех данных
void Port::show() const
{
  std::cout << "Brand  : " << brand_ << std::endl
            << "Kind   : " << style_ << std::endl
            << "Bottles: " << bottles_ << std::endl;
}

// Друзья
std::ostream& operator<<(std::ostream& r_os, const Port& r_prt)
{
  std::cout << r_prt.brand_ << ", " << r_prt.style_ << ", "
            << r_prt.bottles_;
}

// Методы класса VintagePort
// Конструктор по умолчанию
VintagePort::VintagePort() : Port()
{
  nickname_ = nullptr;
  year_ = 0;
}

// Конструктор с аргументами
VintagePort::VintagePort(const char* p_brd, int btl, const char* p_nn, int yr)
 : Port(p_brd, "vintage", btl)
{
  int len = std::strlen(p_nn);
  nickname_ = new char[len + 1];
  std::strcpy(nickname_, p_nn);
  year_ = yr;
}

// Конструктор копирования
VintagePort::VintagePort(const VintagePort& r_vp)
  : Port(r_vp)
{
  int len = std::strlen(r_vp.nickname_);
  nickname_ = new char[len + 1];
  std::strcpy(nickname_, r_vp.nickname_);
  year_ = r_vp.year_;
}

// Перегрузка operator=()
VintagePort& VintagePort::operator=(const VintagePort& r_vp)
{
  if (this == &r_vp)
    return *this;
  Port::operator=(r_vp);
  delete [] nickname_;
  int len = std::strlen(r_vp.nickname_);
  nickname_ = new char[len + 1];
  std::strcpy(nickname_, r_vp.nickname_);
  year_ = r_vp.year_;
  return *this;
}

// Вывод всех данных
void VintagePort::show() const
{
  Port::show();
  std::cout << "Nickname: " << nickname_ << std::endl
            << "Year    : " << year_ << std::endl;
}

// Друзья
std::ostream& operator<<(std::ostream& r_os, const VintagePort& r_vp)
{
  std::cout << r_vp.nickname_ << ", " << r_vp.year_ << ", "
            << r_vp.bottleCount();
}