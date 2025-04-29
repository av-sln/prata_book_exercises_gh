// baddude.h -- определение класса BadDude

#ifndef BADDUDE_H_
#define BADDUDE_H_
#include "gunslinger.h"
#include "pockerplayer.h"

class BadDude : public Gunslinger, public PockerPlayer {
protected:
  void data() const;
  void get();

public:
  // Конструктор #1
  BadDude() {}
  // Конструктор #2
  BadDude(const std::string& r_fnm, const std::string& r_lnm,
    double rt = 0, int n = 0, int crd = 1)
    : Person(r_fnm, r_lnm), Gunslinger(r_fnm, r_lnm, rt, n),
      PockerPlayer(r_fnm, r_lnm, crd) {}
  // Конструктор #3
  BadDude(const Person& r_prn, double rt = 0, int n = 0, int crd = 1)
    : Person(r_prn), Gunslinger(r_prn, rt, n), PockerPlayer(r_prn, crd) {}
  // Конструктор #4
  BadDude(const Gunslinger& r_gnl, int crd = 1)
    : Person(r_gnl), Gunslinger(r_gnl), PockerPlayer(r_gnl, crd) {}
  // Конструктор #5
  BadDude(const PockerPlayer& r_pp, double rt = 0.0, int n = 0)
    : Person(r_pp), Gunslinger(r_pp, rt, n), PockerPlayer(r_pp) {}
  
  // Вывод всех данных
  void Show() const;
  // Установка значений объекта
  void set();
  // Время вынимания оружия
  double Gdraw() const;
  // Показ карты
  int Cdraw() const;
};

// Защищённые методы
void BadDude::data() const
{
  Gunslinger::data();
  PockerPlayer::data();
}

void BadDude::get()
{
  Gunslinger::get();
  PockerPlayer::get();
}

// Открытые методы 
void BadDude::Show() const
{
  std::cout << "Category: BadDude\n";
  Person::data();
  data(); 
}

void BadDude::set()
{
  std::cout << "Enter BadDude's first name: ";
  Person::get();
  get();
}

double BadDude::Gdraw() const
{
  return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
  return PockerPlayer::Draw();
}

#endif // baddude.h