// emp.cpp -- реализация методов класса AbstrEmp и его производных
#include "emp.h"

// Методы AbstrEmp
// Конструктор #1
AbstrEmp::AbstrEmp()
{
  fname = "No first name";
  lname = "No last name";
  job = "No job";
}
// Конструктор #2
AbstrEmp::AbstrEmp(const std::string& fn, const std::string& ln,
  const std::string& j)
{
  fname = fn;
  lname = ln;
  job = j;
}
// Деструктор
AbstrEmp::~AbstrEmp() {}
// Выводит все данные с именами
void AbstrEmp::ShowAll() const
{
  std::cout << "First name: " << fname << std::endl;
  std::cout << "Last name: " << lname << std::endl;
  std::cout << "Job: " << job << std::endl;
}
// Запрашивает значения у пользователя
void AbstrEmp::SetAll()
{
  std::cout << "Enter first name: ";
  getline(std::cin, fname);
  std::cout << "Enter last name: ";
  getline(std::cin, lname);
  std::cout << "Enter a job: ";
  getline(std::cin, job);
}
// Перегрузка операций
std::ostream& operator<<(std::ostream& os, const AbstrEmp& e)
{
  os << "First name: " << e.fname << std::endl;
  os << "Last name: " << e.lname << std::endl;
  return os;
}

// Методы класса Employee
// Конструктор #1
Employee::Employee() : AbstrEmp() {}
// Конструктор #2
Employee::Employee(const std::string& fn, const std::string& ln,
  const std::string& j) : AbstrEmp(fn, ln, j) {}
// Выводит все данные
void Employee::ShowAll() const
{
  AbstrEmp::ShowAll();
}
// Запрашивает значения у пользователя
void Employee::SetAll()
{
  AbstrEmp::SetAll();
}

// Методы класса Manager
// Конструктор #1
Manager::Manager() : AbstrEmp(), inchargeof(0) {}
// Конструктор #2
Manager::Manager(const std::string& fn, const std::string& ln,
  const std::string& j, int ico)
  : AbstrEmp(fn, ln, j)
{
  inchargeof = ico;
}
// Конструктор #3
Manager::Manager(const AbstrEmp& e, int ico) : AbstrEmp(e)
{
  inchargeof = ico;
}
// Конструктор #4
Manager::Manager(const Manager& m) : AbstrEmp(m)
{
  inchargeof = m.inchargeof;
}
// Вывод всех данных
void Manager::ShowAll() const
{
  AbstrEmp::ShowAll();
  std::cout << "In charge of: " << inchargeof << std::endl;
}
// Запрашивает значения у пользователя
void Manager::SetAll()
{
  AbstrEmp::SetAll();
  std::cout << "In charge of: ";
  std::cin >> inchargeof;
  std::cin.get();
}

// Методы класса Fink
// Констурктор #1
Fink::Fink() : AbstrEmp() {}
// Конструктор #2
Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j,
  const std::string& rpo)
  : AbstrEmp(fn, ln, j)
{
  reportsto = rpo;
}
// Конструктор #3
Fink::Fink(const AbstrEmp& e, const std::string& rpo)
  : AbstrEmp(e)
{
  reportsto = rpo;
}
// Конструктор #4
Fink::Fink(const Fink& e) : AbstrEmp(e)
{
  reportsto = e.reportsto;
}
// Вывод всех данных
void Fink::ShowAll() const
{
  AbstrEmp::ShowAll();
  std::cout << "Who output the reports: " << reportsto << std::endl;
}
// Запрашивает значения у пользователя
void Fink::SetAll()
{
  AbstrEmp::SetAll();
  std::cout << "Enter who output the reports: ";
  getline(std::cin, reportsto);
}

// Методы класса HighFink
// Конструктор #1
HighFink::HighFink() : AbstrEmp(), Manager(), Fink() {}
// Конструктор #2
HighFink::HighFink(const std::string& fn, const std::string& ln, 
  const std::string& j, const std::string& rpo, int ico)
  : AbstrEmp(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}
// Конструктор #3
HighFink::HighFink(const AbstrEmp& e, const std::string& rpo, int ico)
  : AbstrEmp(e), Manager(e, ico), Fink(e, rpo) {}
// Конструктор #4
HighFink::HighFink(const Fink& f, int ico)
  : AbstrEmp(f), Manager(f, ico), Fink(f) {}
// Конструктор #5
HighFink::HighFink(const Manager& m, const std::string& rpo)
  : AbstrEmp(m), Manager(m), Fink(m, rpo) {}
// Конструктор #6
HighFink::HighFink(const HighFink& h)
  : AbstrEmp(h), Manager(h), Fink(h) {}
// Вывод всех данных
void HighFink::ShowAll() const
{
  AbstrEmp::ShowAll();
  std::cout << "In charge of: " << Manager::InChargeOf() << std::endl;
  std::cout << "Who output the reports: " << Fink::ReportsTo() << std::endl;
}
// Запрашивает данные у пользователя
void HighFink::SetAll()
{ 
  AbstrEmp::SetAll();
  std::cout << "In charge of: ";
  std::cin >> Manager::InChargeOf();
  std::cin.get();
  std::cout << "Enter who output the reports: ";
  getline(std::cin, Fink::ReportsTo());  
}