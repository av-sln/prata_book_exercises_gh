// queue125.cpp -- реализация методов класса Queue и Customer

#include <cstdlib>
#include "queue126.hpp"

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
long Customer::cWhen() const
{
  return c_arrival_;
}

// Время обслуживания клиента
int Customer::cPtime() const
{
  return c_ptime_;
}

// Установка клиента
void Customer::cSet(long when)
{
  c_arrival_ = when;
  c_ptime_ = std::rand() % 3 + 1;
}

// Класс Queue
// Конструктор
Queue::Queue(int qsz) : q_size_(qsz)
{
  q_items_ = 0;
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
bool Queue::isEmpty() const
{
  return q_items_ == 0;
}

// Является ли очередь заполненной
bool Queue::isFull() const
{
  return q_items_ == q_size_;
}

// Текущее количество элементов в очереди
int Queue::items() const
{
  return q_items_;
}

// Добавление элемента в очередь
bool Queue::addItem(const Item& itm)
{
  if (isFull())
    return false;
  Node* newNode;            // создаём новый узел
  newNode = new Node;       // выделяем память для нового узла
  newNode->data = itm;      // присваиваем значение новому элементу очереди
  newNode->next = nullptr;  // устанавливаем нулевой указатель
  q_items_++;               // увеличиваем счётчик элементов
  if (front_ == nullptr) 
    front_ = newNode;       // если очередь пуста, то добавляем элемент в начало
  else
    rear_->next = newNode;  // заносим ссылку на новый узел
  rear_ = newNode;          // новый элемент ставится в конец очереди
  return true;
}

// Удаление элемента из очереди
bool Queue::delItem(Item& itm)
{
  if (isEmpty())
    return false;
  itm = front_->data; // передаём в метод первый элемент очереди
  q_items_--;         // уменьшаем счётчик элементов на единицу
  Node* tmp = front_; // сохраняем расположение начального узла
  front_ = front_->next;  // заносим указатель на следующий узел
  delete tmp;             // удаляем старый начальный узел
  if (q_items_ == 0)
    rear_ = nullptr;      // если список уже пуст обнуляем все указатели
  return true;  
}