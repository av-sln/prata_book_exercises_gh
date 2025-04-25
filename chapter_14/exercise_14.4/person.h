// person.h -- определение класса Person
#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>

class Person {
private:
  std::string first_name_;    // имя
  std::string last_name_;     // фамилия

public:
  // Конструктор #1
  Person(const std::string& r_fnm = "No first name",
    const std::string& r_lnm = "No last name");
  // Деструктор
  virtual ~Person() {}
  // Вывод всех данных
  virtual void Show() const;
};

// Конструктор #1
Person::Person(const std::string& r_fnm, const std::string& r_lnm)
{
  first_name_ = r_fnm;
  last_name_ = r_lnm;
}

// Вывод всех данных
void Person::Show() const
{
  std::cout << "First name: " << first_name_ << std::endl;
  std::cout << "Last name: " << last_name_ << std::endl;
}

#endif // person.h

