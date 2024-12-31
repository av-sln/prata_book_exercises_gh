// golf.cpp -- реализация функций из golf.h

#include <iostream>
#include <cstring>
#include "golf.h"

// Неитерактивная версия.
void setgolf(golf& g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

// Интерактивная версия.
int setgolf(golf& g)
{
    char temp[Len];
    int flag;
    std::cout << "Enter a name: ";
    std::cin.getline(temp, Len);
    if (!strcmp(temp, "\0"))
        flag = 0;
    else {
        strcpy(g.fullname, temp);
        std::cout << "Enter the handicap: ";
        (std::cin >> g.handicap).get();
        flag = 1;
    }
    return flag;        
}

// Установка нового значения гандикапа
void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

// Отображение содержимого структуры типа golf
void showgolf(const golf& g)
{
    std::cout << "Fullname: " << g.fullname << std::endl;
    std::cout << "Handicap: " << g.handicap << std::endl;
}