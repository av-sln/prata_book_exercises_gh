// useqsales.cpp -- использование класса Sales

#include <iostream>
#include "qsales_class.h"

int main()
{
  // Используем конструктор по умолчанию
  std::cout << std::endl;
  std::cout << "Using the default constructor:" << std::endl;
  SALES::Sales one_default;
  one_default.ShowSales();

  // Используем конструктор с параметрами
  std::cout << std::endl;
  std::cout << "Using the constructor with parameters:" << std::endl;
  double sales[SALES::QUARTERS] {675.98, 5643.76, 875476.99, 65476.00};
  SALES::Sales two_option_one(sales, SALES::QUARTERS);
  std::cout << "Option #1:" << std::endl;
  two_option_one.ShowSales();
  // Вариант 2: не полный массив
  double sales_2[3] {564.99, 8875954.09, 87778.00};
  SALES::Sales two_option_two {sales_2, 3};
  std::cout << std::endl;
  std::cout << "Option #2:" << std::endl;
  two_option_two.ShowSales();

  // Используем интерактивную версию
  std::cout << std::endl;
  std::cout << "Using interactive version:" << std::endl;
  SALES::Sales three;
  three.SetSales();
  three.ShowSales();

  return 0;
}