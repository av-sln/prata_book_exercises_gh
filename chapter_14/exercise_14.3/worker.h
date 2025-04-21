// worker.h -- класс Worker

#ifndef WORKER_H_
#define WORKER_H_
#include <string>
#include <iostream>

class Worker {
private:
  std::string fullname_;
  long id_;

protected:
  void Data() const;
  void Get();

public:
  Worker() : fullname_("no one"), id_(0L) {}
  Worker(const std::string& r_str, long n)
    : fullname_(r_str), id_(n) {}
};

// Методы класса Worker
void Worker::Data() const
{
  std::cout << "Name: " << fullname_ << std::endl;
  std::cout << "Employee ID: " << id_ << std::endl;
}

void Worker::Get()
{
  std::cout << "Enter worker's name: ";
  getline(std::cin, fullname_);
  std::cout << "Enter worker's ID: ";
  std::cin >> id_;
  while (std::cin.get() != '\n')
    continue;
}

#endif // worker.h