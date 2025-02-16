// stock123.hpp -- заголовочный файл класса Stock123

#ifndef STOCK123_HPP_
#define STOCK123_HPP_
#include <iostream>

class Stock123
{
private:
  char *company_;
  int shares_;
  double priceShare_;
  double totalCost_;
  void set_tot() 
  { totalCost_ = shares_ * priceShare_; }

public:
  // Конструкторы/деструктор
  // Конструктор по умолчанию
  Stock123();
  // Конструктор с аргументами
  Stock123(const char *pnm, int sh, double pr);
  // Деструктор
  ~Stock123();

  // Методы
  // Покупка пакета акций
  void buyshares(int sh, double pr);
  // Продажа пакета акций
  void sellshares(int sh, double pr);
  // Изменение цены акций
  void updateprice(double pr);
  // Определение топового пакета
  const Stock123 & topval(const Stock123 &rsh2) const;

  // Друзья
  // Оператор вывода
  friend std::ostream & operator<<(std::ostream &rout, const Stock123 & rsh);
};

#endif