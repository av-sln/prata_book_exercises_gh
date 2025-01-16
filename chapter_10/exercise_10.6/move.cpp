// move.cpp -- файл реализации методов класса Move

#include <iostream>
#include "move.hpp"

// Конструктор
Move::Move(double a, double b)
{
  x = a;
  y = b;
}

// Деструктор
Move::~Move()
{}

// Отображение текущих значений элементов объекта
void Move::showmove() const
{
  std::cout << "Element x: " << x << std::endl;
  std::cout << "Element y: " << y << std::endl;
}

// Добавление данных одного объекта к другому
Move Move::add(const Move& m) 
{
  x += m.x;
  y += m.y;
  return *this;
}

// Сброс значений
void Move::reset(double a, double b)
{
  x = a;
  y = b;
}