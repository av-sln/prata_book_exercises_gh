// useclasses.cpp -- использование абстрактного и производных классов

#include <iostream>
#include <cstring>
#include "classes.h"


const int SIZE = 3;         // количество элементов в массиве
const int STR_SIZE = 80;    // количество символов в строковых данных

void set_array(baseABC* ar[], int n);

int main()
{
  // Используемые переменные
  char choice;                  // символ выбора класса объекта
  char tmp_lbl[STR_SIZE];       // вводимое значение поля label
  int  tmp_rt;                  // вводимое значение поля rating
  char tmp_clr[STR_SIZE];       // вводимое значение поля color
  char tmp_stl[STR_SIZE];       // вводимое значение поля style

  std::cout << std::endl;
  // Создаём массив указателей на абстрактный базовый класс
  baseABC* ptr_array_1[SIZE];
  
  // Заполнение массива
  // Значения полей вводятся пользователем
  // Для создания объектов используется конструктор с аргументами
  for (int i = 0; i < SIZE; i++) {
    std::cout << "Выберите класс создаваемого объекта:\n"
              << "1 - класс baseDMA\n"
              << "2 - класс lacksDMA\n"
              << "3 - класс hasDMA\n"
              << "-> ";
    while (std::cin >> choice && (choice != '1' && choice != '2' &&
      choice != '3'))
      std::cout << "Введите цифры 1, 2 или 3: ";

    switch (choice) {
      case '1': std::cout << "Введите значение поля label: ";
                std::cin.get();
                std::cin.getline(tmp_lbl, STR_SIZE);
                std::cout << "Введите значение поля rating: ";
                (std::cin >> tmp_rt).get();
                ptr_array_1[i] = new baseDMA(tmp_lbl, tmp_rt);
                break;

      case '2': std::cout << "Введите значение поля label: ";
                std::cin.get();
                std::cin.getline(tmp_lbl, STR_SIZE);
                std::cout << "Введите значение поля rating: ";
                (std::cin >> tmp_rt).get();
                std::cout << "Введите значение поля color: ";
                std::cin.getline(tmp_clr,STR_SIZE);
                ptr_array_1[i] = new lacksDMA(tmp_clr, tmp_lbl, tmp_rt);
                break;

      case '3': std::cout << "Введите значение поля style: ";
                std::cin.get();
                std::cin.getline(tmp_stl, STR_SIZE);
                std::cout << "Введите значение поля label: ";
                std::cin.getline(tmp_lbl, STR_SIZE);
                std::cout << "Введите значение поля rating: ";
                (std::cin >> tmp_rt).get();
                ptr_array_1[i] = new hasDMA(tmp_stl, tmp_lbl, tmp_rt);
                break;                
    }
  }

  // Вывод массива объектов 
  std::cout << std::endl;
  std::cout << "Вывод массива объектов #1:\n";
  for (int i = 0; i < SIZE; i++) {
    ptr_array_1[i]->view();
    std::cout << std::endl;
  }

  // Освобождение выделенной памяти 
  for (int i = 0; i < SIZE; i++)
    delete ptr_array_1[i];

  return 0;  
} 
