// golf.cpp -- реализация методов Golf

#include <iostream>
#include <cstring>
#include "golf.h"

// Конструктор класса Golf
Golf::Golf(const char* fullname, int handicap)
{
  strcpy(fullname_, fullname);
  handicap_ = handicap;
}

// Деструктор
Golf::~Golf()
{}

// Установка нового значения гандикапа
void Golf::HandiCap(int handicap)
{
  handicap_ = handicap;
}

// Отображение данных игрока
void Golf::ShowGolf() const 
{
  std::cout << "Player's name    : " << fullname_ << std::endl;
  std::cout << "Player's handicap: " << handicap_ << std::endl;
}

// Интерактивная версия метода SetGolf
int Golf::SetGolf()
{
  int flag = 0;
  int handicap = 0;
  char tmp_name[LEN];
  std::cout << std::endl;
  std::cout << "Enter the Player's name: ";
  std::cin.getline(tmp_name, LEN);
  if (strcmp(tmp_name,"\0" )) {
    std::cout << "Enter the Player's handicap: ";
    (std::cin >> handicap).get();
    Golf tmp_obj(tmp_name, handicap);
    *this = tmp_obj;
    flag = 1;
  }
  else
    flag = 0;
  
  return flag;
}