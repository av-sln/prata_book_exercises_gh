// usestock123.cpp -- использование класса Stock123

#include <iostream>
#include "stock123.hpp"

const int STKS = 4;

int main()
{
  // Создание массива инициализированных объектов
  Stock123 stocks[STKS] = {
    Stock123("NanoSmart", 12, 20.0),
    Stock123("Boffo Objects", 200, 2.0),
    Stock123("Monolithic Obelisk", 130, 3.25),
    Stock123("Fleep Enterpises", 60, 6.5)
  };
  std::cout << "Stock holdings:\n";
  int st;
  for (st = 0; st < STKS; st++)
    std::cout << stocks[st] << std::endl;

  // Установка указателя на первый элемент
  const Stock123 *top = &stocks[0];
  for (st = 1; st < STKS; st++)
    top = &top->topval(stocks[st]);

  // Теперь top указывает на самый ценный пакет акций
  std::cout << "\nMost valuable holding:\n";
  std::cout << *top << std::endl;

  return 0;
}