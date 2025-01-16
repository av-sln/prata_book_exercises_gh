// plorg.hpp -- объвление класс Plorg

#ifndef PLORG_HPP_
#define PLORG_HPP_

const int NameSize = 19;

class Plorg
{
private:
  char name_[NameSize];
  int ci_;

public:
  Plorg();    // Конструктор по умолчанию
  Plorg(const char* name, int ci = 50); // конструктор с аргументами
  ~Plorg();   // деструктор
  void changeindex(const int ci);
  void showplorg() const;
};

#endif