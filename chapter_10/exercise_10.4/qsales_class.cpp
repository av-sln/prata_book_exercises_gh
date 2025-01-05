// qsales_class.cpp -- файл реализации методов класса Sales

#include <iostream>
#include "qsales_class.h"

// Конструктор по умолчанию
SALES::Sales::Sales()
{
  for (int i = 0; i < QUARTERS; i++)
    sales_[i] = 0;
  average_ = 0;
  min_ = 0;
  max_ = 0;
}

// Конструктор с параметрами
SALES::Sales::Sales(const double sales[], const int n)
{
  for (int i = 0; i < n; i++) 
    sales_[i] = sales[i];
  if (n < QUARTERS)                   
    for (int i = n; i < QUARTERS; i++)
      sales_[i] = 0;

  average_ = Average(sales_, n);    // находим среднее арифметическое
  max_ = MaxElement(sales_, n);     // находим максимальное значение
  min_ = MinElement(sales_, n);     // находим минимальное значение
}

// Интерактивный метод
void SALES::Sales::SetSales()
{
  for (int i = 0; i < QUARTERS; i++) {
    std::cout << "Enter sales for the Quarter #" << i + 1 << ": ";
    std::cin >> sales_[i];
  }

  average_ = Average(sales_, QUARTERS); // находим среднее арифметическое
  max_ = MaxElement(sales_, QUARTERS);  // находим максимальное значение
  min_ = MinElement(sales_, QUARTERS);  // находим минимальное значение
}

// Отображение информации объекта класса Sales
void SALES::Sales::ShowSales() const
{
  std::cout << "Total sales for the year: ";
  for (int i = 0; i < QUARTERS; i++) 
    std::cout << sales_[i] << ", ";
  std::cout << "\b\b" << ";" << std::endl;
  std::cout << "Average sales: " << average_ << std::endl;
  std::cout << "Maximum sales: " << max_ << std::endl;
  std::cout << "Minimum sales: " << min_ << std::endl;
}

// Среднее арифметическое
double SALES::Sales::Average(const double sales[], const int n)
{
  double sum = 0.0;
  double average = 0.0;
  for (int i = 0; i < n; i++)
    sum += sales[i];
  average = sum /n;
  return average;  
}

// Максимальное значение
double SALES::Sales::MaxElement(const double sales[], const int n)
{
  double max = sales[0];
  for (int i = 0; i < n; i++)
    if (max < sales[i])
      max = sales[i];
  return max;
}

// Минимальное значение
double SALES::Sales::MinElement(const double sales[], const int n)
{
  double min = sales[0];
  for (int i = 0; i < n; i++)
    if (min > sales[i])
      min = sales[i];
  return min;
}