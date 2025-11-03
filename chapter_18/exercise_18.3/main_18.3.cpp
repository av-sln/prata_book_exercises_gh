// main_18.3.cpp
#include <iostream>

// Определение для 0 параметров
long double sum_values() {
   return 0;
}

// Определение для 1 параметра
template<typename T>
long double sum_values(const T& value) {
   return value;
}

// Определение для 2-х и более параметров
template<typename T, typename...Args>
long double sum_values(const T& value, const Args&...args) {
   long double totalSum{0};
   totalSum += value + sum_values(args...);
   return totalSum;
}

int main() {
   int a{4}, b{7};
   double c{4.5}, d{5.5};
   std::cout << std::endl;
   std::cout << sum_values(a, b, c, d) << std::endl;
}