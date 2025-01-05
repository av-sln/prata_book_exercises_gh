// usegolf.cpp -- использование методов Golf

#include <iostream>
#include "golf.h"

const int SIZE = 5;

int main()
{
  // Создание статического объекта
  Golf ivan_petrov {"Ivan Petrov", 10};
  std::cout << std::endl;
  std::cout << "Displayong static object:" << std::endl;
  ivan_petrov.ShowGolf();

  // Меняем гандикап
  std::cout << std::endl;
  std::cout << "Change handicap:" << std::endl;
  ivan_petrov.HandiCap(25);
  ivan_petrov.ShowGolf();

  // Использование интерактивной функции
  std::cout << std::endl;
  std::cout << "Using an interactive method:" << std::endl;
  // Создаём динамический массив объектов Golf
  Golf* golf_players = new Golf[SIZE];
  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    int flag = golf_players[i].SetGolf();
    if (flag == 0)
      break;   
    else 
      count++;
  }

  // Отображение данных динамического массива
  std::cout << std::endl;
  std::cout << "Displaying dinamic array data:" << std::endl;
  for (int i = 0; i < count; i++)
    golf_players[i].ShowGolf();
  std::cout << std::endl;  

  return 0;
}