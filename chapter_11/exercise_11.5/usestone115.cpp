// usestone115.cpp -- использование класса Stonewt

#include <iostream>
#include "stone115.hpp"

int main()
{
  // Создаём два объекта
  Stonewt one_obj {139.7};
  Stonewt two_obj {6, 2.0};
  std::cout << std::endl;
  std::cout << "Объект 1: ";
  std::cout << one_obj << std::endl;
  std::cout << "Объект 2: ";
  std::cout << two_obj << std::endl;;

  // Сложение объектов C = A + B
  one_obj = one_obj + two_obj;
  std::cout << std::endl;
  std::cout << "one_obj = one_obj + two_obj\n";
  std::cout << one_obj << std::endl;

  // Умножение объектов C = A * B
  one_obj = one_obj * two_obj;
  std::cout << std::endl;
  std::cout << "one_obj = one_obj * two_obj\n";
  std::cout << one_obj << std::endl;

  // Вычитание объектов C = A - B
  one_obj = one_obj - two_obj;
  std::cout << std::endl;
  std::cout << "one_obj = one_obj - two_obj\n";
  std::cout << one_obj << std::endl;

  // Умножение объекта на число C = A * n
  one_obj = one_obj * 1.3;
  std::cout << std::endl;
  std::cout << "one_obj = one_obj * 1.3\n";
  std::cout << one_obj << std::endl;

  // C = n * A
  one_obj = 1.7 * one_obj;
  std::cout << "one_obj = 1.7 * one_obj\n";
  std::cout << one_obj << std::endl;

  // Установка формы интерпретации
  one_obj.set_stone();
  std::cout << std::endl;
  std::cout << "Отображение в стоунах: ";
  std::cout << one_obj << std::endl;
  one_obj.set_pounds();
  std::cout << "Отображение в целочисленных фунтах: ";
  std::cout << one_obj << std::endl;
  one_obj.set_float();
  std::cout << "Отображение в фунтах с плавающей точкой: ";
  std::cout << one_obj << std::endl;

  return 0;
}