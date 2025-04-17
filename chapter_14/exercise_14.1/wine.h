// wine.h -- объявление класса Wine

#ifndef WINE_H_
#define WINE_H_
#include <string>
#include <iostream>
#include <valarray>

template <typename T1, class T2>
class Pair {
private:
  T1 first_;
  T2 second_;
  
public:
  // Конструктор с аргументами
  Pair(const T1& r_fval, const T2& r_sval)
    : first_(r_fval), second_(r_sval) {}
  // Констуктор по умолчанию
  Pair() {}
  // Присвоить значение первому элементу
  T1& first();
  // Присвоить значение второму элементу
  T2& second();
  // Вернуть первое значение
  T1 first() const { return first_; }
  // Вернуть второе значение
  T2 second() const { return second_; }
};

typedef std::valarray<int> array_int;
typedef Pair<array_int, array_int> pair_array;

class Wine {
private:
  std::string label_;
  pair_array data_;
  int years_;

public:
  // Конструктор по умолчанию
  Wine(std::string lbl = "No label", int yrs = 0);
  // Конструктор #1  
  Wine(const char* p_lbl, int y, const int yr[], const int bot[]);
  // Конструктор #2
  Wine(const char* p_lbl, int y);
  void GetBottles();    // вводит год урожая и количество бутылок
  const std::string& Label() const;     // возвращает название вина
  int sum() const;        // возвращает общее количество бутылок
  void Show() const;  // вывод всех данных
  ~Wine() {}
};

#endif // wine.h