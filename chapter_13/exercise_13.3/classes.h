// classes.h -- файл содержит определения абстрактного базового класса
// классов: baseDMA, lacksDMA и hasDMA

// Абстрактный базовый класс baseABC
// использует динамическое выделение памяти
#ifndef CLASSES_H_
#define CLASSES_H_

class baseABC {
private:
  char* label_;
  int rating_;

public:
  // Конструктор
  baseABC(const char* l = "null", int r = 0);
  // Конструктор копирования
  baseABC(const baseABC& rs);
  // Деструктор
  virtual ~baseABC();
  // Перегруженная операция присваивания
  virtual baseABC& operator=(const baseABC& rs);
  // Вывод всех данных
  virtual void view() const = 0;

protected:
  const char* viewLabel() const { return label_; }
  int viewRating() const { return rating_; }
};

// Класс baseDMA
// Производный класс без динамического выделения памяти
// Не добавляет новых членов использует методы baseABC
// Деструктор не нужен
// Использует неявный конструктор копирования
// Используется неявная операция присваивания
class baseDMA : public baseABC {
public:
  baseDMA(const char* l = "null", int r = 0);  
  virtual void view() const;
};

// Класс lacksDMA
// Производный класс без динамического выделения памяти
// Деструктор не нужен
// Использует неявный конструктор копирования
// Использует неявную операцию присваивания
// Добавляет новый член в виде символьного массива
class lacksDMA : public baseABC {
private:
  enum {COL_LEN = 40};
  char color_[COL_LEN];

public:
  // Конструктор по умолчанию
  lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
  // Конструктор с аргументами
  lacksDMA(const char* c, const baseABC& rs);
  virtual void view() const;
};

// Класс hasDMA
// Производный класс с динамическим выделением памяти
// Содержит деструктор
// Явный конструктор копирования
// Перегруженная операция присваивания
// Добавляет новый член в виде char*
class hasDMA : public baseABC {
private:
  char* style_;

public:
  // Конструктор по умолчанию
  hasDMA(const char* st = "none", const char* l = "null", int r = 0);
  // Конструктор с аргументами
  hasDMA(const char* st, const baseABC& rs);
  // Конструктор копирования
  hasDMA(const hasDMA& rhs);
  // Деструктор
  ~hasDMA();
  // Перегруженная операция присваивания
  hasDMA& operator=(const hasDMA& rhs);
  virtual void view() const;
};

#endif // classes.h