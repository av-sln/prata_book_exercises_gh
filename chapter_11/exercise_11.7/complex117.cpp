// complex117.cpp -- файл реализации методов класса Complex

#include <iostream>
#include "complex117.hpp"

// Конструктор
Complex::Complex(double a, double b)
{
  a_ = a;
  b_ = b;
}

// Деструктор
Complex::~Complex()
{}

// Перегрузка операций
// Сложение: a + c = (A + C, (B + D)i)
Complex Complex::operator+(const Complex &rc) const
{
  Complex c_sum;
  c_sum.a_ = a_ + rc.a_;
  c_sum.b_ = b_ + rc.b_;

  return c_sum;
}

// Вычитание: a - c = (A - C, (B - D)i)
Complex Complex::operator-(const Complex &rc) const
{
  Complex c_diff;
  c_diff.a_ = a_ - rc.a_;
  c_diff.b_ = b_ - rc.b_;

  return c_diff;
}

// Умножение: a * c = (A * C - B * D, (A * D + B * C)i)
Complex Complex::operator*(const Complex &rc) const
{
  Complex c_mult;
  c_mult.a_ = a_ * rc.a_ - b_ * rc.b_;
  c_mult.b_ = a_ * rc.b_ + b_ * rc.a_;

  return c_mult;
}

// Сопряжение: ~a = (A, -Bi)
Complex Complex::operator~() const
{  
  Complex c_num;
  c_num.a_ = a_;
  c_num.b_ = -b_;
  return c_num; 
}

// Друзья
// n * C = (n * C, n * Di)
Complex operator*(double n, const Complex &ra)
{
  Complex c_num;
  c_num.a_ = n * ra.a_;
  c_num.b_ = n * ra.b_;
  return c_num;
}
std::istream& operator>>(std::istream &rin, Complex &ra)
{
  std::cout << "real: ";
  if (rin >> ra.a_) {    
    std::cout << "imaginary: ";
    rin >> ra.b_;
  }
  return rin;
}

std::ostream& operator<<(std::ostream &rout, const Complex &ra)
{
  rout << "(" << ra.a_ << ", " << ra.b_ << "i)";
  return rout;
}