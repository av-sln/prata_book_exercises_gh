// main_16.4.cpp -- использование функций STL

#include <iostream>
#include <vector>
#include <algorithm>

int reduce(long ar[], int n);

int main()
{
  long myAr[] {1, 3, 4, 3, 6, 8, 6, 4, 2, 5, 9, 0, 4, 2, 1};
  int sizeAr = sizeof(myAr) / sizeof(long);
  std::cout << std::endl;
  std::cout << "Array before sorting and conversion:\n";
  for (int i = 0; i < sizeAr; ++i)
    std::cout << myAr[i] << ", ";
  std::cout << "\b\b;\nAll the elements: " << sizeAr << std::endl;
  std::cout << std::endl;
  std::cout << "Array after sorting and conversion:\n";
  sizeAr = reduce(myAr, sizeAr);
  std::cout << "All the elements: " << sizeAr << std::endl;

  return 0;
}

int reduce(long ar[], int n)
{
  std::vector<long> tmp(n);
  for (int i = 0; i < n; ++i)
    tmp[i] = ar[i];
  std::sort(tmp.begin(), tmp.end());
  auto last = std::unique(tmp.begin(), tmp.end());
  tmp.erase(last, tmp.end());
  std::vector<long>::iterator iter;
  for (iter = tmp.begin(); iter != tmp.end(); ++iter)
    std::cout << *iter << ", ";
  std::cout << "\b\b;\n";
  
  return std::size(tmp);
}