// use_error153.cpp -- использование класса исключений logic_error
#include <iostream>
#include <cmath>
#include <exception>
#include "error153.h"

// Протитпы функций
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
  double x, y, z;
  std::cout << std::endl;
  std::cout << "Enter two numbers: ";
  while (std::cin >> x >> y) {
    try {
      z = hmean(x, y);
      std::cout << "Harmonic mean of " << x << " and " << y 
                << " is " << z << std::endl;
      z = gmean(x, y);
      std::cout << "Geometric mean of " << x << " and " << y
                << " is " << z << std::endl;
      std::cout << "Enter next set of numbers <q to quit>: ";
    }
    catch (std::logic_error& ex) {
      if (typeid(bad_hmean) == typeid(ex)) {
          dynamic_cast<bad_hmean&>(ex).show();
          std::cout << ex.what() << std::endl;;
          break;
      } else if (typeid(bad_gmean) == typeid(ex)) {
          dynamic_cast<bad_gmean&>(ex).show();
          std::cout << ex.what() << std::endl;
          break;
      }
    }
  }  
  std::cout << "Bye!\n";

  return 0;
}

double hmean(double a, double b)
{
  if (a == -b)
    throw bad_hmean("Error is in hmean. Invalid arguments a = -b.", a, b);
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
  if (a < 0 || b < 0)
    throw bad_gmean("Error is in gmean(). Arguments should be >= 0.", a, b);
  return std::sqrt(a * b);
}