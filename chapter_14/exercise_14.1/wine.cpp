// wine.cpp -- определение методов классов Pair и Wine

#include "wine.h"

// Методы класса Pair
template<typename T1, typename T2>
T1& Pair<T1, T2>::first()
{
  return first_;
}

template<typename T1, typename T2>
T2& Pair<T1, T2>::second()
{
  return second_;
}

// Методы класса Wine

// Конструктор по умолчанию
Wine::Wine(std::string lbl, int yrs)
  : label_(lbl), years_(yrs)
{
  data_.first().resize(years_);
  data_.first().resize(years_);
}

// Конструктор #1
Wine::Wine(const char* plbl, int y, const int yr[], const int bot[])
  : label_(plbl), years_(y)
{
  data_.first().resize(years_);
  data_.second().resize(years_);
  for (int i = 0; i < years_; ++i) {
    data_.first()[i] = yr[i];
    data_.second()[i] = bot[i];
  }
}

// Конструктор #2
Wine::Wine(const char* plbl, int y)
  : label_(plbl), years_(y)
{
  data_.first().resize(years_);
  data_.second().resize(years_);
}

// Вводит год урожая и количество бутылок
void Wine::GetBottles()
{
  std::cout << "Enter " << Label() << " data for " << years_ << " year(s):\n";
  for (int i = 0; i < years_; ++i) {
    std::cout << "Enter year: ";
    std::cin >> data_.first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> data_.second()[i];
  }
}

// Возвращает название вина
const std::string& Wine::Label() const
{
  return label_;
}

// Возвращает общее количество бутылок
int Wine::sum() const
{
  return data_.second().sum();
}

// Вывод всех данных
void Wine::Show() const
{
  std::cout << "Wine: " << Label() << std::endl;
  std::cout << "\tYear\tBottles\n";
  for (int i = 0; i < years_; ++i) {
    std::cout << "\t" << data_.first()[i] << "\t" << data_.second()[i]
              << std::endl;
  }
}

