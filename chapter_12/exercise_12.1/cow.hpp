// cow.hpp -- заголовочный файл класса Cow

#ifndef COW_HPP_
#define COW_HPP_

class Cow
{
private:
  char name_[20];
  char *hobby_;
  double weight_;

public:
  // Конструктор по умолчанию
  Cow();
  // Конструктор с аргументами
  Cow(const char *pnm, const char *pho, double wt);
  // Конструктор копирования
  Cow(const Cow& rc);
  // Деструктор
  ~Cow();
  // Перегруженный оператор присваивания
  Cow& operator=(const Cow& rc);
  // Отображение всех данных объекта Cow
  void ShowCow() const;
};

#endif