// main_16.7.cpp -- использование функций STL
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> Lotto(int a, int b);

int main()
{
  std::srand(time(NULL));
  int a, b;
  std::cout << std::endl;
  std::cout << "Enter total numbers: ";
  std::cin >> a;
  std::cout << "Enter number of winners numbers: ";
  std::cin >> b;
  std::vector<int> winners;
  std::cout << std::endl;
  winners = Lotto(a, b);
  std::cout << "Winners numbers:\n";
  for (int i = 0; i < b; ++i) 
    std::cout << winners[i] << ", ";
  std::cout << "\b\b;\n";

  return 0;
}

std::vector<int> Lotto(int a, int b)
{
  std::vector<int> card(a);
  std::vector<int> win;
  for (int i = 0; i < a; ++i )
    card[i] = i + 1;

  // Отладочная информация
  std::cout << "Vector card:\n";
  for (int i = 0; i < a; ++i)
    std::cout << card[i] << ", ";
  std::cout << "\b\b;\n";

  std::random_shuffle(card.begin(), card.end());
  win.assign(card.begin(), card.begin() + 6);

  // Отладочная информация
  std::cout << "Vector win:\n";
  for (int i = 0; i < b; ++i)
    std::cout << win[i] << ", ";
  std::cout << "\b\b;\n";

  std::sort(win.begin(), win.end());

  return win;
}