// usecomplex117.cpp -- использование класса Complex

#include <iostream>
#include "complex117.hpp"

int main()
{
  Complex a(3.0, 4.0);    // инициализация значением (3, 4i)
  Complex c;
  std::cout << std::endl;
  // Ввод комплексного числа (q для завершения)
  std::cout << "Enter a complex number (q to quit):\n";
  while (std::cin >> c) {
    std::cout << "c is " << c << std::endl; // значение с
    // Значение сопряжённого числа
    std::cout << "complex conjugate is " << ~c << std::endl;
    std::cout << "a is " << a << std::endl; // значение а
    std::cout << "a + c is " << a + c << std::endl; // значение a + c
    std::cout << "a - c is " << a - c << std::endl; // значение a - c
    std::cout << "a * c is " << a * c << std::endl; // значение a * c
    std::cout << "2 * c is " << 2 * c << std::endl; // значение 2 * c
    std::cout << "Enter a complex number (q to quit):\n";
  }
  std::cout << "Done!\n";

  return 0;
}