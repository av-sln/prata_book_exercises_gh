// queue125.cpp -- реализация методов класса Queue и Customer

#include <cstdlib>
#include "queue125.hpp"

// Класс Customer
// Конструктор
Customer::Customer()
{
  arrival_ = process_time_ = 0;
}

// Деструктор
Customer::~Customer()
{}

// Время появления клиента
long Customer::when() const
{
  return arrival_;
}

// Время обслуживания клиента
int Customer::ptime() const
{
  return process_time_;
}

// Установка клиента
void Customer::set(long when)
{
  arrival_ = when;
  process_time_ = std::rand() % 3 + 1;
}

// Класс Queue
// Конструктор
Queue::Queue(int qsz) : size_(qsz)
{
  items_ = 0;
  front_ = rear_ = nullptr;
}

// Деструктор
Queue::~Queue()
{
  Node* tmp;                  // создание временного элемента
  // Пока очередь не пуста
  while (front_ != nullptr) {
    tmp = front_;             // сохраняем адрес первого элемента
    front_ = front_->next;    // перемещаем вперёд следующий элемент
    delete tmp;               // удаляем первый элемент из очереди
  }
}

// Является ли очередь пустой
bool Queue::isempty() const
{
  return items_ == 0;
}

// Является ли очередь заполненной
bool Queue::isfull() const
{
  return items_ == size_;
}

// Текущее количество элементов в очереди
int Queue::items() const
{
  return items_;
}

// Добавление элемента в очередь
bool Queue::additem(const Item& itm)
{
  if (isfull())
    return false;
  Node* newNode;            // создаём новый узел
  newNode = new Node;       // выделяем память для нового узла
  newNode->data = itm;      // присваиваем значение новому элементу очереди
  newNode->next = nullptr;  // устанавливаем нулевой указатель
  items_++;               // увеличиваем счётчик элементов
  if (front_ == nullptr) 
    front_ = newNode;       // если очередь пуста, то добавляем элемент в начало
  else
    rear_->next = newNode;  // заносим ссылку на новый узел
  rear_ = newNode;          // новый элемент ставится в конец очереди
  return true;
}

// Удаление элемента из очереди
bool Queue::delitem(Item& itm)
{
  if (isempty())
    return false;
  itm = front_->data; // передаём в метод первый элемент очереди
  items_--;         // уменьшаем счётчик элементов на единицу
  Node* tmp = front_; // сохраняем расположение начального узла
  front_ = front_->next;  // заносим указатель на следующий узел
  delete tmp;             // удаляем старый начальный узел
  if (items_ == 0)
    rear_ = nullptr;      // если список уже пуст обнуляем все указатели
  return true;  
}

// Очистить очередь
void Queue::clear()
{
  Node* tmp;                  // создаём временный узел
  // Цикл выполняется пока очередь не пуста
  while (front_ != nullptr) {
    tmp = front_;             // сохраняем адрес первого элемента
    front_ = front_->next;    // следующий элемент становится первым
    delete tmp;               // удаление предыдущего первого элемента
  }
  rear_ = nullptr;
  items_ = 0;
}