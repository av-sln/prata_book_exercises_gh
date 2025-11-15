// functor.cpp --
// Использование класса functor
// Исходный код из листинга 16.15

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T> // Класс функтора определяет operator()
class TooBig {
private:
   T cutoff;
public:
   TooBig(const T& t) : cutoff(t) {}
   bool operator()(const T& v) {return v > cutoff;}
};

void outint(int n) {std::cout << n << " ";}

int main() {
   using std::list;
   using std::cout;
   using std::endl;

   TooBig<int> f100(100);  // Предельное значение = 100
   int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
   list<int> yadayada(vals, vals + 10);   // Конструктор диапазона
   list<int> etcetera(vals, vals + 10);

   cout << "Original lists:\n";  // Исходные списки
   for_each(yadayada.begin(), yadayada.end(), outint);
   cout << endl;

   for_each(etcetera.begin(), etcetera.end(), outint);
   cout << endl;
   yadayada.remove_if(f100);  // Использование именованного функтора

   etcetera.remove_if(TooBig<int>(200));  // Конструирование функтора

   cout << "Trimmed lists:\n";   // Усечённые списки

   for_each(yadayada.begin(), yadayada.end(), outint);
   cout << endl;

   for_each(etcetera.begin(), etcetera.end(), outint);
   cout << endl;
}