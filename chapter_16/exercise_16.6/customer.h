// customer.h -- загловочный файл класса Customer
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <cstdlib>

class Customer {
private:
  long arrive;      // момент появления клиента
  int processtime;  // время обсдуживания клиента
public:
  void set(long when);
  Customer() { arrive = processtime = 0; }
  long when() const { return arrive; }
  int ptime() const { return processtime; }
};

inline void Customer::set(long when)
{
  processtime = std::rand() % 3 + 1;
  arrive = when;
}

#endif  //customer.h