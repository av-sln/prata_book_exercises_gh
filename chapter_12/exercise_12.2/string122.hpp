// string122.hpp -- заголовочный файл класса String122

#ifndef STRING122_HPP_
#define STRING122_HPP_
#include <iostream>

class String122
{
private:
  char *str_;                          // указатель на строку
  int len_;                         // длина строки
  static const int CinLim_ = 80;       // предел ввода для cin

public:
  // Конструктор по умолчанию
  String122();
  // Конструктор с аргументами
  String122(const char *pstr);
  // Конструктор копирования
  String122(const String122 &rstr);
  // Деструктор
  ~String122();

  // Методы
  // Длинаа строки
  int strlen() const;
  // Преобразование буквенных символов строки в нижний регистр
  void stringlow();
  // Преобразование буквенных символов строки в верхний регистр
  void stringup();
  // Возвращает количество раз, которое символ появился в строке
  int numchar(char s) const;

  // Перегруженные операции
  // Объединяет две строки в одну
  String122 operator+(const String122 &rstr2) const;
  // Присваивает объект объекту
  String122 & operator=(const String122 &rstr2);
  // Присваивает объекту строку в стиле С
  String122 & operator=(const char *pstr);
  // Чтение и запись отдельных символов в неконстантном объекте
  char & operator[](int i);
  // Доступ для чтения отдельных символов в константном объекте
  const char & operator[](int i) const;

  // Друзья
  // Объединение строки в стиле С с объектом String122
  friend String122 operator+(const char *pstr, const String122 &rstr);
  // Сравнение строк
  friend bool operator<(const String122 &rstr1, const String122 &rstr2);
  friend bool operator>(const String122 &rstr1, const String122 &rstr2);
  friend bool operator==(const String122 &rstr1, const String122 &rstr2);
  // Вывод строки
  friend std::ostream & operator<<(std::ostream &rout, const String122 &rstr);
  // Ввод строки
  friend std::istream & operator>>(std::istream &rin, String122 &rstr);
};

#endif