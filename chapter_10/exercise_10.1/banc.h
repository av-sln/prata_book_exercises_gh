// banc.h -- 

#ifndef BANC_H_
#define BANC_H_

#include <string>

class BancAccount
{
private:
  std::string client_name_;           // имя владельца счёта
  std::string account_number_;        // номер счёта
  double balance_;                     // баланс счёта

public:
  // Конструктор по умолчанию
  // используется для сосзлания объектов без аргументов
  BancAccount();

  // Создание банковского счёта и его инициализация
  // Используем конструктор с аргументами
  BancAccount(const std::string& client_name, 
    const std::string& account_number, double balance = 0.0);

  // Деструктор
  ~BancAccount();

  // Отображение данных по счёту
  void ShowAccountData() const;

  // Добавление на счёт суммы денег переданной в аргументе
  void Deposit(double cash);

  // Снятие суммы денег переданной в аргументе
  void Withdraw(double cash);
};

#endif