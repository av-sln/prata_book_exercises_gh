// stone115.hpp -- загловочный файл класса Stonewt

#ifndef STONE115_HPP_
#define STONE115_HPP_
#include <iostream>

class Stonewt
{
private:
  static const int PdsStn = 14;
  enum Mode {Stone, Pounds, Float};
  int stone_;           // стоуны
  double pds_left_;
  int pounds_;          // целочисленные фунты
  double flt_pounds_;   // фунты с плавающей точкой
  Mode mode_;

public:
  //Конструктор по умолчанию
  Stonewt();
  // Конструктор для значения в фунтах с плавающей точкой
  Stonewt(double pds, Mode form = Float);
  // Конструктор для значения в стоунах и фунтах
  Stonewt(int stn, double pds, Mode form = Float);
  // Деструктор
  ~Stonewt();

  // Перегрузка операций
  // C = A + B
  Stonewt operator+(const Stonewt& rb) const;
  // C = A - B
  Stonewt operator-(const Stonewt& rb) const;
  // C = A * B
  Stonewt operator*(const Stonewt& rb) const;
  // C = A * n
  Stonewt operator*(double n) const;
  // Установка форм интерпретации
  void set_stone();
  void set_pounds();
  void set_float();

  // Друзья
  // C = n * A
  friend Stonewt operator*(double n, const Stonewt& ra);
  friend std::ostream& operator<<(std::ostream& ros, const Stonewt& ra);
};

#endif