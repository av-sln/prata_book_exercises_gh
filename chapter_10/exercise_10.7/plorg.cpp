// plorg.cpp -- файл реализации методов класса Plorg

#include <iostream>
#include <cstring>
#include "plorg.hpp"

// Конструктор по умолчанию
Plorg::Plorg()
{
  strcpy(name_, "Plorga");
  ci_ = 50;
}

// Конструктор с аргументами
Plorg::Plorg(const char* name, int ci)
{
  strcpy(name_, name);
  ci_ = ci;
}

// Деструктор
Plorg::~Plorg()
{}

// Изменение индекса CI
void Plorg::changeindex(const int ci)
{
  ci_ = ci;
}

// Отображение объекта Plorg
void Plorg::showplorg() const
{
  std::cout << "Plorg's name     : " << name_ << std::endl;
  std::cout << "Contentment index: " << ci_ << std::endl;
}