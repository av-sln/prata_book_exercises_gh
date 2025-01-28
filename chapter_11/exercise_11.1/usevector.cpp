// usevector.cpp -- файл использования класса Vector

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "vect.hpp"

int main()
{
  srand(time(0));             // начальное значение генератора случайных чисел
  double direction;           // Направление (у)
  VECTOR::Vector step;        
  VECTOR::Vector result(0.0, 0.0);
  std::size_t steps = 0;      // счётчик шагов
  double target;              // заданное расстояние
  double dstep;               // длина шага
  // Ввод заданного расстояния
  std::cout << "Enter target distance (q to quit): ";
  while (std::cin >> target) {
    // Ввод длины шага
    std::cout << "Enter step length: ";
    if (!(std::cin >> dstep))
      break;
    std::string filename;       // имя файла для записи результата
    std::cout << "Enter your filename: ";
    std::cin.get();
    getline(std::cin, filename);
    std::ofstream fout;
    fout.open(filename);    
    fout << "Target distance: " << target << ", "
         << "Step size: " << dstep << std::endl;
    while (result.magval() < target) {
      fout << steps << ": " << result << std::endl; 
      direction = rand() % 360;
      step.reset(dstep, direction, VECTOR::Vector::POL);
      result = result + step;
      steps++;
    }
    fout << steps << result << std::endl;     // запись последней позиции
    fout << "After " << steps << " steps, the subject "
      "has the following location:\n";
    fout << result << std::endl;            
    result.polar_mode();        // устанавливаем режим POL
    fout << "or\n" << result << std::endl;
    // Вывод среднего значения на один шаг
    fout << "Average outward distance per step = "
         << result.magval() / steps << std::endl;

    steps = 0;
    result.reset(0.0, 0.0);
    std::cout << "Enter target distance (q to quit): ";
  }
  std::cout << "Bye!\n";
  std::cin.clear();
  while (std::cin.get() != '\n')
    continue;
  
  return 0;
}