// person.cpp -- определения методов класса Person

#include <iostream>
#include <cstring>
#include <string>
#include "person.h"

// Конструктор #2
Person::Person(const std::string& lname, const char* fname)
{
  lname_ = lname;
  strcpy(fname_, fname);
}

// Деструктор 
Person::~Person()
{}

// Отображение lname и fname
void Person::Show() const 
{
  std::cout << "Person's full name is " << fname_ << " "
            << lname_ << std::endl;
}

void Person::FormalShow() const 
{
  std::cout << "Person's full name is " << lname_ << ", "
            << fname_ << std::endl;
}