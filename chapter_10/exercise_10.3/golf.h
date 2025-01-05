// golf.h -- определение класса Golf

#ifndef GOLF_H_
#define GOLF_H_

const int LEN = 40;

class Golf
{
private:
  char fullname_[LEN];
  int handicap_;

public:
  // Конструктор
  Golf(const char* fullname = "Nobody", int handicap = 0);

  // Деструктор
  ~Golf();

  // Метод предлагает пользователю ввести имя и ганидкап, присваивает
  // элементам класса Golf введённые значения;
  // возвращает 1, если введено имя, и 0, если введена пустая строка
  int SetGolf();

  // Метод устанавливает новое значение гандикапа
  void HandiCap(int handicap);

  // Метод отображает данные игрока
  void ShowGolf() const;
};

#endif