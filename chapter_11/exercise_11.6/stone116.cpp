// stone116.cpp -- файл реализации класса Stonewt

#include <iostream>
#include "stone116.hpp"

// Конструктор по умолчанию
Stonewt::Stonewt()
{
  stone_ = stn_left_ = pounds_ = 0.0;
}

// Конструктор объекта с аргументом в фунтах
Stonewt::Stonewt(double pds)
{
  stone_ = int(pds) / PdsStn_;
  stn_left_ = int(pds) % PdsStn_ + pds - int(pds);
  pounds_ = pds;
}

// Конструктор объекта с аргументами в стоунах и фунтах
Stonewt::Stonewt(int stn, double pds)
{
  pounds_ = stn * PdsStn_ + pds;
  stone_ = int(pounds_) / PdsStn_;
  stn_left_ = int(pounds_) % PdsStn_ + pounds_ - int(pounds_);
}

// Деструктор
Stonewt::~Stonewt()
{}

// Перегрузка операций
// A == B
bool Stonewt::operator==(const Stonewt& rb) const
{
  return pounds_ == rb.pounds_;  
}

// A != B
bool Stonewt::operator!=(const Stonewt& rb) const
{
  return pounds_ != rb.pounds_;
}

// A < B
bool Stonewt::operator<(const Stonewt& rb) const
{
  return pounds_ < rb.pounds_;
}

// A > B
bool Stonewt::operator>(const Stonewt& rb) const
{
  return pounds_ > rb.pounds_;
}

// A <= B
bool Stonewt::operator<=(const Stonewt& rb) const
{
  return pounds_ <= rb.pounds_;
}

// A >= B
bool Stonewt::operator>=(const Stonewt& rb) const
{
  return pounds_ >= rb.pounds_;
}

// Друзья
std::ostream& operator<<(std::ostream& rout, const Stonewt& ra)
{
  rout << ra.stone_ << " stouns and " << ra.stn_left_ << " pounds.";
  return rout; 
}
