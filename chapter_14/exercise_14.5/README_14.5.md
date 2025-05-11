# Упражнение по программированию 14.5  
Ниже приведено несколько объявлений классов:  
```cpp
// emp.h -- заголовочный файл для класса AbstrEmp и его дочерних классов  
#include <iostream>
#include <string>

class AbstrEmp {
private:
  std::string fname;        // имя AbstrEmp
  std::string lname;        // фамилия AbstrEmp
  std::string job;
public:
  AbstrEmp();
  AbstrEmp(const std::string& fn, const std::string& ln,
    const std::string& j);
  virtual void ShowAll() const;   // выводит все данные с именами
  virtual void SetAll();          // запрашивает значения у пользователя
  // Выводит только имя и фамилию
  friend std::ostream& operator<<(std::ostream& os, const AbstrEmp& e);
  virtual ~AbstrEmp() = 0;    // виртуальный базовый класс    
};

class Employee : public AbstrEmp {
public:
  Employee();
  Employee(const std::string& fn, const std::string& ln,
    const std::string& j);
  virtual void ShowAll() const;
  virtual void SetAll();
};

class Manager : virtual public AbstrEmp {
private:
  int inchargeof;       // количество управляемых AbstrEmp
protected:
  int InChargeOf() const { return inchargeof; }   // вывод
  int& InChargeOf() { return inchargeof; }        // ввод
public:
  Manager();
  Manager(const std::string& fn, const std::string& ln, 
    const std::string& j, int ico = 0);
  Manager(const AbstrEmp& e, int ico);
  Manager(const Manager& m);
  virtual void ShowAll() const;
  virtual void SetAll();
};

class Fink : virtual public AbstrEmp {
private:
  std::string reportsto;        // кому выводить отчёты
protected:
  const std::string ReportsTo() const { return reportsto; }
  std::string& ReportsTo() { return reportsto; }
public:
  Fink();
  Fink(const std::string& fn, const std::string& ln,
    const std::string& j, const std::string& rpo);
  Fink(const AbstrEmp& e, const std::string& rpo);
  Fink(const Fink& e);
  virtual void ShowAll() const;
  virtual void SetAll();
};

// Надзор за управляющими
class HighFink : public Manager, public Fink {
public:
  HighFink();
  HighFink(const std::string& fn, const std::string& ln,
    const std::string& j, const std::string& rpo, int ico);
  HighFink(const AbstrEmp& e, const std::string& rpo, int ico);
  HighFink(const Fink& f, int ico);
  HighFink(const Manager& m, const std::string& rpo);
  HighFink(const HighFink& h);
  virtual void ShowAll() const;
  virtual void SetAll();
}; 
```
Здесь в иерархии классов используется множественное наследование с виртуальлным  
базовым классом. Поэтому не забывайте о специальных правилах для списков  
инициализации в конструкторах. Обратите также внимание на наличие нескольких  
методов с защищённым доступом. Это упрощает код некоторых методов `HighFink`.  
(Например, если метод `HighFink::ShowAll()` просто вызывает `Fink::ShowAll()`  
и `Manager::ShowAll()`, то это приводит к двукратному вызову `AbstrEmp::ShowAll()`.)  
Реализуйте эти методы и протестируйте классы.  
Ниже приведена минимальная тестовая программа:
```cpp
// pe14-5.cpp
// useemp1.cpp -- использование классов AbstrEmp
#include <iostream>
using namespace std;
#include "emp.h"
int main()
{
  Employee em("Trip", "Harris", "Thumper");
  cout << em << endl;
  em.ShowAll();
  Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
  cout << ma << endl;
  ma.ShowAll();
  Fink fi("Matt", "Oggs", "Oiler", "Juno Bar");
  cout << fi << endl;
  fi.ShowAll();
  HighFink hf(ma, "Curly Kew");         // укомплектовано
  hf.ShowAll();
  cout << "Press a key for next phase:\n";
  cin.get();
  HighFink hf2;
  hf2.SetAll();
  cout << "Using an AbstrEmp* pointer:\n";
  AbstrEmp* tri[4] = {&em, &fi, &hf, &hf2};
  for (int i = 0; i < 4; ++i)
    tri[i]->ShowAll();
  return 0;
}
```
Почему не определена операция присваивания?  
Почему методы `ShowAll()` и `SetAll()` виртуальные?  
Почему класс `AbstrEmp` является виртуальным базовым классом?  
Почему в классе `HighFink` нет раздела данных?  
Почему достаточно только одной версии операции `operator<<()`?  
Что произойдёт, если код в конце программы модифицировать следующим образом:  
```cpp
AbstrEmp tri[4] = {em, fi, hf, hf2};
for (int i = 0; i < 4; ++i)
  tri[i].ShowAll();
``` 