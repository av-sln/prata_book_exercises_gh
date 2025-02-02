// stone116.hpp -- заголовочный файл класса Stonewt

#ifndef STONE116_HPP_
#define STONE116_HPP_
#include <iostream>

class Stonewt
{
private:
  static const int PdsStn_ = 14;
  int stone_;         // вес в стоунах
  double stn_left_;   // дробная часть в фунтах
  double pounds_;     // вес в фунтах

public:
  // Конструктор по умолчанию
  Stonewt();    
  // Конструктор объекта с аргументом в фунтах
  Stonewt(double pds);
  // Конструктор объекта с аргументами в стоунах и фунтах
  Stonewt(int stn, double pds = 0.0);
  // Деструктор
  ~Stonewt();

  // Перегрузка операций
  // A == B
  bool operator==(const Stonewt& rb) const;
  // A != B
  bool operator!=(const Stonewt& rb) const;
  // A < B
  bool operator<(const Stonewt& rb) const;
  // A > B
  bool operator>(const Stonewt& rb) const;
  // A <= B
  bool operator<=(const Stonewt& rb) const;
  // A >= B
  bool operator>=(const Stonewt& rb) const;

  // Друзья
  friend std::ostream& operator<<(std::ostream& rout, const Stonewt& rb);
};

#endif