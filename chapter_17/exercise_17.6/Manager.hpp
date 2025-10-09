// Mahager.hpp
// Заголовочный файл производного класса Manager
#pragma once
#include <iostream>
#include <format>
#include <fstream>
#include "Abstremp.hpp"

class Manager : virtual public AbstrEmp
{
public:
   // Конструктор по умолчанию
   Manager() = default;
   // Выводит все данные
   void showAll() override;
   // Запрашивает значения у пользователя
   void setAll() override;
   // Записывает данные в файл
   void writeAll(std::ofstream& fileOutputRef) const override;
   // Считывает данные из файла
   void getAll(std::ifstream& fileInputRef) override;

protected:
   // set-функция
   int& setInChargeOf() {return m_inChargeOf;}
   // get-функция
   int getInChargeOf() const {return m_inChargeOf;}
   
private:
   int m_inChargeOf{0};
};

void Manager::showAll() {
   std::cout << AbstrEmp::toString()
      << "In charge of: " << getInChargeOf() << std::endl;
}

void Manager::setAll() {
   std::cout << "Enter Manager's name: ";
   std::getline(std::cin, AbstrEmp::setName());
   std::cout << "Enter Manager's last name: ";
   std::getline(std::cin, AbstrEmp::setLastName());
   std::cout << "Enter Manager's job: ";
   std::getline(std::cin, AbstrEmp::setJob());
   std::cout << "Enter in charge of: ";
   (std::cin >> setInChargeOf()).get();
}

void Manager::writeAll(std::ofstream& fileOutputRef) const {
   fileOutputRef << eManager << " "
      << AbstrEmp::getName() << " "
      << AbstrEmp::getLastName() << " "
      << AbstrEmp::getJob() << " "
      << getInChargeOf() << std::endl;
}

void Manager::getAll(std::ifstream& fileInputRef) {
   fileInputRef >> AbstrEmp::setName()
      >> AbstrEmp::setLastName()
      >> AbstrEmp::setJob();
   (fileInputRef >> setInChargeOf()).get();
}