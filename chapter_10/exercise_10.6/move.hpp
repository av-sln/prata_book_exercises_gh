// move.hpp -- заголовочный файл определения класса Move

#ifndef MOVE_HPP_
#define MOVE_HPP_

class Move
{
private:
  double x;
  double y;

public:
  Move(double a = 0, double y = 0); // конструктор по умолчанию
  ~Move();                          // деструктор
  void showmove() const;            // отображение текущих значений объекта
  Move add(const Move& m) const;    // добавление данных 
  void reset(double a = 0, double b = 0); // сброс значений объекта
};

#endif