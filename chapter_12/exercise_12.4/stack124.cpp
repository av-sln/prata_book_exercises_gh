// stack124.cpp -- файл реализации класса Stack

#include <iostream>
#include "stack124.hpp"

// Конструкторы/деструктор
// Конструктор по умолчанию
Stack::Stack(int n)
{
  size_ = n;
  pitems_ = new Item[size_];
  top_ = 0;
}

// Конструктор копирования
Stack::Stack(const Stack &rst)
{
  size_ = rst.size_;
  top_ = rst.top_;
  pitems_ = new Item[size_];
  for (int i = 0; i < top_; i++)
    pitems_[i] = rst.pitems_[i];
  
}

// Деструктор
Stack::~Stack()
{
  delete [] pitems_;
}

// Методы класса
// Пуст ли стек
bool Stack::isempty() const
{
  return top_ == 0;
}

// Полон ли стек
bool Stack::isfull() const
{
  return top_ == size_;
}

// Добавление элемента в стек
bool Stack::push(const Item &ritem)
{
  bool flag;
  if (isfull()) {
    std::cout << "Stack is already full!\n"
              << "The operaration can't be performed!\n";
    flag = false;
  } 
  else {
    pitems_[top_++] = ritem;
    std::cout << ritem << " was pushed.\n";
    std::cout << "The operation was completed successfully.\n";
    flag = true;
  }
  return flag;
}

// Извлечение элемента из стека
bool Stack::pop(Item &ritem)
{
  bool flag;
  if (isempty()) {
    std::cout << "Stack is already empty!\n"
              << "The operation can't be performed!\n";
    flag = false;
  }
  else {
    ritem = pitems_[--top_];
    std::cout << ritem << " was poped.";
    std::cout << "The operation was completed successfully.\n";
    flag = true;
  }
  return flag;
}

// Перегрузка операций
// Операция присваивания
Stack & Stack::operator=(const Stack &rst)
{
  if (this == &rst)
    return *this;
  else {
    delete [] pitems_;
    size_ = rst.size_;
    top_ = rst.top_;
    pitems_ = new Item[size_];
    for (int i = 0; i < top_; i++)
      pitems_[i] = rst.pitems_[i];
  }
  return *this;
}