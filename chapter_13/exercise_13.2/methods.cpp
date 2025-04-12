// methods.cpp -- файл реализации методов классов Cd и Classic
#include <iostream>
#include <cstring>
#include "classic.h"

// Методы Cd
// Конструктор по умолчанию
Cd::Cd() 
{
  performers_ = nullptr;
  label_ = nullptr;
  selections_ = 0;
  playtime_ = 0.0;
}

// Конструктор с аргументами
Cd::Cd(const char* s1, const char* s2, int n, double x)
{
  int len_1 = std::strlen(s1);
  int len_2 = std::strlen(s2);
  performers_ = new char[len_1 + 1];
  label_ = new char[len_2 + 1];
  std::strcpy(performers_, s1);
  std::strcpy(label_, s2);
  selections_ = n;
  playtime_ = x;   
}

// Деструктор
Cd::~Cd()
{
  delete [] performers_;
  delete [] label_;
}

// Конструктор копирования
Cd::Cd(const Cd& rd)
{
  int len_1 = std::strlen(rd.performers_);
  int len_2 = std::strlen(rd.label_);
  performers_ = new char[len_1 + 1];
  label_ = new char[len_2 + 1];
  std::strcpy(performers_, rd.performers_);
  std::strcpy(label_, rd.label_);
  selections_ = rd.selections_;
  playtime_ = rd.playtime_;
}

// Вывод всех данных о компакт-диске
void Cd::Report() const
{
  std::cout << "Performers       :" << performers_ << std::endl;
  std::cout << "Name of the album: " << label_ << std::endl;
  std::cout << "Selections       : " << selections_ << std::endl;
  std::cout << "Playtime         : " << playtime_ << std::endl;
}

// Перегруженная операция присваивания
Cd& Cd::operator=(const Cd& rcd)
{
  if (this == &rcd)
    return *this;
  delete [] performers_;
  delete [] label_;
  int len_1 = std::strlen(rcd.performers_);
  int len_2 = std::strlen(rcd.label_);
  performers_ = new char[len_1 + 1];
  label_ = new char[len_2 + 1];
  std::strcpy(performers_,rcd.performers_);
  std::strcpy(label_, rcd.label_);
  selections_ = rcd.selections_;
  playtime_ = rcd.playtime_;
  return *this;
}

// Методы Classic
// Конструктор по умолчанию
Classic::Classic() : Cd()
{
 favorite_ = nullptr;
}

// Конструктор с аргументами
Classic::Classic(const char* pf, const char* s1, const char* s2, int n, 
  double x) : Cd(s1, s2, n, x)
{
  int len = std::strlen(pf);
  favorite_ = new char[len + 1];
  std::strcpy(favorite_, pf);
}

// Конструктор копирования
Classic::Classic(const Classic& rcd) : Cd(rcd)
{
  int len = std::strlen(rcd.favorite_);
  favorite_ = new char[len + 1];
  std::strcpy(favorite_, rcd.favorite_);
}

// Деструктор
Classic::~Classic() 
{
  delete [] favorite_;
}

// Переопределение функций
// Вывод всех данных о компакт-диске
void Classic::Report() const
{
  Cd::Cd::Report();
  std::cout << "Favorite track: " << favorite_ << std::endl;
}

// Перегруженная операция присваивания
Classic& Classic::operator=(const Classic& rcd)
{
  if (this == &rcd)
    return *this;
  Cd::Cd::operator=(rcd);
  delete [] favorite_;
  int len = std::strlen(rcd.favorite_);
  favorite_ = new char[len + 1];
  std::strcpy(favorite_, rcd.favorite_);
  return *this;
}