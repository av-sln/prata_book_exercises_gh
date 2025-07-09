// main_16.7.cpp -- использование функций STL
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

std::vector<int> Lotto(int a, int b);

int main()
{
  int a, b;
  std::cout << std::endl;
  std::cout << "Enter total numbers: ";
  std::cin >> a;
  std::cout << "Enter number of winners numbers: ";
  std::cin >> b;
  std::vector<int> winners;
  std::cout << std::endl;
  winners = Lotto(a, b);
  std::ostream_iterator<int> output{std::cout, " "};
  std::cout << "Winners numbers: ";
  std::ranges::copy(winners, output);
  std::cout << std::endl;

  return 0;
}

std::vector<int> Lotto(int a, int b)
{
  std::vector<int> card(a);
  for (int i = 0; i < a; ++i )
    card[i] = i + 1;

  // Отладочная информация
  std::cout << "Vector card:\n";
  for (int i = 0; i < a; ++i)
    std::cout << card[i] << ", ";
  std::cout << "\b\b;\n";

  // Инициализируем генератор случайных чисел для
  // перемешивания элементов вектора card
  std::default_random_engine randomEngine{std::random_device{}()};
  // Перемешиваем элементы вектора в случайном порядке
  std::ranges::shuffle(card, randomEngine);  
  card.assign(card.begin(), card.begin() + 6);

  // Отладочная информация
  std::cout << "Vector win:\n";
  for (int i = 0; i < b; ++i)
    std::cout << card[i] << ", ";
  std::cout << "\b\b;\n";

  std::sort(card.begin(), card.end());

  return card;
}
