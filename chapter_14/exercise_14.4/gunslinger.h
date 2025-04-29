// gunslinger.h -- определение класса Gunslinger
#ifndef GUNSLINGER_H_
#define GUNSLINGER_H_
#include "person.h"

class Gunslinger : virtual public Person {
private:
  double ready_time_;         // время на изготовку
  int notch_;                 // количество насечек

protected:
  void data() const;
  void get();

public:
  // Конструктор #1
  Gunslinger() : Person(), ready_time_(0.0), notch_(0) {}
  // Констуктор #2
  Gunslinger(const std::string& r_fnm, const std::string& r_lnm, 
    double rt = 0.0, int n = 0)
    : Person(r_fnm, r_lnm), ready_time_(rt), notch_(n) {}
  // Конструктор #3
  Gunslinger(const Person& r_prn, double rt = 0.0, int n = 0)
    : Person(r_prn), ready_time_(rt), notch_(n) {}
  
  double Draw() const { return ready_time_; }
  void set();
  void Show() const;   
};

// Защищённые методы
void Gunslinger::data() const
{
  std::cout << "Ready time: " << Draw() << std::endl;
  std::cout << "Notches: " << notch_ << std::endl;
}

void Gunslinger::get()
{
  std::cout << "Enter gunslinger's ready time: ";
  std::cin >> ready_time_;
  std::cout << "Enter number of notches: ";
  std::cin >> notch_;
  while (std::cin.get() != '\n')
    continue;
}

// Открытые методы
void Gunslinger::set()
{
  std::cout << "Enter gunslinger's first name: ";
  Person::get();
  get();
}

void Gunslinger::Show() const
{
  std::cout << "Category: Gunslinger\n";
  Person::data();
  data();
}

#endif // gunslinger.h