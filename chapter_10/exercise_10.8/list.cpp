// list.cpp -- реализация методов класса List

#include <iostream>
#include "list.hpp"

List::List()
{
  top_ = 0;
}

List::~List()
{}

bool List::isempty() const
{
  return top_ == 0;
}

bool List::isfull() const
{
  return top_ == MAX;
}

bool List::add(const Item& lst)
{
  if (top_ < MAX) {
    items_[top_++] = lst;
    return true;
  }
  else {
    std::cout << "List is already full. "
              << "The operation is impossible." << std::endl;
    return false;
  }
}

void List::visit(void (*pf)(Item& lst))
{
  for (int i = 0; i < MAX; i++)
    pf(items_[i]);
}

void List::show() const
{
  for (int i = 0; i < top_; i++)
    std::cout << items_[i] << ", ";
  std::cout << "\b\b" << ";" << std::endl;
}