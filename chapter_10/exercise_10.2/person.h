// person.h -- определение класса Person

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
private:
  static const int LIMIT = 25;
  std::string lname_;          // фамилия
  char fname_[LIMIT];          // имя

public:
  // Конструктор по умолчанию #1
  Person() { lname_ = ""; fname_[0] = '\0'; }

  // Конструктор #2
  Person(const std::string& lname, const char* fname = "Heyyou");

  // Деструктор
  ~Person();

  // Методы отображения lname и fname
  void Show() const;          // формат: имя фамилия
  void FormalShow() const;    // формат: фамилия, имя
};

#endif