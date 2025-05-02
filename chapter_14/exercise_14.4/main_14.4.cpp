// main_14.4.cpp -- использование абстрактного базового класса Person

#include <iostream>
#include <cstring>
#include "baddude.h"

const int SIZE = 5;

int main()
{
  Person* lolas[SIZE];          // создаём массив указателей на базовый класс
  int ct;
  char choice;
  
  for (ct = 0; ct < SIZE; ++ct) {
    std::cout << "\nEnter the person's category:\n"
              << "g: gunslinger           p: pockerplayer\n"
              << "b: baddude              q: quit\n";
    std::cin >> choice;
    while (!std::strchr("gpbq", choice)) {
      std::cout << "Please enter a g, p, b or q: ";
      std::cin >> choice;
    }
    if (choice == 'q')
      break;
    switch(choice) {
      case 'g': lolas[ct] = new Gunslinger;
                break;
      case 'p': lolas[ct] = new PockerPlayer;
                break;
      case 'b': lolas[ct] = new BadDude;
                break;
    }
    std::cin.get();
    lolas[ct]->set();
  }
  std::cout << std::endl;
  std::cout << "Here are your persons:\n";
  for (int i = 0; i < ct; ++i) {
    std::cout << std::endl;
    lolas[i]->Show();
  }
  for (int i = 0; i < ct; ++i)
    delete lolas[i];
  std::cout << "Bye!\n";

  return 0;
}