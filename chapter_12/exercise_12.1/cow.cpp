// cow.cpp -- файл реализации методов класса Cow

#include "cow.hpp"
#include <cstring>
#include <iostream>

// Конструктор по умолчанию
Cow::Cow()
{
  std::strcpy(name_, "no name");
  hobby_ = new char[1];
  hobby_[0] = '\0';
  weight_ = 0.0;
}

// Конструктор с аргументами
Cow::Cow(const char *pnm, const char *pho, double wt)
{
  std::strcpy(name_, pnm);
  int ln = std::strlen(pnm);
  hobby_ = new char[ln + 1];
  std::strcpy(hobby_, pho);
  weight_ = wt;
}

// Конструктор копирования
Cow::Cow(const Cow& rc)
{
  std::strcpy(name_, rc.name_);
  int ln = std::strlen(rc.hobby_);
  hobby_ = new char[ln + 1];
  std::strcpy(hobby_, rc.hobby_);
  weight_ = rc.weight_;
}

// Деструктор
Cow::~Cow()
{
  delete [] hobby_;
}

// Перегрузка операций
// Перегруженный оператор присваивания
Cow& Cow::operator=(const Cow& rc)
{
  if (std::strcmp(name_, rc.name_) == 0 && hobby_ == rc.hobby_
    && weight_ == rc.weight_)
      return *this;
  delete [] hobby_;
  std::strcpy(name_, rc.name_);
  int ln = std::strlen(rc.hobby_);
  hobby_ = new char[ln + 1];
  std::strcpy(hobby_, rc.hobby_);
  weight_ = rc.weight_;
  return *this;
}

// Отображение всех данных объекта Cow
void Cow::ShowCow() const
{
  std::cout << "Name  : " << name_ << std::endl;
  std::cout << "Hobby : " << hobby_ << std::endl;
  std::cout << "Weight: " << weight_ << std::endl; 
}