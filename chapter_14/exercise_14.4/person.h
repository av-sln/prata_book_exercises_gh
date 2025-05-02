// person.h -- определение абстрактного базового класса Person
#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>

class Person {
private:
  std::string first_name_;    // имя
  std::string last_name_;     // фамилия
protected:
  virtual void data() const;
  virtual void get();

public:
  // Конструктор #1
  Person() : first_name_("No first name"), last_name_("No last name") {}
  // Конструктор #2
  Person(const std::string& r_fnm, const std::string& r_lnm)
    : first_name_(r_fnm), last_name_(r_lnm) {} 
  // Деструктор
  virtual ~Person() = 0;
  // Вывод всех данных
  virtual void Show() const = 0;
  // Установка значений объекта   
  virtual void set() = 0; 
};

// Деструктор
Person::~Person() {}

// Вывод всех данных
void Person::Show() const
{
  std::cout << "First name: " << first_name_ << std::endl;
  std::cout << "Last name: " << last_name_ << std::endl;
}

void Person::data() const
{
  std::cout << "First name: " << first_name_ << std::endl;
  std::cout << "Last name: " << last_name_ << std::endl;
}

void Person::get()
{
  getline(std::cin, first_name_);
  std::cout << "Enter last name: ";
  getline(std::cin, last_name_);
}

#endif // person.h