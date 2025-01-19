// list.hpp -- заголовочный файл класса List

#ifndef LIST_HPP_
#define LIST_HPP_

typedef double Item;
class List
{
private:
  enum {MAX = 10};
  Item items_[MAX];
  int top_;

public:
  List();                           // Конструктор по умолчанию
  ~List();                          // Деструктор
  bool isempty() const;             // пуст ли список
  bool isfull() const;              // полон ли список
  bool add(const Item& lst);        // добавить элемент в список
  void visit(void(*pf)(Item& lst)); // посетить каждый элемент списка
  void show() const;                // отобразить список
};

#endif