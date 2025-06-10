// main_16.9.cpp -- использование STL
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <cstdlib>

void setArray(std::vector<int>& rvec, int a);
void show(const int& rx);

int main()
{
  std::srand(time(NULL));
  // Ввод размерности массивов
  int arSize;
  std::cout << std::endl;
  std::cout << "Enter the size of arrays: ";
  std::cin >> arSize;

  // Создание массивов
  std::vector<int> vi0(arSize);
  std::vector<int> vi(arSize);
  std::list<int> li(arSize);

  // Инициализация вектора случайными значениями
  setArray(vi0, arSize);
  vi = vi0;
  std::copy(begin(vi), end(vi), begin(li));

  // Отладочная информация
  //std::cout << "Vector:\n";
  //for (auto x : vi) show(x);
  //std::cout << std::endl;
  //std::cout << "List:\n";
  //for (auto x : li) show(x);
  //std::cout << std::endl;

  // Сортировка вектора
  clock_t start = clock();
  std::sort(begin(vi), end(vi));
  clock_t stop = clock();
  std::cout << "Time of vector sorting: " 
            << (double)(stop - start) / CLOCKS_PER_SEC
            << std::endl;

  // Cортировка списка
  start = clock();
  li.sort();
  stop = clock();
  std::cout << "Time of list sorting: "
            << (double)(stop - start) / CLOCKS_PER_SEC
            << std::endl;

  // Смешанная операция сортировки и копирования
  std::copy(begin(vi0), end(vi0), begin(li));
  start = clock();
  std::copy(begin(li), end(li), begin(vi));
  std::sort(begin(vi), end(vi));
  std::copy(begin(vi), end(vi), begin(li));
  stop = clock();
  std::cout << "Mixed sorting and copying operation: "
            << (double)(stop - start) / CLOCKS_PER_SEC
            << std::endl;
  

  return 0;
}

void setArray(std::vector<int>& rvec, int a)
{
  for (int i = 0; i < a; ++i)
    rvec[i] = std::rand() % 100; 
}

void show(const int& rx)
{
  std::cout << rx << " ";
}