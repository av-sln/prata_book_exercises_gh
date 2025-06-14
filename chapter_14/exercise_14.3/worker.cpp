// worker.cpp -- релизация классов работников с множественным наследованием
#include <iostream>
#include "worker.h"

// Методы Worker
Worker::~Worker() {}
void Worker::Data() const
{
  std::cout << "Name: " << fullname << std::endl;
  std::cout << "Employee ID: " << id << std::endl;  
}

void Worker::Get()
{
  getline(std::cin, fullname);
  std::cout << "Enter worker's ID: ";
  std::cin >> id;
  while (std::cin.get() != '\n')
    continue;
}

// Методы Waiter
void Waiter::Set()
{
  std::cout << "Enter waiter's name: ";
  Worker::Get();
  Get();
} 

void Waiter::Show() const
{
  std::cout << "Category: waiter\n";
  Worker::Data();
  Data();
}

// Защищённые методы
void Waiter::Data() const
{
  std::cout << "Panache rating: " << panache << std::endl;
}

void Waiter::Get()
{
  std::cout << "Enter waiter's panache rating: ";
  std::cin >> panache;
  while (std::cin.get() != '\n')
    continue;  
}

// Методы Singer
const char* Singer::pv[Singer::Vtypes] = {
  "other", "alto", "contralto", "soprano",
  "bass", "baritone", "tenor"
};

void Singer::Set()
{
  std::cout << "Enter singer's name: ";
  Worker::Get();
  Get();
}

void Singer::Show() const
{
  std::cout << "Category: singer\n";
  Worker::Data();
  Data();
}

// Защищённые методы
void Singer::Data() const
{
  std::cout << "Vocal range: " << pv[voice] << std::endl;
}

void Singer::Get()
{
  std::cout << "Enter number for singer's vocal range:\n";
  int i;
  for (i = 0; i < Vtypes; i++) {
    std::cout << i << ": " << pv[i] << " ";
    if (i % 4 == 3)
      std::cout << std::endl;
  }
  if (i % 4 != 0)
    std::cout << std::endl;
  std::cin >> voice;
  while (std::cin.get() != '\n')
    continue;
}

// Методы SingingWaiter
void SingingWaiter::Data() const
{
  Singer::Data();
  Waiter::Data();
}

void SingingWaiter::Get()
{
  Waiter::Get();
  Singer::Get();
}

void SingingWaiter::Set()
{
  std::cout << "Enter singing waiter's name: ";
  Worker::Get();
  Get();
}

void SingingWaiter::Show() const
{
  std::cout << "Category: singing waiter\n";
  Worker::Data();
  Data();
}