// useperson.cpp -- применение методов класса Person

#include <iostream>
#include "person.h"

int main()
{
  Person one;                         // без аргументов
  Person two("Smythecraft");          // с одним аргументом
  Person three("Dimwiddy", "Sam");    // с двумя аргументами

  // Отображение первого объекта
  std::cout << std::endl;
  std::cout << "Displaying the first object:" << std::endl;
  one.Show();
  one.FormalShow();

  // Отоброажение второго объекта
  std::cout << std::endl;
  std::cout << "Displaying the second object:" << std::endl;
  two.Show();
  two.FormalShow();

  // Отображение третьего объекта
  std::cout << std::endl;
  std::cout << "Displaying the third object:" << std::endl;
  three.Show();
  three.FormalShow();

  return 0;  
}