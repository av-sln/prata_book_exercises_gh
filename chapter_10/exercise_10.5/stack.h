// stack.h -- определение стека

#ifndef STACK_H_
#define STACK_H_

const int StrSize = 35;

struct customer
{
  char fullname[StrSize];
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
  Stack() { top_ = 0; }
  ~Stack() {}
  bool isempty() const { return top_ == 0; }
  bool isfull() const { return top_ == MAX; }
  
  // Добавляет элемент в стек
  // push() возвращает false, если стек полон, и true - в противном случае
  bool push(const Item& item);

  // Выталкивает элемент из вершины стека
  // pop() возвращает false, если стек пуст, и true - в противном случае
  bool pop(Item& item);
};

#endif