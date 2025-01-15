// stack.cpp -- файл реализации методов класса Stack

#include <iostream>
#include "stack.h"

// Метод добавления
bool Stack::push(const Item& item)
{
  if (!Stack::isfull()) {
    items_[top_++] = item;
    return true;
  }
  else 
    return false;
}

// Метод исключения
bool Stack::pop(Item& item)
{
  if (!Stack::isempty()) {
    item = items_[--top_];
    return true;
  }
  else 
    return false;
}
