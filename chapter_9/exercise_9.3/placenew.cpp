// placenew.cpp -- реализация методов из файла placenew.h
// компилировать совместно с useplacenew.cpp

#include <iostream>
#include <cstring>
#include "placenew.h"

void setstruct(chaff* p_st, char* str, int n)
{
  strcpy(p_st->dross, str);
  p_st->slag = n;
}

void showstruct(const chaff* p_st)
{
  std::cout << "Element dross is " << p_st->dross << std::endl;
  std::cout << "Element slag is " << p_st->slag << std::endl;
}