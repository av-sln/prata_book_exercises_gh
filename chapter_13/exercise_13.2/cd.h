// cd.h -- заголовочный файл базового класса Cd

#ifndef CD_H_
#define CD_H_

// Базовый класс
class Cd {
private:
  char*  performers_;   // испольнитель
  char*  label_;        // альбом
  int    selections_;   // количество треков
  double playtime_;     // время воспроизведения в минутах

public:
  // Конструктор
  Cd(const char* s1, const char* s2, int n, double x);
  // Конструктор копирования
  Cd(const Cd& rd);
  // Конструктор по умолчанию
  Cd();
  // Деструктор
  virtual ~Cd();
  // Вывод всех данных о компакт диске
  virtual void Report() const;
  // Перегруженная операция присваивания
  virtual Cd& operator=(const Cd& rd);
};

#endif