// usequeue125.cpp -- использование класса Queue и Customer

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue126.hpp"

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
  // Создаём две очереди
  Queue line_1(qs);
  Queue line_2(qs);
  std::cout << "Введите количество часов эмуляции: ";
  int hours;
  std::cin >> hours;

  // Используемые переменные
  long served = 0;                  // обслужены во время эмуляции
  int wait_time_1 = 0;              // время до освобождения банкомата #1
  int wait_time_2 = 0;              // время до освобождения банкомата #2
  long line_wait = 0;               // общее время в очереди
  double average_waiting_time = 0;  // среднее время ожидания
  double min_per_cust = 0;          // среднее время между появлениями клиентов
  

  // Эмуляция запускает один цикл в минуту
  long cyclelimit = MinPerHour * hours;   // количество циклов
  double perhour = 1;

  // Запускаем бесконечный цикл 
  // Остановка по условию
  for (;;) {
    min_per_cust = MinPerHour / perhour;
    Item new_customer;      // новый клиент
           
    served = 0;          
    line_wait = 0;       

    // Запуск эмуляции
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
      if (newCustomer(min_per_cust)) {    // есть ли подошедший клиент
        new_customer.cSet(cycle);         // cycle - время прибытия
        // Выбираем короткую очередь
        if (line_1.items() < line_2.items()) 
          line_1.addItem(new_customer); // добавляем нового клиента в #1
        else
          line_2.addItem(new_customer); // добавляем нового клиента в #2          
      }
    
      // Если банкомат #1 свободен и очередь не пустая
      if (wait_time_1 <= 0 && !line_1.isEmpty()) {
        line_1.delItem(new_customer);           // обслуживание следующего клиента
        wait_time_1 = new_customer.cPtime();    // время обслуживания 
        line_wait += cycle - new_customer.cWhen();
        served++;
      }
      if (wait_time_1 > 0)
        wait_time_1--;
      
      // Если банкомат #2 свободен и очередь не пустая
      if (wait_time_2 <= 0 && !line_2.isEmpty()) {
        line_2.delItem(new_customer);     // обслуживание следующего клиента
        wait_time_2 = new_customer.cPtime();  // время обслуживания
        line_wait += cycle - new_customer.cWhen();
        served++;
      }
      if (wait_time_2 > 0)
        wait_time_2--;
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
  std::cout << "Количество клиентов за час ожидающих одну минуту или менее:\n";
  std::cout << perhour << std::endl;
  std::cout << "Done!\n";

  return 0;
}

// х = среднее время в минутах между клиентами
// возвращает значение true, если в эту минуту появился клиент
bool newCustomer(double x)
{
  return (std::rand() * x / RAND_MAX < 1);
}