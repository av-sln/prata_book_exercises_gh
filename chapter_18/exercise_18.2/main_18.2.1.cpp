// main_18.2.1.cpp
// Тест-драйв класса Cpmv

#include <iostream>
#include <string>
#include "Cpmv.hpp"

int main() {
   // Инициализируем тестовые аргументы
   std::string qcode{"Argument one"};
   std::string zcode{"Argument two"};

   // Тестирование конструктора по умолчанию
   std::cout << std::endl;
   std::cout << "Default constructor testing...\n";
   Cpmv Object_1;
   Object_1.Display();
   
   // Тестирование конструктора с аргументами
   std::cout << std::endl;
   std::cout << "Constructor with arguments testing...\n";
   Cpmv Object_2{qcode, zcode};
   Object_2.Display();

   // Тестирование копирующего конструктора
   std::cout << std::endl;
   std::cout << "Copy constructor testing...\n";
   Cpmv Object_3{Object_2};
   Object_3.Display();

   // Тестирование оператора копирующего присваивания
   std::cout << std::endl;
   std::cout << "Copy assignment operator testing...\n";
   Object_1 = Object_3;
   Object_1.Display();

   // Тестирование перемещающего конструктора
   std::cout << std::endl;
   std::cout << "Move constructor testing...\n";
   // Создаём объект с произвольными аргументами
   Cpmv Object_4{"Argument three", "Argument four"};
   Cpmv Object_5{std::move(Object_4)};
   Object_5.Display();

   // Тестирование оператора перемещающего присваивания
   std::cout << std::endl;
   std::cout << "Move assignment operator testing...\n";
   Object_5 = std::move(Object_1);
   Object_5.Display();

   // Тестирование операции конкатенации
   std::cout << std::endl;
   std::cout << "Operator+() testing...\n";
   // Создаём два объекта с произвольными аргументами
   Cpmv Object_6{"one ", "two "};
   Cpmv Object_7{"hundred", "thousand"};
   Cpmv Object_8 = Object_6 + Object_7;
   Object_8.Display();
   std::cout << std::endl;  
}