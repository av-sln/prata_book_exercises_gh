// useplacenew.cpp -- файл использования методов из placenew.cpp
// компилировать: g++ -Wall placenew.cpp useplacenew.cpp

#include <iostream>
#include "placenew.h"

int main()
{
  // Создаём массив C-style строк для элемента dross
  char str_ar[ArSize][20] = {"Dross name one", "Dross name two"};
  // Создаём массив интов для элемента slag
  int slag_arr[ArSize] = {1, 2};
  char buffer[BUF];                           // создаём блок памяти из 512 байт
  chaff* ptr_st = new (buffer) chaff[ArSize]; // размещаем в буфере памяти массив из двух структур

  // Вариант 1
  std::cout << std::endl;
  std::cout << "Option 1:" << std::endl;
  for (int i = 0; i < ArSize; i++)
    setstruct(ptr_st + i, str_ar[i], slag_arr[i]);
  for (int i = 0; i < ArSize; i++)
    showstruct(ptr_st + i);

  // Вариант 2
  chaff* ptr = new chaff[ArSize];
  for (int i = 0; i < ArSize; i++)
    setstruct(ptr + i, str_ar[i], slag_arr[i]);
  std::cout << std::endl;
  std::cout << "Option 2:" << std::endl;
  for (int i = 0; i < ArSize; i++)
    showstruct(ptr + i);
  delete [] ptr;

  return 0;

}