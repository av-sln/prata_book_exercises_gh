// usestone116.cpp -- использование класса Stonewt

#include <iostream>
#include <cctype>
#include "stone116.hpp"

const int ArSz = 6;

Stonewt MinElement(const Stonewt (&rar)[], int n);
Stonewt MaxElement(const Stonewt (&rar)[], int n);
int Count(const Stonewt& ra, const Stonewt (&rar)[], int n);

int main()
{
  char ch;  
  int tmp_stn;
  double tmp_pds; 
                  
  Stonewt weights[ArSz] {
    Stonewt(140.98),
    Stonewt(7),
    Stonewt(4, 23.0)
  };

  Stonewt Standard(11);         // эталонный объект 11 стоунов

  // Вывод полученных значений массива
  std::cout << std::endl;
  std::cout << "Displaying object's array:\n";
  for (int i = 0; i < ArSz; i++)
    std::cout << weights[i] << std::endl;

  std::cout << std::endl;
  for (int i = 3; i < ArSz; i++) {
    std::cout << "Enter S - weight in stone or P - weight in pounds: ";
    while (!(std::cin >> ch).get() && (toupper(ch) != 'S' || toupper(ch) != 'P')) {
      std::cout << "Enter S or P: ";
      continue;
    }
    switch (ch) {
      case 's':
      case 'S':
        std::cout << "Enter the weight in stones: ";
        std::cin >> tmp_stn;
        std::cout << "and punds: ";
        std::cin >> tmp_pds;
        weights[i] = Stonewt(tmp_stn, tmp_pds);
        break;
      case 'p':
      case 'P':
        std::cout << "Enter the weight in pounds: ";
        std::cin >> tmp_pds;
        weights[i] = Stonewt(tmp_pds);
    }
  }

  // Вывод полученных результатов
  std::cout << std::endl;
  for (int i = 0; i < ArSz; i++)
    std::cout << weights[i] << std::endl;

  // Вывод окончательных результатов
  std::cout << std::endl;
  std::cout << "Displaying of final results:\n";
  std::cout << "Smallest element = " << MinElement(weights, ArSz) << std::endl;
  std::cout << "Biggest element  = " << MaxElement(weights, ArSz) << std::endl;
  std::cout << "The quantity of elements which >= 11 stones = " 
            << Count(Standard, weights, ArSz) << std::endl;  

  return 0;
}

Stonewt MinElement(const Stonewt (&rar)[], int n)
{
  Stonewt min = rar[0];
  for (int i = 0; i < ArSz; i++)
    if (min > rar[i])
      min = rar[i];
  
  return min;
}

Stonewt MaxElement(const Stonewt (&rar)[], int n)
{
  Stonewt max = rar[0];
  for (int i = 0; i < ArSz; i++)
    if (max < rar[i])
      max = rar[i];

  return max;
}

int Count(const Stonewt& ra, const Stonewt (&rar)[], int n)
{
  int counter = 0;
  for (int i = 0; i < ArSz; i++)
    if (ra <= rar[i])
      counter++;
  
  return counter;
}