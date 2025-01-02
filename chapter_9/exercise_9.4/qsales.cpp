// qsales.cpp -- определение функций из файла qsales.h

#include <iostream>
#include "qsales.h"

// Неитерактивная версия
void SALES::setSales(Sales& s, const double ar[], int n)
{
  // Копируем значения из массива ar в член sales структуры s
  for (int i = 0; i < n; i++) 
    s.sales[i] = ar[i];
  

  // Если элементов меньше чем QUARTERS, то устанавливаем оставшиеся члены в 0
  if (n < QUARTERS)
    for (int i = n; i < QUARTERS; i ++)
      s.sales[i] = 0;

  // Вычисляем и сохраняем среднее арифметическое
  double sum = 0;
  for (int i = 0; i < n; i++) 
    sum += s.sales[i];
  s.average_ = sum / n;

  // Находим максимальное и минимальное значения
  s.min_ = s.sales[0];
  s.max_ = s.sales[0];
  for (int i = 0; i < n; i++) {
    if (s.min_ > s.sales[i])
      s.min_ = s.sales[i];
    else if (s.max_ < s.sales[i])
      s.max_ = s.sales[i];
  }
}

// Интерактивная версия
void SALES::setSales(Sales& s)
{ 
  // Вводим продажи за 4 квартала
  for (int i = 0; i < QUARTERS; i++) {
    std::cout << "Enter the sales for the Quarter #" << i + 1 << ": ";
    std::cin >> s.sales[i];
  }

  // Вычисляем и сохраняем среднее арифметическое
  double sum = 0;
  for (int i = 0; i < QUARTERS; i++)
    sum += s.sales[i];
  s.average_ = sum / QUARTERS;

  // Находим максимальное и минимальное значения
  s.min_ = s.sales[0];
  s.max_ = s.sales[0];
  for (int i = 0; i < QUARTERS; i++) {
    if (s.min_ > s.sales[i])
      s.min_ = s.sales[i];
    else if (s.max_ < s.sales[i])
      s.max_ = s.sales[i];    
  }
}

// Отображает всю информацию из структуры s
void SALES::showSales(const Sales& s)
{
  std::cout << "Sales for 4 quartes: ";
  for (int i = 0; i < QUARTERS; i++)
    std::cout << s.sales[i] << ", ";
  std::cout << "\b\b" << "." << std::endl;
  std::cout << "Average sales: " << s.average_ << std::endl;
  std::cout << "Minimum sales: " << s.min_ << std::endl;
  std::cout << "Maximum sales: " << s.max_ << std::endl;
}