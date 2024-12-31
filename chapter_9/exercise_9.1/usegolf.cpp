// usegolf.cpp -- реализация всех средств функций golf.h

#include <iostream>
#include "golf.h"

const int ArSize = 5;

int main()
{
    // Использование неинтерактивной функции
    std::cout << std::endl;
    std::cout << "Using non-interactive function:" << std::endl;
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);

    // Использование интерактивной функции
    std::cout << std::endl;
    std::cout << "Using interactive function:" << std::endl;
    int counter = 0;
    golf players[ArSize];
    for (int i = 0; i < ArSize; i++) {
        std::cout << "Player #" << i + 1 << std::endl;
        int check = setgolf(players[i]);
        if (check == 0)
            break;
        else 
            counter += 1;
    }
    // Показ массива структур
    std::cout << std::endl;
    for (int i = 0; i < counter; i++) {
        std::cout << "Player #" << i + 1 << std::endl;
        showgolf(players[i]);
    }

    // Изменение значение гандикапа
    std::cout << std::endl;
    std::cout << "Change a handicap:" << std::endl;
    int hgp = 55;
    handicap(ann, hgp);
    showgolf(ann);
    return 0;
}