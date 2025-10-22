// main_18.1.cpp

#include <iostream>
#include <iterator>
#include <initializer_list>

template<typename T>
T average_list(std::initializer_list<T> value) {
   T sum{0};
   auto count{value.end() - value.begin()};
   for (auto iter{value.begin()}; iter != value.end(); ++iter) {
      sum += *iter;
   }
   return sum / count;
}

int main() {
   // Список double выведен из содержимого списка
   auto q = average_list({15.4, 10.7, 9.0});
   std::cout << q << std::endl;

   // Список int выведен из содержимого списка
   std::cout << average_list({20, 30, 19, 17, 45, 38}) << std::endl;

   // Принудительное использование списка double
   auto ad = average_list<double>({'A', 70, 65.33});
   std::cout << ad << std::endl;
}