// ctack124.hpp -- заголовочный файл класса Stack

#ifndef STACK124_HPP_
#define STACH124_HPP_

typedef unsigned long Item;

class Stack
{
private:
  enum {MAX = 10};          // максимальное количество элементов в стеке
  Item *pitems_;            // элементы стека
  int size_;                // количество элементов в стеке (размер стека)
  int top_;                 // индекс верхнего элемента стека

public:
  // Конструкторы/деструктор
  // Конструктор по умолчанию
  Stack(int n = MAX);
  // Конструктор копирования
  Stack(const Stack &rst);
  // Деструктор
  ~Stack();

  // Методы класса
  // Пуст ли стек
  bool isempty() const;
  // Полон ли стек
  bool isfull() const;
  // Добавление элемента в стек. Возвращает false, если стек полный
  // и true в противном случае
  bool push(const Item &ritem);
  // Извлечение элемента из стека. Возвращает false, если стек пустой
  // и true в противном случае
  bool pop(Item &ritem);

  // Перегруженные операции
  // Операция присваивания
  Stack & operator=(const Stack &rst);
};

#endif