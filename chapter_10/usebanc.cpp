// usebanc.cpp -- файл использования методов класса BancAccount

#include <iostream>
#include "banc.h"

int main()
{
  // Создание объекта по умолчанию
  BancAccount noname_account;
  
  // Создание инициализируемого объекта
  BancAccount ivan_petrov ("Ivan Petrov", "ACC875488", 678);

  // Отображение объекта по умолчанию
  std::cout << std::endl;
  std::cout << "Displaying default object:" << std::endl;
  noname_account.ShowAccountData();

  // Отображение инициализированного объекта
  std::cout << std::endl;
  std::cout << "Displaying an initialized object:" << std::endl;
  ivan_petrov.ShowAccountData();

  // Внести депозит
  ivan_petrov.Deposit(54.09);
  std::cout << std::endl;
  std::cout << "Balance after depositing:" << std::endl;
  ivan_petrov.ShowAccountData();

  // Снять сумму с депозита
  ivan_petrov.Withdraw(70);
  std::cout << std::endl;
  std::cout << "Balance after withdrawing:" << std::endl;
  ivan_petrov.ShowAccountData();

  // Попытка сломать
  ivan_petrov.Deposit(-200);
  ivan_petrov.Withdraw(90000);
  ivan_petrov.Withdraw(-500);
  std::cout << std::endl;
  std::cout << "Current balance:" << std::endl;
  ivan_petrov.ShowAccountData();

  return 0; 
}