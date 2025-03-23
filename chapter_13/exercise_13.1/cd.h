// Базовый класс
// Представляет компакт-диск

#ifndef CD_H_
#define CD_H_

class Cd {
private:
  char performers[50];      // исполнитель
  char label[20];           // альбом
  int selections;           // количество треков
  double playtime;          // время воспроизведения в минутах

public:
  Cd(const char* ps1, const char* ps2, int n, double x);
  Cd();
  virtual ~Cd() {};
  virtual void Report() const;      // выводит все данные о компакт-диске
  virtual Cd& operator=(const Cd& rcd);
};

#endif // cd.h