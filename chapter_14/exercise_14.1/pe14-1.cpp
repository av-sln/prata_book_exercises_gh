// pe14-1.cpp -- класс Wine c использованием включения

#include <iostream>
#include "wine.h"

int main()
{
  std::cout << "Enter name of wine: ";   // ввод названия вина
  char lab[50];
  std::cin.getline(lab, 50);
  std::cout << "Enter number of years: ";  // ввод количества годов сбора винограда
  int yrs;
  std::cin >> yrs;
  Wine holding(lab, yrs); // сохранение названия, лет,
                          // создание массивов из yrs элементов
  holding.GetBottles();   // предложение ввести год и количество бутылок
  holding.Show();
  const int YRS = 3;
  int y[YRS] = {1993, 1995, 1998};
  int b[YRS] = {48, 60, 72};
  // Создание нового объекта, инициализация
  // с использованием данных из массивов y и b
  Wine more("Gushing Grape Red", YRS, y, b);
  more.Show();
  std::cout << "Total bottles for " << more.Label()  // использует метод Label()
            << ": " << more.sum() << std::endl;           // использует метод sum()
  std::cout << "Bye!\n";

  return 0;
}