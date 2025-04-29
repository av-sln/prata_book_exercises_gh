// pockerplayer.h -- определение класса PockerPlayer
#ifndef POCKERPLAYER_H_
#define POCKERPLAYER_H_
#include <cstdlib>
#include <ctime>
#include "person.h"

class PockerPlayer : virtual public Person {
private:
  int card_;

protected:
  void data() const;
  void get();
  
public:
  // Конструктор #1
  PockerPlayer() : Person(), card_(1) {}
  // Конструктор #2
  PockerPlayer(const std::string& r_fnm, const std::string& r_lnm, int crd = 1)
    : Person(r_fnm, r_lnm), card_(crd) {}
  // Конструктор #3
  PockerPlayer(const Person& r_prn, int crd = 1)
    : Person(r_prn), card_(crd) {}
  int Draw() const;
  void set();
  void Show() const;
};

// Защищённые методы
void PockerPlayer::data() const
{
  std::cout << "Card: " << card_ << std::endl;
}

void PockerPlayer::get()
{
  card_ = Draw();
}

void PockerPlayer::set()
{
  std::cout << "Enter pockerplayer's first name: ";
  Person::get();
  get();
}

void PockerPlayer::Show() const
{
  std::cout << "Category: Pockerplayer\n";
  Person::data();
  data();
}

int PockerPlayer::Draw() const
{
  std::srand(std::time(0));   // случайная инициализация rand
  int res = std::rand() % 52 +  1;
  return res;
}

#endif // pockerplayer.h