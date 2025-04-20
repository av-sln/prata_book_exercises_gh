// wine2.cpp -- реализация методов класса Wine2

#include "wine2.h"

// Конструктор по умоолчанию
Wine::Wine()
  : std::string("No label"), PairArray(ArrayInt(0), ArrayInt(0)) 
{
  years_ = 0;
}

// Конструктор #1
Wine::Wine(const char* p_lbl, int y, const int yr[], const int btl[])
  : std::string(p_lbl), PairArray(ArrayInt(y), ArrayInt(y))
{
  years_ = y;
  for (int i = 0; i < years_; ++i) {
    PairArray::setfirst()[i] = yr[i];
    PairArray::setsecond()[i] = btl[i];
  }
}

// Конструктор #2
Wine::Wine(const char* p_lbl, int y)
  : std::string(p_lbl), PairArray(ArrayInt(y), ArrayInt(y)) 
{
  years_ = y;
}

// Вводит год урожая и количество бутылок
void Wine::GetBottles()
{
  std::cout << "Enter " << Label() << " data for "
            << years_ << " year(s):\n";
  for (int i = 0; i < years_; ++i) {
    std::cout << "Enter year: ";
    std::cin >> PairArray::setfirst()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> PairArray::setsecond()[i];
  }
}

// Возвращает название вина
const std::string& Wine::Label() const
{
  return (const std::string&)*this;
}

// Возвращает общее количество бутылок
int Wine::Sum() const
{
  return PairArray::second().sum();
}

// Вывод всех данных
void Wine::Show() const
{
  std::cout << "Wine: " << Label() << std::endl;
  std::cout << "\tYear\tBottles\n";
  for (int i = 0; i < years_; ++i) 
    std::cout << "\t" << PairArray::first()[i]
              << "\t" << PairArray::second()[i]
              << std::endl;
}
