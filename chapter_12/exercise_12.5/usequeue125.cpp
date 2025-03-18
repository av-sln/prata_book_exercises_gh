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
  long turnaways = 0;       // не допущены в полную очередь
  long customers = 0;       // присоединены к очереди
  long served = 0;          // обслужены во время эмуляции
  long sum_line = 0;        // общая длина очереди
  int wait_time = 0;        // время до освобождения банкомата
  long line_wait = 0;       // общее время в очереди
  double average_waiting_time = 0;  // среднее время ожидания
  double min_per_cust = 0;  // среднее время между появлениями клиентов
  

  // Эмуляция запускает один цикл в минуту
  long cyclelimit = MinPerHour * hours;   // количество циклов
  double perhour = 1;

  // Запускаем бесконечный цикл 
  // Остановка по условию
  for (;;) {
    min_per_cust = MinPerHour / perhour;
    Item new_customer;      // новый клиент

    turnaways = 0;       
    customers = 0;       
    served = 0;          
    sum_line = 0;        
    wait_time = 0;        
    line_wait = 0;       

    // Запуск эмуляции
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
      if (newCustomer(min_per_cust)) {    // есть ли подошедший клиент
        // Если очередь полная клиент не допускается
        if (line.isFull())  
          turnaways++;
        // Если в очереди есть место клиент помещается в конец
        else {
          customers++;
          new_customer.cSet(cycle);       // cycle = время прибытия
          line.addItem(new_customer);     // добавление нового клиента в очередь
        }
      }
      // Если банкомат свободен и очередь не пустая
      if (wait_time <= 0 && !line.isEmpty()) {
        line.delItem(new_customer);           // обслуживание следующего клиента
        wait_time = new_customer.cPtime();    // время обслуживания 
        line_wait += cycle - new_customer.cWhen();
        served++;
      }
      if (wait_time > 0)
        wait_time--;
      sum_line += line.items();
    }

    // Вычисляем среднее время ожидания
    average_waiting_time = double(line_wait) / double(served);
    if (average_waiting_time < 1) {
      perhour++;
      continue;
    }
    else if (average_waiting_time == 1) 
      break;
    else {
      perhour--;
      break;
    }      
  }

  // Вывод результатов
  std::cout << std::endl;
  std::cout << "Результаты исследования:\n";
  if (customers > 0) {
    std::cout << "Количество клиентов за час ожидающих одну минуту или менее:\n";
    std::cout << perhour << std::endl;
  }
  else
    std::cout << "Клиентов нет!\n";
  std::cout << "Done!\n";

  return 0;
}

// х = среднее время в минутах между клиентами
// возвращает значение true, если в эту минуту появился клиент
bool newCustomer(double x)
{
  return (std::rand() * x / RAND_MAX < 1);
}