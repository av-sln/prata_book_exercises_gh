// time114.hpp -- класс Time с друзьями

#ifndef TIME114_HPP_
#define TIME114_HPP_
#include <iostream>

class Time
{
private:
  int hours;
  int minutes;

public:
  Time();                 // конструктор по умолчанию
  Time(int h, int m = 0); // конструктор с аргументами
  ~Time();                // деструктор
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);

  // Друзья
  // С = A + B
  friend Time operator+(const Time& ra, const Time& rb);

  // c = A - B
  friend Time operator-(const Time& ra, const Time& rb);

  // B = A * n;
  friend Time operator*(const Time& ra, double n);

  // B = n * A (встроенное определение)
  friend Time operator*(double n, const Time& ra)
    { return ra * n; }
  friend std::ostream& operator<<(std::ostream& ros, const Time& ra);
};

#endif