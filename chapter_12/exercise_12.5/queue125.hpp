// queue125.hpp -- загловочный файл класса Queue и Customer

#ifndef QUEUE125_HPP_
#define QUEUE125_HPP_


//Класс Customer
class Customer
{
private:
  long arrival_;                   // время прибытия клиента
  int process_time_;               // время обслуживания клиента

public:
  // Конструктор
  Customer();
  // Деструктор
  ~Customer();
  // Установка клиента
  void set(long when);
  // Время прибытия клиента
  long when() const;
  // Время обслуживания клиента
  int ptime() const; 
};

typedef Customer Item;


// Класс Queue
class Queue
{
private:
  struct Node
  {
    Item data;    // элемент очереди 
    Node* next;   // адрес следующего элемента
  };
  enum {QSZ = 10};   // размер очереди по умолчанию
  int items_;        // текущее количество элементов в очереди
  int size_;         // размер очереди
  Node* front_;      // указатель на начало очереди
  Node* rear_;       // указатель на конец очереди
  
  // Упреждающие объявления для предотвращения открытого копирования
  Queue(const Queue& q) : size_(0) {}
  Queue & operator=(const Queue& q) { return *this; }

public:
// Конструктор
Queue(int qsz = QSZ);
// Деструктор
~Queue();
// Является ли очередь пустой
bool isempty() const;
// Является ли очередь заполненной
bool isfull() const;
// Добавление элемента в очередь
bool additem(const Item& itm);
// Удаление элемента из очереди
bool delitem(Item& itm);
int items() const;
// Очистить очередь
void clear();
};

#endif