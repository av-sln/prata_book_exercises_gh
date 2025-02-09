// usecow.cpp -- использование класса Cow

#include <iostream>
#include "cow.hpp"

int main()
{
  // Создаём дефолтный объект
  Cow defobj;
  std::cout << std::endl;
  std::cout << "Created default object:\n";
  defobj.ShowCow();

  // Создаём объект с аргументами
  Cow argobj("A name", "H hobby", 20.0);
  std::cout << std::endl;
  std::cout << "Created object with arguments:\n";
  argobj.ShowCow(); 

  // Создаём объект с помощью конструктора копирования
  Cow cpobj(argobj);
  std::cout << std::endl;
  std::cout << "Create an object using the copy constructor:\n";
  cpobj.ShowCow();

  // Присвоим дефолтному объекту значения объекта с аргументами
  defobj = argobj;
  std::cout << std::endl;
  std::cout << "Assign default object values to the object with arguments:\n";
  defobj.ShowCow(); 

  return 0;
}