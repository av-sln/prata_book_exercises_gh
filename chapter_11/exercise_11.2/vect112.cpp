// vect.cpp -- реализация методов класса Vector

#include <cmath>
#include "vect112.hpp"

namespace VECTOR
{
  // Вычисляет количество градусов в одном радиане
  const double Rad_to_deg = 45.0 / std::atan(1.0);

  // Закрытые методы
  // Вычисляет длину вектора из х и у
  double Vector::magval() const
  {
    return std::sqrt(x * x + y * y);
  }

  // Вычисляет угол вектора
  double Vector::angval() const
  {
    return (x == 0.0 && y == 0.0) ? 0.0 : std::atan2(y, x);
  }

  // Устанавливает х по полярным координатам
  void Vector::set_x(double mag, double ang)
  {
    x = mag * std::cos(ang);
  }

  // Устанавливает у по полярным координатам
  void Vector::set_y(double mag, double ang)
  { 
    y = mag * sin(ang);
  }

  // Открытые методы
  // Конструктор по умолчанию
  Vector::Vector()
  {
    x = y = 0.0;
    mode = RECT;
  }

  // Конструирует вектор по прямоугольным координатам, если form равно RECT
  // или по полярным координатам, если form равно POL
  Vector::Vector(double n1, double n2, Mode form)
  {
    mode = form;
    if (form == RECT) {    
      x = n1;
      y = n2;
    }    
    else if (form == POL) {
      double mag = n1;
      double ang = n2 / Rad_to_deg;
      set_x(mag, ang);
      set_y(mag, ang);
    }
    else {
      // Некорректный третий аргумент Vector(); вектор устанавливается в 0
      std::cout << "Incorrect 3rd argument to Vector() -- ";
      std::cout << "Vector set to 0\n";
      x = y = 0.0;
      mode = RECT;
    }
  }

  // Устанавливает вектор по прямоугольным координатам, если form равно RECT
  // или по полярным координатам, если form равно POL
  void Vector::reset(double n1, double n2, Mode form)
  {
    mode = form;
    if (form == RECT) {
      x = n1;
      y = n2;
    }
    else if (form == POL) {
      double mag = n1;
      double ang = n2 / Rad_to_deg;
      set_x(mag, ang);
      set_y(mag, ang);
    }
    else {
      std::cout << "Incorrect 3rd argument to Vector() -- ";
      std::cout << "Vector set to 0\n";
      x = y = 0.0;
      mode = RECT;
    }
  }

  // Деструктор
  Vector::~Vector()
  {}

  // Устанавливает режим полярных координат
  void Vector::polar_mode()
  {
    mode = POL;
  }

  // Устанавливает режим прямоугольных координат
  void Vector::rect_mode()
  {
    mode = RECT;
  }

  // Перегрузка операций
  // Сложение двух векторов
  Vector Vector::operator+(const Vector& rb) const
  {
    return Vector(x + rb.x, y + rb.y);
  }

  // Вычитание вектора b из a
  Vector Vector::operator-(const Vector& rb) const
  {
    return Vector(x - rb.x, y - rb.y);
  }

  // Смена знака вектора на противоположный 
  Vector Vector::operator-() const
  {
    return Vector(-x, -y);
  }

  // Умножение вектора на n
  Vector Vector::operator*(double n) const
  {
    return Vector(n * x, n * y);
  }

  // Дружественные методы
  // Умножение n на вектор a
  Vector operator*(double n, const Vector& ra)
  {
    return ra * n;
  }

  // Отображает прямоугольные координаты, если mode равно RECT,
  // или отображает полярные координаты, если mode равно POL
  std::ostream& operator<<(std::ostream& ros, const Vector& rv)
  {
    if (rv.mode == Vector::RECT)
      ros << "(x, y) = (" << rv.x << ", " << rv.y << ")";
    else if (rv.mode == Vector::POL) 
      ros << "(m, a) = (" << rv.magval() << ", "
          << rv.angval() * Rad_to_deg << ")";
    else
      ros << "Vector object mode is invalid";
    return ros;      
  }
}