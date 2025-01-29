// vect.hpp -- Класс Vector c операцией << и поддержкой режима координат

#ifndef VECT_HPP_
#define VECT_HPP_
#include <iostream>

namespace VECTOR
{
  class Vector
  {
  public:
    // RECT -- для режима прямоугольных координат, 
    // POL  -- для режима полярных координат
    enum Mode {RECT, POL};

  private:
    double x;         // горизонтальное значение
    double y;         // вертикальное значение
    double mag;       // длина вектора
    double ang;       // направление вектора в градусах
    Mode mode;        // RECT или POL

    // Закрытые методы для установки значений
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();

  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const { return x; }         // сообщает значение х
    double yval() const { return y; }         // сообщает значение у
    double magval() const { return mag; }     // сообщает длину вектора
    double angval() const { return ang; }     // сообщает угол вектора
    void polar_mode();                        // устанавливает режим в POL
    void rect_mode();                         // устанавливает режим в RECT

    // Перегрузка операций
    Vector operator+(const Vector& rb) const;
    Vector operator-(const Vector& rb) const;
    Vector operator-() const;
    Vector operator*(double n) const;

    // Друзья 
    friend Vector operator*(double n, const Vector& ra);
    friend std::ostream& operator<<(std::ostream& ros, const Vector& rv);
  };
}

#endif