// classic.h -- заголовочный файл производного класса Classic

#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

// Производный класс Classic
class Classic : public Cd {
private:
  char* favorite_;    // любимая мелодия

public:
  // Конструктор по умолчанию
  Classic();
  // Конструктор с аргументами
  Classic(const char* pf, const char* s1, const char* s2, int n, double x);
  // Конструктор копирования
  Classic(const Classic& rcd);
  // Деструктор
  ~Classic();
  // Вывод всех данных о компакт диске
  virtual void Report() const;
  // Перегруженная операция присваивания
  Classic& operator=(const Classic& rcd);
};











#endif