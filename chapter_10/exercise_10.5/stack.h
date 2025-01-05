// stack.h -- определение стека

#ifndef STACK_H_
#define STACK_H_

struct customer
{
  char fullname[35];
  double payment;
};

typedef customer Item;

class Stack
{
private:
  enum {MAX = 10};
  Item items_[MAX];
  int top_;   

public:
  Stack();
  bool isempty() const;
  bool isfull() const;

  // Добавляет элемент в стек
  // push() возвращает false, если стек полон, и true - в противном случае
  bool push(const Item& item);

  // Выталкивает элемент из вершины стека
  // pop() возвращает false, если стек пуст, и true - в противном случае
  bool pop(const Item& item);
};

#endif