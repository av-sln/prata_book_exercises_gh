// useqsales.cpp -- 
// Компилировать: g++ -Wall useqsales.cpp qsales.cpp

#include <iostream>
#include "qsales.h"

int main()
{
  // Объявляем два объекта Sales
  SALES::Sales sales_1;
  SALES::Sales sales_2;

  // Использование интерактивной версии
  std::cout << std::endl;
  std::cout << "Using interactive version:" << std::endl;
  SALES::setSales(sales_1);
  SALES::showSales(sales_1);

  // Использование неинтерактивной версии с неполными данными
  double array_1[SALES::SIZE] = {543.98, 356.76};
  std::cout << std::endl;
  std::cout << "Using non-interactiv version with not full data:"
            << std::endl;
  SALES::setSales(sales_2, array_1, SALES::SIZE);
  SALES::showSales(sales_2);

  // Использование неинтерактивной версии с полными данными
  double array_2[SALES::QUARTERS] = {869.97, 678.43, 567.89, 342.54};
  std::cout << std::endl;
  std::cout << "Using non-interactiv version with full data:"
            << std::endl;
  SALES::setSales(sales_2, array_2, SALES::QUARTERS);
  SALES::showSales(sales_2);

  return 0;

}