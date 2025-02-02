// complex117.hpp -- заголовочный файл класса Complex

#ifndef COMPLEX117_HPP_
#define COMPLEX117_HPP_

#include <iostream>

class Complex
{
private:
  double a_;
  double b_;

public:
  // Конструктор
  Complex(double a = 0.0, double b = 0.0);
  // Деструктор
  ~Complex();

  // Перегрузка операций
  // a + c = (A + C, (B + D)i)
  Complex operator+(const Complex &rc) const;
  // a - c = (A - C, (B - D)i)
  Complex operator-(const Complex &rc) const;
  // a * c = (A * C - B * D, (A * D + B * C)i)
  Complex operator*(const Complex &rc) const;
  // ~a = (A, -Bi)
  Complex operator~() const;

  // Друзья
  // n * c = (n * C, n * Di)
  friend Complex operator*(double n, const Complex &ra);
  friend std::istream& operator>>(std::istream &rin, Complex &ra);
  friend std::ostream& operator<<(std::ostream &rout, const Complex &ra);  
  };

  #endif