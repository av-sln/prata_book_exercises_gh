// uselist.cpp -- использование методов класса List

#include <iostream>
#include "list.hpp"

void qtr(double& x) { x = x * x * x * x; }

int main()
{
  List my_list_1;   // создаём пустой список #1
  List my_list_2;   // создаём пустой список #2

  // Проверяем пуст ли список
  std::cout << std::endl;
  std::cout << "Using the isempty() method:" << std::endl;
  if (my_list_1.isempty())
    std::cout << "The list is empty." << std::endl;
  else
    std::cout << "The list is not empty." << std::endl;

  // Проверяем полон ли список
  std::cout << std::endl;
  std::cout << "Using the isfull() method:" << std::endl;
  if (my_list_1.isfull())
    std::cout << "The list is full." << std::endl;
  else
    std::cout << "The list is not full yet." << std::endl;

  // Проверяем добавление элементов в список
  // вариант 1 наполняем список полностью
  std::cout << std::endl;
  std::cout << "Using the add() method. Option #1:" << std::endl;
  double a = 453.78;
  while (my_list_1.add(a))      // ввод элементов массива в цикле 
    a *= 2;
  // Проверяем работу метода add()
  // должно быть 10 элементов
  my_list_1.show();
  if (my_list_1.isempty())
    std::cout << "The list is empty." << std::endl;
  else
    std::cout << "The list is not empty." << std::endl;
  if (my_list_1.isfull())
    std::cout << "The list is full." << std::endl;
  else
    std::cout << "The list is not full." << std::endl;


  // Проверяем добавление элементов в список 
  // вариант 2 наполняем список не полностью
  std::cout << std::endl;
  std::cout << "Using the add() method. Option #2:" << std::endl;
  double b = 193.87;
  for (int i = 0; i < 5 && !(my_list_2.isfull());  i++) {
    my_list_2.add(b);
    b *= 1.5;
  }
  // Проверяем работу метода add()
  // должно быть 5 элементов
  my_list_2.show();
  if (my_list_2.isempty())
    std::cout << "The list is empty." << std::endl;
  else
    std::cout << "The list is not empty." << std::endl;
  if (my_list_2.isfull())
    std::cout << "The list is full." << std::endl;
  else 
    std::cout << "The list is not full yet." << std::endl;
  
  // Проверяем работу метода visit()
  std::cout << std::endl;
  std::cout << "Using the visit() method:" << std::endl;
  my_list_2.visit(qtr);
  my_list_2.show();

  return 0;  
}