// usestack124.cpp -- использование класса Stack

#include <iostream>
#include "stack124.hpp"



int main()
{
  int sz;         // размер стека
  Item itm;       // элемент стека
  std::cout << std::endl;
  std::cout << "Enter the size of the stack: ";
  std::cin >> sz;
  // Создание пустого стека
  Stack oneSt(sz);
  // Наполнение стека
  int cnt = 0;
  while (!oneSt.isfull()) {
    std::cout << "Enter the element #" << cnt + 1 << ": ";
    std::cin >> itm;
    oneSt.push(itm);
    cnt++;
  }
  
  // Использование конструктора кoпирования
  std::cout << std::endl;
  std::cout << "Using the copy constructor:\n";
  Stack twoSt(oneSt);
  // Извлечение элементов из стека
  while (!twoSt.isempty())
    twoSt.pop(itm);

  // Использование операции присваивания
  // Создание стека по умолчанию
  std::cout << std::endl;
  std::cout << "Using the operator=(): \n";
  Stack threeSt;
  threeSt = oneSt;
  while (!threeSt.isempty())
    threeSt.pop(itm);

  return 0;  
}

