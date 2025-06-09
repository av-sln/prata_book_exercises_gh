// main_16.5.cpp -- использование функций STL

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <class T>
int reduce(T ar[], int n);

int main()
{
  long myNumArray[] {1, 3, 4, 3, 6, 8, 6, 4, 2, 5, 9, 0, 4, 2, 1};
  auto sizeAr = std::end(myNumArray) - std::begin(myNumArray);
  std::cout << "Numeric array berfore sorting and conversion:\n";
  for (int i = 0; i < sizeAr; ++i)
    std::cout << myNumArray[i] << ", ";
  std::cout << "\b\b;";
  std::cout << "\nAll the elements: " << sizeAr << std::endl;
  std::cout << std::endl;
  std::cout << "Numeric array after sorting and conversion:\n";
  sizeAr = reduce(myNumArray, sizeAr);
  std::cout << "All the elements: " << sizeAr << std::endl;
  std::cout << std::endl;

  std::string myStrArray[] {
    "peace", "earth", "cup", "pencil", "cup", "bottle", "peace", "cup",
    "earth", "pencil", "forty", "house", "forty", "building", "business",
    "mother", "house", "tree"
  };
  sizeAr = std::end(myStrArray) - std::begin(myStrArray);
  std::cout << "String array before sorting and conversion:\n";
  for (int i = 0; i < sizeAr; ++i)
    std::cout << myStrArray[i] << ", ";
  std::cout << "\b\b;";
  std::cout << "\nAll the elements: " << sizeAr << std::endl;
  std::cout << std::endl;
  std::cout << "String array after sorting and conversion:\n";
  sizeAr = reduce(myStrArray, sizeAr);
  std::cout << "All the elements: " << sizeAr << std::endl;
  
  return 0;
}

template <class T>
int reduce(T ar[], int n)
{
  std::vector<T> tmp(n);
  for (int i = 0; i < n; ++i)
    tmp[i] = ar[i];
  std::sort(tmp.begin(), tmp.end());
  auto last = std::unique(tmp.begin(), tmp.end());
  tmp.erase(last, tmp.end());
  typename std::vector<T>::iterator iter;
  for (iter = tmp.begin(); iter != tmp.end(); ++iter)
    std::cout << *iter << ", ";
  std::cout << "\b\b;\n";

  return std::size(tmp);
}