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

  // Создаём очередь
  Queue line(qs);
  std::cout << "Введите количество часов эмуляции: ";
  int hours;
  std::cin >> hours;

  // Используемые переменные
  int served {0};                  // обслужены во время эмуляции
  int wait_time {0};                // время до освобождения банкомата 
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
    line.clear();
    min_per_cust = MinPerHour / perhour;
    average_waiting_time = 0;
    wait_time = 0;       
    served = 0;          
    line_wait = 0; 
    
    // Запуск эмуляции
    for (long cycle = 0; cycle < cyclelimit; cycle++) {
      if (newCustomer(min_per_cust)) {      // есть ли подошедший клиент
        if (!line.isfull()) {
          new_customer.set(cycle);           // cycle - время прибытия
          line.additem(new_customer);         // добавляем нового клиента
        }
      }
    
      // Если банкомат свободен и очередь не пустая
      if (wait_time <= 0 && !line.isempty()) {
        line.delitem(new_customer);           // обслуживание следующего клиента
        wait_time = new_customer.ptime();    // время обслуживания 
        line_wait += cycle - new_customer.when();
        served++;
      }
      if (wait_time > 0)
        wait_time--;
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