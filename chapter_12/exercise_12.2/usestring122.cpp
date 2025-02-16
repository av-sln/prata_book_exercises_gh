// usestring122.cpp -- использование класса String122

#include <iostream>
#include "string122.hpp"

int main()
{
  // Используется конструктор с аргументами
  String122 s1(" and I am a C++ student.");
  // Ввод имени
  String122 s2 = "Please enter your name: ";
  // Конструктор по умолчанию
  String122 s3;
  // Использование перегруженной операции <<
  std::cout << s2;
  // Использование перегруженной операции >>
  std::cin >> s3;
  // Использование перегруженных операций =, +
  s2 = "My name is " + s3;
  std::cout << s2 << ".\n";
  s2 = s2 + s1;
  // Преобразование строки в верхний регистр
  s2.stringup();
  std::cout << "The string\n" << s2 << "\ncontains "
            << s2.numchar('A')
            << " 'A' characters in it.\n";
  s1 = "red";
  String122 rgb[3] = { String122(s1), String122("green"), String122("blue") };
  std::cout << "Enter the name of a primary color for mixing light: ";
  String122 ans;
  bool success = false;
  while (std::cin >> ans) {
    ans.stringlow();
    for (int i = 0; i < 3; i++) {
      if (ans == rgb[i]) {
        std::cout << "That's right!\n";
        success = true;
        break; 
      }
    }
    if (success)
      break;
    else
      std::cout << "Try again!\n";
  }
  std::cout << "Bye\n";

  return 0;  
}