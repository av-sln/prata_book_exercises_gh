// string122.cpp -- файл реализации методов класса String122

#include <iostream>
#include <cctype>
#include <cstring>
#include "string122.hpp"

// Конструкторы/деструктор
// Конструктор по умолчанию
String122::String122()
{
  len_ = 0;
  str_ = new char[1];
  str_ = nullptr;
}

// Конструктор с аргументами
String122::String122(const char *pstr)
{
  len_ = std::strlen(pstr);
  str_ = new char[len_ + 1];
  std::strcpy(str_, pstr);
}

// Конструктор копирования
String122::String122(const String122 &rstr)
{
  len_ = rstr.len_;
  str_ = new char[len_ + 1];
  std::strcpy(str_, rstr.str_);
}

// Деструктор
String122::~String122()
{
  delete [] str_;
}

// Методы класса
// Длина строки
int String122::strlen() const
{
  return len_;
}

// Преобразование всех буквенных символов строки в нижний регистр
void String122::stringlow()
{
  for (int i = 0; i < len_; i++) 
    if (std::isalpha(str_[i]))
      str_[i] = std::tolower(str_[i]);
}

// Преобразование всех буквенных символов строки в верхний регистр
void String122::stringup()
{
  for (int i = 0; i < len_; i++)
    if (std::isalpha(str_[i]))
      str_[i] = std::toupper(str_[i]);
}

// Возвращает количество раз, которое символ появился в строке
int String122::numchar(char s) const
{
  int counter = 0;
  for (int i = 0; i < len_; i++) 
    if (str_[i] == s)
      counter++;
  return counter;
}

// Перегруженные операции
// Объединяет две строки в одну
String122 String122::operator+(const String122 &rstr2) const
{
  String122 tmp;
  tmp.len_ = len_ + rstr2.len_;
  tmp.str_ = new char[tmp.len_ + 1];
  std::strcpy(tmp.str_, str_);
  std::strcat(tmp.str_, rstr2.str_);
  return tmp;
}

// Присваивает объект String122 объекту String122
String122 & String122::operator=(const String122 &rstr2)
{
  if (this == &rstr2)
    return *this;
  delete [] str_;
  len_ = rstr2.len_;
  str_ = new char[len_ + 1];
  std::strcpy(str_, rstr2.str_);
  return *this;
}

// Присваивает объекту String122 строку в стиле С
String122 & String122::operator=(const char *pstr)
{
  delete [] str_;
  len_ = std::strlen(pstr);
  str_ = new char[len_ + 1];
  std::strcpy(str_, pstr);
  return *this;
}

// Чтение и запись отдельных символов в неконстантном объекте String122
char & String122::operator[](int i)
{
  return str_[i];
}

// Доступ для чтения отдельных символов в константном объекте String122
const char & String122::operator[](int i) const
{
  return str_[i];
}

// Друзья
// Объединение строки в стиле С с объектом String122
String122 operator+(const char *pstr, const String122 & rstr)
{
  String122 tmp;
  tmp.len_ = std::strlen(pstr) + rstr.len_;
  tmp.str_ = new char[tmp.len_ + 1];
  std::strcpy(tmp.str_, pstr);
  std::strcat(tmp.str_, rstr.str_);
  return tmp;
}

// Сравнение строк
bool operator<(const String122 &rstr1, const String122 &rstr2)
{
  bool flag;
  if (std::strcmp(rstr1.str_, rstr2.str_) < 0)
    flag = true;
  else
    flag = false;
  return flag;
}

bool operator>(const String122 &rstr1, const String122 &rstr2)
{
  bool flag;
  if (std::strcmp(rstr1.str_, rstr2.str_) > 0)
    flag = true;
  else
    flag = false;
  return flag;
}

bool operator==(const String122 &rstr1, const String122 &rstr2)
{
  bool flag;
  if (std::strcmp(rstr1.str_, rstr2.str_) == 0)
    flag = true;
  else
    flag = false;
  return flag;
}

// Вывод строки
std::ostream & operator<<(std::ostream &rout, const String122 &rstr)
{
  rout << rstr.str_;
  return rout;
}

// Ввод строки
std::istream & operator>>(std::istream &rin, String122 &rstr)
{
  char tmp[String122::CinLim_];
  rin.get(tmp, String122::CinLim_);
  if (rin)
    rstr = tmp;
  while (rin && rin.get() != '\n')
    continue;
  return rin;
}