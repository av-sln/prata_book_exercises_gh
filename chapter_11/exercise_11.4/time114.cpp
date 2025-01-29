// time114.cpp -- реализация методов класса Time

#include "time114.hpp"

// Конструктор по умолчанию
Time::Time()
{
  hours = minutes = 0;
}

// Конструктор с аргументами
Time::Time(int h, int m)
{
  hours = h;
  minutes = m;
}

// Деструктор
Time::~Time()
{}

void Time::AddMin(int m)
{
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h)
{
  hours += h;
}

void Time::Reset(int h, int m)
{
  hours = h;
  minutes = m;
}

// Друзья
// C = A + B
Time operator+(const Time& ra, const Time& rb)
{
  Time sum;
  sum.minutes = ra.minutes + rb.minutes;
  sum.hours = ra.hours + rb.hours + sum.minutes / 60;
  sum.minutes %= 60;

  return sum;
}

// C = A - B
Time operator-(const Time& ra, const Time& rb)
{
  Time diff;
  int tot_a, tot_b;
  tot_a = ra.minutes + 60 * ra.hours;
  tot_b = rb.minutes + 60 * rb.hours;
  diff.minutes = (tot_a - tot_b) % 60;
  diff.hours = (tot_a - tot_b) / 60;

  return diff;
}

// B = A * n;
Time operator*(const Time& ra, double n)
{
  Time mult;
  long tot_min = ra.hours * n * 60 + ra.minutes * n;
  mult.hours = tot_min / 60;
  mult.minutes = tot_min % 60;

  return mult;
}

std::ostream& operator<< (std::ostream& ros, const Time& ra)
{
  ros << ra.hours << " hours, " << ra.minutes << " minutes";

  return ros;
}