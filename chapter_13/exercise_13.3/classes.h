// classes.h -- файл содержит определения абстрактного базового класса
// классов: baseDMA, lacksDMA и hasDMA

// Абстрактный базовый класс baseABC
// использует динамическое выделение памяти
#ifndef CLASSES_H_
#define CLASSES_H_

class baseABC {
private:
  char* label_;
  int   rating_;

public:
  // Конструктор
  baseABC(const char* plb = "none", int rt = 0);
  // Конструктор копирования
  baseABC(const baseABC& rabc);
  // Деструктор
  virtual ~baseABC() = 0;
  // Перегруженная операция присваивания
  // Операция присваивания не наследуется
  // Используется без ключевого слова virtual
  baseABC& operator=(const baseABC& rabc);
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
// Использует неявную операцию присваивания

class baseDMA : public baseABC {
public:
  baseDMA(const char* plb = "none", int rt = 0);  
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
  lacksDMA(const char* pcl = "none", const char* plb = "none", int rt = 0);
  // Конструктор с аргументами
  lacksDMA(const char* pcl, const baseABC& rabc);
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
  hasDMA(const char* pst = "none", const char* plb = "none", int rt = 0);
  // Конструктор с аргументами
  hasDMA(const char* pst, const baseABC& rabc);
  // Конструктор копирования
  hasDMA(const hasDMA& rdma);
  // Деструктор
  ~hasDMA();
  // Перегруженная операция присваивания
  hasDMA& operator=(const hasDMA& rdma);
  virtual void view() const;
};

#endif // classes.h