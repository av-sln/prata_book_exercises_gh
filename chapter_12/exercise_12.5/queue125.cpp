// queue125.cpp -- реализация методов класса Queue и Customer

#include <cstdlib>
#include "queue125.hpp"

// Класс Customer
// Конструктор
Customer::Customer()
{
  c_arrival_ = c_ptime_ = 0;
}

// Деструктор
Customer::~Customer()
{}

// Время появления клиента
long Customer::cwhen() const
{
  return c_arrival_;
}

// Время обслуживания клиента
int Customer::cptime() const
{
  return c_ptime_;
}

// Установка клиента
void Customer::cset(long when)
{
  c_arrival_ = when;
  c_ptime_ = std::rand() % 3 + 1;
}

// Класс Queue
// Конструктор
Queue::Queue(int qsz) : q_size_(qsz)
{
  q_items_ = 0;
  begin_ = finish_ = nullptr;
}

// Деструктор
Queue::~Queue()
{
  Node *tmp;            // создание временного элемента
  // Пока очередь не пуста
  while (begin_ != nullptr) {
    tmp = begin_;           // сохраняем адрес первого элемента
    begin_ = begin_->next;  // перемещаем вперёд следующий элемент
    delete tmp;             // удаляем первый элемент из очереди
  }
}

// Является ли очередь пустой
bool Queue::isempty() const
{
  return q_items_ == 0;
}

// Является ли очередь заполненной
bool Queue::isfull() const
{
  return q_items_ == q_size_;
}

// Текущее количество элементов в очереди
int Queue::items() const
{
  return q_items_;
}

// Добавление элемента в очередь
bool Queue::additem(const Item &itm)
{
  if (isfull())
    return false;
  Node *add;          // создаём новый узел
  add = new Node;     // выделяем память для нового узла
  add->item = itm;    // присваиваем значение новому элементу очереди
  add->next = nullptr;  // устанавливаем нулевой указатель
  q_items_++;         // увеличиваем счётчик элементов
  if (isempty())
    begin_ = add;     // если очередь пуста, то добавляем элемент в начало
  else
    finish_ = add;    // если нет, то помещаем элемент в конец очереди
  return true;
}

// Удаление элемента из очереди
bool Queue::delitem(Item &itm)
{
  if (isempty())
    return false;
  Node *dlt;            // создание временного элемента
  itm = begin_->item;   // присваивание аргументу значение первого элемента 
  dlt = begin_;         // сохраняем адрес первого элемента
  begin_ = begin_->next;  // перемещаем следующий элемент вперёд
  q_items_--;             // уменьшаем текущее количество элементов
  if (isempty())
    finish_ = nullptr;
  return true;
}