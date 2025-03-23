// methods.cpp -- файл реализации методов класса Cd и Classic

#include <iostream>
#include <cstring>
#include "classic.h"

// Методы базового класса Cd
// Конструктор по умолчанию
Cd::Cd()
{
  std::strcpy(performers, "None");
  std::strcpy(label, "none");
  selections = 0;
  playtime = 0.0;
}

// Конструктор с аргументами
Cd::Cd(const char* ps1, const char* ps2, int n, double x)
{
  std::strcpy(performers, ps1);
  std::strcpy(label, ps2);
  selections = n;
  playtime = x;
}

// Вывод информации о компакт-диске
void Cd::Report() const
{
  std::cout << "Performers   : " << performers << std::endl;
  std::cout << "Name of album: " << label << std::endl;
  std::cout << "Tracks       : " << selections << std::endl;
  std::cout << "Play Time    : " << playtime << std::endl;
}

// Перегрузка операции присваивания
Cd& Cd::operator=(const Cd& rcd)
{
  if (this == &rcd)
    return *this;
  else {
    std::strcpy(performers, rcd.performers);
    std::strcpy(label, rcd.label);
    selections = rcd.selections;
    playtime = rcd.playtime;
    return *this;
  }
}

// Методы производного класса Classic
// Конструктор по умолчанию
Classic::Classic() : Cd()
{
  std::strcpy(favorite, "none");
}

// Конструктор с аргументами
Classic::Classic(const char* pf, const char* ps1, const char* ps2, int n,
  double x) : Cd(ps1, ps2, n, x)
{
  std::strcpy(favorite, pf);
}

// Переопределение реализации метода Report()
void Classic::Report() const
{
  Cd::Report();
  std::cout << "Favorite: " << favorite << std::endl;
}

// Переопределение перегрузки операции присваивания
Classic& Classic::operator=(const Classic& rcd)
{
  if (this == &rcd)
    return *this;
  else {
    Cd::operator=(rcd);
    std::strcpy(favorite, rcd.favorite);
    return *this;
  }
}