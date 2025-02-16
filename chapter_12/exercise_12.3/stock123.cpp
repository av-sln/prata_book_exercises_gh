// stock123.cpp -- реализация методов класса Stock123

#include <iostream>
#include <cstring>
#include "stock123.hpp"

// Конструкторы/деструктор
// Корструктор по умолчанию
Stock123::Stock123()
{
  company_ = new char[1];
  company_ = nullptr;
  shares_ = 0;
  priceShare_ = 0.0;
  set_tot();
}

// Конструктор с аргументами
Stock123::Stock123(const char *pnm, int sh, double pr)
{
  company_ = new char[std::strlen(pnm) + 1];
  std::strcpy(company_, pnm);
  if (sh < 0) {
    std::cout << "Number of shares can't be negative; \n"
              << company_ << " shares set to 0.\n";
    shares_ = 0;
  }
  else 
    shares_ = sh;
  priceShare_ = pr;
  set_tot();
}

// Деструктор
Stock123::~Stock123()
{
  delete [] company_;
}

// Методы
// Покупка пакета акций
void Stock123::buyshares(int sh, double pr)
{
  if (sh < 0)
    std::cout << "Number of shares purchased can't be negative!\n"
              << "Transaction is aborted!\n";
  else {
    shares_ += sh;
    priceShare_ = pr;
    set_tot();
  }  
}

// Продажа пакета акций
void Stock123::sellshares(int sh, double pr)
{
  if (sh < 0)
    std::cout << "Number of shares sold can't be negative!\n"
              << "Transaction is aborted!\n";
  else if (sh > shares_)
    std::cout << "You can't sell more than you have!\n"
              << "Transaction is aborted!\n";
  else {
    shares_ -= sh;
    priceShare_ = pr;
    set_tot();
  }
}

// Изменение цены акций
void Stock123::updateprice(double pr)
{
  priceShare_ = pr;
  set_tot();
}

// Определение топового пакета
const Stock123 & Stock123::topval(const Stock123 &rsh2) const
{
  if (totalCost_ > rsh2.totalCost_)
    return *this;
  else
    return rsh2;
}

// Друзья
// Оператор вывода
std::ostream & operator<<(std::ostream &rout, const Stock123 &rsh)
{
  // Установка формата в #.###
  std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed,
    std::ios_base::floatfield);
  std::streamsize prec = std::cout.precision(3);
  rout << "Company name       : " << rsh.company_ << std::endl
       << "Shares             : " << rsh.shares_ << std::endl
       << "Current share price: $" << rsh.priceShare_ << std::endl;
  // Установка формата #.##
  std::cout.precision(2);
  std::cout << "Total Worth        : $" << rsh.totalCost_ << std::endl;
  // Восстановление исходного формата
  std::cout.setf(orig, std::ios_base::floatfield);
  std::cout.precision(prec);
  return rout;        
}