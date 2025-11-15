// main_18.4.cpp
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <ranges>
#include <span>

// Класс функтора
//template<class T>
//class TooBig {
//public:
//   explicit TooBig(const T& cutoff) : m_cutoff{cutoff} {}
//   bool operator()(const T& value) {return value > cutoff;}
//
//private:
//   T m_cutoff;
//};

//void outint(int n) {std::cout << n << " ";}

int main() {
   //TooBig<int> f100{100};
   int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
   // Создаём объект класса span
   std::span<int> valsSpan{vals};
   std::list<int> listOne(valsSpan.begin(), valsSpan.end());
   std::list<int> listTwo(valsSpan.begin(), valsSpan.end());

   std::cout << std::endl;
   
   // Именованное лямбда-выражение
   auto outint = [](int n) -> void {std::cout << n << " ";};

   std::cout << "Original lists:\n";
   std::ranges::for_each(listOne, outint);
   std::cout << std::endl;

   std::ranges::for_each(listTwo, outint);
   std::cout << std::endl;

   int cutOff{100};
   listOne.remove_if([cutOff](const int& value){return value > cutOff;});

   cutOff = 200;
   listTwo.remove_if([cutOff](const int& value){return value > cutOff;});

   std::cout << "Trimed lists:\n";

   std::ranges::for_each(listOne, outint);
   std::cout << std::endl;

   std::ranges::for_each(listTwo, outint);
   std::cout << std::endl;
}