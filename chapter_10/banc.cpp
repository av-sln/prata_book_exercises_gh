// bancacc.cpp -- определение методов класса BankAccount

#include <iostream>
#include "banc.h"

// Конструктор по умолочанию
BancAccount::BancAccount()
{
  client_name_ = "Nobody";
  account_number_ = "Nothing";
  balance_ = 0.0;
}

// Создание банковского счёта и его инициализация
BancAccount::BancAccount(const std::string& client_name,
  const std::string& account_number, double balance)
{
  client_name_ = client_name;
  account_number_ = account_number;
  balance_ = balance;
}

// Деструктор класса
BancAccount::~BancAccount()
{}

// Отображение данных по счёту
void BancAccount::ShowAccountData() const
{
  // std::cout << std::endl;
  std::cout << "Client information:" << std::endl;
  std::cout << "Full name     : " << client_name_ << std::endl;
  std::cout << "Account number: " << account_number_ << std::endl;
  std::cout << "Balance       : " << balance_ << std::endl;
}

// Добавление на счёт суммы денег переданной в аргументе
void BancAccount::Deposit(double cash)
{
  if (cash < 0)
    std::cout << "The amount of money cannot be negative. "
              << "Operation is aborted!" << std::endl;
  else
    balance_ += cash;
}

// Снятие суммы денег переданной в аргументе
void BancAccount::Withdraw(double cash)
{
  if (cash < 0)
    std::cout << "The amount of money cannot be negative."
              << "Operation is aborted!" << std::endl;
  else if (cash > balance_)
    std::cout << "You cannot withdraw more money than you have."
              << "Operation is aborted!" << std::endl;
  else 
    balance_ -= cash;
}