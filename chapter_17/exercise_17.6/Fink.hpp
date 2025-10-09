// Fink.hpp
// Заголовочный файл производного класса Fink
#pragma once
#include <iostream>
#include <format>
#include <fstream>
#include "Abstremp.hpp"

class Fink : virtual public AbstrEmp
{
public:
   // Конструктор по умолчанию
   Fink() = default;
   // Выводит все данные
   void showAll() override;
   // Запрашивает данные у пользователя
   void setAll() override;
   // Записывает данные в файл
   void writeAll(std::ofstream& fileOutputRef) const override;
   // Считывает данные из файла
   void getAll(std::ifstream& fileInputRef) override;

protected:
   // set-Функция
   std::string& setReportsTo() {return m_reportsTo;}
   // get-функция
   const std::string& getReportsTo() const {return m_reportsTo;}
   
private:
   std::string m_reportsTo{}; // Кому отправлять отчёты
};

void Fink::showAll() {
   std::cout << AbstrEmp::toString()
      << "Reports to : " << getReportsTo() << std::endl;
}

void Fink::setAll() {
   std::cout << "Enter Fink's name: ";
   std::getline(std::cin, AbstrEmp::setName());
   std::cout << "Enter Fink's last name: ";
   std::getline(std::cin, AbstrEmp::setLastName());
   std::cout << "Enter Fink's job: ";
   std::getline(std::cin, AbstrEmp::setJob());
   std::cout << "Enter Reports to: ";
   std::getline(std::cin, setReportsTo());
}

void Fink::writeAll(std::ofstream& fileOutputRef) const {
   fileOutputRef << eFink << " "
      << AbstrEmp::getName() << " "
      << AbstrEmp::getLastName() << " "
      << AbstrEmp::getJob() << " "
      << getReportsTo() << std::endl;
}

void Fink::getAll(std::ifstream& fileInputRef) {
   fileInputRef >> AbstrEmp::setName()
      >> AbstrEmp::setLastName()
      >> AbstrEmp::setJob();
   std::getline(fileInputRef, setReportsTo());
}