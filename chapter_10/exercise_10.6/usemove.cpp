// usemove.cpp -- использование класса Move

#include <iostream>
#include "move.hpp"

int main()
{
  Move one_obj;
  Move two_obj(10, 20);

  std::cout << std::endl;
  std::cout << "Displaying new objects:" << std::endl;
  one_obj.showmove();
  two_obj.showmove();

  std::cout << std::endl;
  std::cout << "Using the add method:" << std::endl;
  one_obj.add(two_obj);
  one_obj.showmove();
  two_obj.showmove();

  std::cout << std::endl;
  std::cout << "Using the reset method:" << std::endl;
  one_obj.reset();
  two_obj.reset();
  one_obj.showmove();
  two_obj.showmove();

  return 0;
}