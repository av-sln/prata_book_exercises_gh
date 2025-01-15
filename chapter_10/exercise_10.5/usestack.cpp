// usestack.cpp -- использование класса Strack и его методов

#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
  double tot_pay = 0.0;     // промежуточная сумма всех платежей
  Stack my_customers;       // создание пустого списка заказчиков
  char ch;                  // символ выбора
  customer new_customer;    // создание структуры

  // А - добавление заказчика
  // D - исключение заказчика
  // Q - завершение

  std::cout << std::endl;
  std::cout << "Please enter A to add a customer," << std::endl
            << "D to exclude a customer," << std::endl
            << "Q to quit." << std::endl;
  while ((std::cin >> ch).get() && toupper(ch) != 'Q') {
    if (!isalpha(ch)) {
      std::cout << "Please enter one of these symbols A, E or Q: ";
      continue;
    }
    switch(ch) {
      // Добавление нового заказчика
      case 'A':   
      case 'a': 
        std::cout << std::endl;
        if (my_customers.isfull())
          std::cout << "Stack is already full." << std::endl
                    << "The addition operation cannot be performed."
                    << std::endl;
        else {
          std::cout << "Enter new customer's fullname: ";
          std::cin.getline(new_customer.fullname, StrSize);
          std::cout << "Enter new customer's payment: ";
          std::cin >> new_customer.payment;
          std::cin.get();
          my_customers.push(new_customer);
          std::cout << "Customer " << new_customer.fullname 
                    << " was added." << std::endl; 
        }
        break;
      // Исключение заказчика
      case 'D':
      case 'd':
        std::cout << std::endl;
        if (my_customers.isempty())
          std::cout << "Stack is already empty." << std::endl
                    << "The exclusion operation cannot be performed."
                    << std::endl;
        else {
          my_customers.pop(new_customer);
          std::cout << "Customer " << new_customer.fullname 
                    << " was excluded." << std::endl;
          tot_pay += new_customer.payment;
          std::cout << "Total amount of the payment: " << tot_pay
                    << std::endl;          
          }
          break;
        }
    std::cout << std::endl;
    std::cout << "Please enter A to add a customer, " << std::endl
              << "D to exclude a customer, " << std::endl
              << "Q to quit." << std::endl;
  } 
  std::cout << std::endl;
  std::cout << "Bye." << std::endl;
  return 0;
}