// queue125.hpp -- определение класса Queue

#ifndef QUEUE125_HPP_
#define QUEUE125_HPP_

typedef int Item;

class Queue
{
private:
  struct Node
  {
    Item item;
    Node *next;
  };
  static const int QSZ = 10;    // количество элементов в очереди по умолчанию
  int qcount_;                  // текущее количество элементов в очереди
  Node *front_;                 // указатель на первый элемент очереди
  Node *rear_;                  // указатель на последний элемент очереди
  const int maxsize_;             // максимальный размер очереди (аргумент)

public:
  // Конструкторы/деструктор
  Queue(int qs = QSZ);    // конструктор по умолчанию
  ~Queue();               // деструктор

  // Методы
  bool isempty() const;   // является ли очередь пустой
  bool isfull() const;    // является ли очередь заполненной
  bool inqueue(const Item &Item); // добавление элемента в конец очереди
  bool delqueue(Item &item);      // удаление элемента из начала очереди
  int qitems() const;   // количество элементов в очереди  
};

#endif