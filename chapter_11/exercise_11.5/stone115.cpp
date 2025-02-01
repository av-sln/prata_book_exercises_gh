// stone115.cpp -- файл реализации класса Stonewt

#include <iostream>
#include "stone115.hpp"

// Конструктор по умолчанию
Stonewt::Stonewt()
{
  stone_ = 0;
  pds_left_ = 0.0;
  pounds_ = 0;
  flt_pounds_= 0.0;
  mode_ = Float;
}

// Конструктор для значения в фунтах
Stonewt::Stonewt(double pds, Mode form)
{
  stone_ = int(pds) / PdsStn;
  pds_left_ = int(pds) % PdsStn + pds - int(pds);
  pounds_ = int(pds + 0.5);
  flt_pounds_ = pds;
  mode_ = form;
}

// Конструктор для значения в стоунах и фунтах
Stonewt::Stonewt(int stn, double pds, Mode form)
{
  stone_ = stn;
  pds_left_ = pds;
  flt_pounds_ = stn * PdsStn + pds;
  pounds_ = int(flt_pounds_ + 0.5);
  mode_ = form;
}

// Деструктор
Stonewt::~Stonewt()
{}

// Установка форм интерпретации
void Stonewt::set_stone()
{
  mode_ = Stone;
}

void Stonewt::set_pounds()
{
  mode_ = Pounds;
}

void Stonewt::set_float()
{
  mode_ = Float;
}

// Перегрузка операций
// C = A + B
Stonewt Stonewt::operator+(const Stonewt& rb) const
{
  Stonewt sum;
  double temp;
  temp = flt_pounds_ + rb.flt_pounds_;
  sum.stone_ = int(temp) / PdsStn;
  sum.pds_left_ = int(temp) % PdsStn + temp - int(temp);
  sum.pounds_ = int(temp + 0.5);
  sum.flt_pounds_ = temp;
  sum.mode_ = Float;

  return sum;
}

// C = A - B
Stonewt Stonewt::operator-(const Stonewt& rb) const
{
  Stonewt diff;
  double temp;
  temp = flt_pounds_ - rb.flt_pounds_;
  diff.stone_ = int(temp) / PdsStn;
  diff.pds_left_ = int(temp) % PdsStn + temp - int(temp);
  diff.pounds_ = int(temp + 0.5);
  diff.flt_pounds_ = temp;
  diff.mode_ = Float;

  return diff;
}

// C = A * B
Stonewt Stonewt::operator*(const Stonewt& rb) const
{
  Stonewt mult;
  double temp;
  temp = flt_pounds_ * rb.flt_pounds_;
  mult.stone_ = int(temp) / PdsStn;
  mult.pds_left_ = int(temp) % PdsStn + temp - int(temp);
  mult.pounds_ = int(temp + 0.5);
  mult.flt_pounds_ = temp;
  mult.mode_ = Float;

  return mult;
}

// C = A * n
Stonewt Stonewt::operator*(double n) const
{
  Stonewt tmp;
  double temp;
  temp = flt_pounds_ * n;
  tmp.stone_ = int(temp) / PdsStn;
  tmp.pds_left_ = int(temp) % PdsStn + temp - int(temp);
  tmp.pounds_ = int(temp + 0.5);
  tmp.flt_pounds_ = temp;
  tmp.mode_ = Float;

  return tmp;
}

// Друзья
// C = n * A
Stonewt operator*(double n, const Stonewt& ra)
{
  return ra * n;
}

std::ostream& operator<<(std::ostream& ros, const Stonewt& ra)
{
  if (ra.mode_ == Stonewt::Stone)
    ros << ra.stone_ << " стоунов и " << ra.pds_left_ << " фунтов.";
  else if (ra.mode_ == Stonewt::Pounds)
    ros << ra.pounds_ << " фунтов.";
  else
    ros << ra.flt_pounds_ << " фунтов.";

  return ros;
}

