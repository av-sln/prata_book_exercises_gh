// usetime114.cpp -- использование класса Time

#include <iostream>
#include "time114.hpp"

int main()
{
  Time aida(3, 35);
  Time tosca(2, 48);
  Time temp;

  std::cout << std::endl;
  std::cout << "Aida and Tosca:\n";
  std::cout << aida << "; " << tosca << std::endl;
  temp = aida + tosca;      // operator+()
  std::cout << "Aida + Tosca: " << temp << std::endl;
  std::cout << std::endl;
  temp = aida * 1.17;        // operator*()
  std::cout << "Aida * 1.17: " << temp << std::endl;
  std::cout << "10.0 * Tosca: " << 10.0 * tosca << std::endl; // operator*()

  return 0; 
}