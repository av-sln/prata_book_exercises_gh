// useplorg.cpp -- использование класса Plorg

#include <iostream>
#include "plorg.hpp"

int main()
{
  // Используем конструктор по умолчанию
  std::cout << std::endl;
  std::cout << "Using the default constructor:" << std::endl;
  Plorg plorg_1;
  plorg_1.showplorg();

  // Используем конструктор с аргументами Вариант 1
  // есть имя нет CI
  Plorg plorg_2("Plorgman");
  std::cout << std::endl;
  std::cout << "Using the constructor with arguments. Option 1:" << std::endl;
  plorg_2.showplorg();

  // Используем конструктор с аргументами Вариант 2
  // есть имя и есть CI
  Plorg plorg_3("Plorgwoman", 90);
  std::cout << std::endl;
  std::cout << "Using the constructor with arguments. Option 2:" << std::endl;
  plorg_3.showplorg();

  // Изменение индекса CI
  plorg_1.changeindex(300);
  plorg_2.changeindex(400);
  plorg_3.changeindex(500);
  std::cout << std::endl;
  std::cout << "Change index CI:" << std::endl;
  std::cout << "Object 1:" << std::endl;
  plorg_1.showplorg();
  std::cout << std::endl;
  std::cout << "Object 2:" << std::endl;
  plorg_2.showplorg();
  std::cout << std::endl;
  std::cout << "Object 3:" << std::endl;
  plorg_3.showplorg();

  return 0;
}