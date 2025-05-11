// emp.h -- заголовочный файл для класса AbstrEmp и его дочерних классов  
#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class AbstrEmp {
private:
  std::string fname;        // имя AbstrEmp
  std::string lname;        // фамилия AbstrEmp
  std::string job;
public:
  // Конструктор #1
  AbstrEmp();
  // Конструктор #2
  AbstrEmp(const std::string& fn, const std::string& ln,
    const std::string& j);
  // Выводит все данные с именами
  virtual void ShowAll() const;
  // Запрашивает значения у пользователя
  virtual void SetAll();
  // Выводит только имя и фамилию
  friend std::ostream& operator<<(std::ostream& os, const AbstrEmp& e);
  virtual ~AbstrEmp() = 0;    // чистая виртуальная функция    
};

class Employee : public AbstrEmp {
public:
  // Конструктор #1
  Employee();
  // Конструктор #2
  Employee(const std::string& fn, const std::string& ln,
    const std::string& j);
  // Выводит все данные
  virtual void ShowAll() const;
  // Запрашивает значения у пользователя
  virtual void SetAll();
};

class Manager : virtual public AbstrEmp {
private:
  int inchargeof;       // количество управляемых AbstrEmp
protected:
  int InChargeOf() const { return inchargeof; }   // вывод
  int& InChargeOf() { return inchargeof; }        // ввод
public:
  // Конструктор #1
  Manager();
  // Конструктор #2
  Manager(const std::string& fn, const std::string& ln, 
    const std::string& j, int ico = 0);
  // Конструктор #3
  Manager(const AbstrEmp& e, int ico);
  // Конструктор #4
  Manager(const Manager& m);
  // Вывод всех данных
  virtual void ShowAll() const;
  // Запрашивает значения у пользователя
  virtual void SetAll();
};

class Fink : virtual public AbstrEmp {
private:
  std::string reportsto;        // кому выводить отчёты
protected:
  const std::string ReportsTo() const { return reportsto; }
  std::string& ReportsTo() { return reportsto; }
public:
  // Конструктор #1
  Fink();
  // Конструктор #2
  Fink(const std::string& fn, const std::string& ln,
    const std::string& j, const std::string& rpo);
  // Конструктор #3
  Fink(const AbstrEmp& e, const std::string& rpo);
  // Конструктор #4
  Fink(const Fink& e);
  // Вывод всех данных
  virtual void ShowAll() const;
  // Запрашивает значения у пользователя
  virtual void SetAll();
};

// Надзор за управляющими
class HighFink : public Manager, public Fink {
public:
  // Конструктор #1
  HighFink();
  // Конструктор #2
  HighFink(const std::string& fn, const std::string& ln,
    const std::string& j, const std::string& rpo, int ico);
  // Конструктор #3
  HighFink(const AbstrEmp& e, const std::string& rpo, int ico);
  // Конструктор #4
  HighFink(const Fink& f, int ico);
  // Конструктор #5
  HighFink(const Manager& m, const std::string& rpo);
  // Конструктор #6
  HighFink(const HighFink& h);
  // Вывод всех данных
  virtual void ShowAll() const;
  // Запрашивает данные у пользователя
  virtual void SetAll();
}; 

#endif  // emp.h