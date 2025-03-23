// usequeue125.cpp -- использование класса Queue и Customer

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue125.hpp"

const int MinPerHour = 60;

bool newCustomer(double tm);      // появление нового клиента

int main()
{
  // Подготовка
  std::srand(std::time(0));       // случайная инициализация rand
  std::cout << std::endl;
  std::cout << "Исследование: Bank of Heather банкомат\n";
  std::cout << "Введите максимальный размер очереди: ";
  int qs;
  std::cin >> qs;

  // Создаём две очереди
  Queue line_1(qs);
  Queue line_2(qs);
  std::cout << "Введите количество часов эмуляции: ";
  int hours;
  std::cin >> hours;

  // Используемые переменные
  int served {0};                   // обслужены во время эмуляции
  int wait_time_1 {0};              // время до освобождения банкомата #1
  int wait_time_2 {0};              // время до освобождения банкомата #2 
  long line_wait {0};               // общее время в очереди
  double average_waiting_time {0};  // среднее время ожидания
  double min_per_cust {0};          // среднее время между появлениями клиентов
  
  // Эмуляция запускает один цикл в минуту
  long cyclelimit = MinPerHour * hours;   // количество циклов
  double perhour = 1;
  Item new_customer;

  // Запускаем бесконечный цикл 
  // Остановка по условию
  for (;;) {
    line_1.clear();
    line_2.clear();
    min_per_cust = MinPerHour / perhour;
    average_waiting_time = 0;
    wait_time_1 = 0;
    wait_time_2 = 0;       
    served = 0;          
    line_wait = 0; 
    
    // Запуск эмуляции
    for (long cycle = 0; cycle < cyclelimit; cycle++) {
      if (newCustomer(min_per_cust)) {          // есть ли подошедший клиент
        if (line_1.items() < line_2.items()) {
          new_customer.set(cycle);              // cycle - время прибытия
          line_1.additem(new_customer);         // добавляем нового клиента 
        }
        else {
          new_customer.set(cycle);
          line_2.additem(new_customer);
        }
      }
    
      // Если банкомат #1 свободен и очередь не пустая
      // обслуживается первый в очереди клиент
      if (wait_time_1 <= 0 && !line_1.isempty()) {
        line_1.delitem(new_customer);         
        // Время обслуживания 
        wait_time_1 = new_customer.ptime();
        // Общее время ожидания в очереди 
        line_wait += cycle - new_customer.when();
        served++;
      }
      if (wait_time_1 > 0)
        wait_time_1--;

      // Если банкомат #2 свободен и чередь не пустая
      // обслуживается первый в очереди клиент
      if (wait_time_2 <= 0 && !line_2.isempty()) {
        line_2.delitem(new_customer);
        wait_time_2 = new_customer.ptime();
        line_wait += cycle - new_customer.when();
        served++;
      }
      if (wait_time_2 > 0)
        wait_time_2--;
    }

    // Вычисляем среднее время ожидания
    average_waiting_time = (double)line_wait / served;
    if (average_waiting_time < 1) {
      std::cout << "#" << perhour << ": " << average_waiting_time
                << std::endl;
      perhour++;

      // res = average_waiting_time;
      continue;
    }
    else if (average_waiting_time == 1) {
      std::cout << "#" << perhour << ": " << average_waiting_time
                << std::endl;
       // res = average_waiting_time; 
      break;
    }
    else {
      std::cout << "#" << perhour << ": " << average_waiting_time
                << std::endl;
      perhour--;
      break;
    } 
  }

  // Вывод результатов
  std::cout << std::endl;
  std::cout << "Результаты исследования:\n";
  std::cout << "Количество клиентов за час ожидающих одну минуту или менее:\n";
  std::cout << perhour << std::endl;
  // std::cout << "Среднее время ожидания клиента: " << res << " минут.\n";
  std::cout << "Done!\n";

  return 0;
}

// х = среднее время в минутах между клиентами
// возвращает значение true, если в эту минуту появился клиент
bool newCustomer(double x)
{
  return (std::rand() * x / RAND_MAX < 1);
}