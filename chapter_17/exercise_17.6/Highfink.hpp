// Highfink.hpp
// Заголовочный файла класса HighFink
#pragma once
#include <iostream>
#include <format>
#include <fstream>
#include "Manager.hpp"
#include "Fink.hpp"

class HighFink final : public Manager, public Fink
{
public:
   // Конструктор по умолчанию
   HighFink() = default;
   // Выводит все данные
   void showAll() override;
   // Запрашивает данные у пользователя
   void setAll() override;
   // Записывает данные в файл
   void writeAll(std::ofstream& fileOutputRef) const override;
   // Считывае данные из файла
   void getAll(std::ifstream& fileInputRef) override;
};

void HighFink::showAll() {
   std::cout << AbstrEmp::toString()
      << "In charge of: " << Manager::getInChargeOf()
      << "\nReports to: " << Fink::getReportsTo() << std::endl;
}

void HighFink::setAll() {
   std::cout << "Enter HighFink's name: ";
   std::getline(std::cin, AbstrEmp::setName());
   std::cout << "Enter HighFink's last name: ";
   std::getline(std::cin, AbstrEmp::setLastName());
   std::cout << "Enter HighFink's job: ";
   std::getline(std::cin, AbstrEmp::setJob());
   std::cout << "Enter in charge of: ";
   (std::cin >> Manager::setInChargeOf()).get();
   std::cout << "Enter reports to: ";
   std::getline(std::cin, Fink::setReportsTo());

}

void HighFink::writeAll(std::ofstream& fileOutputRef) const {
   fileOutputRef << eHighFink << " "
      << AbstrEmp::getName() << " "
      << AbstrEmp::getLastName() << " "
      << AbstrEmp::getJob() << " "
      << Manager::getInChargeOf() << " "
      << Fink::getReportsTo() << std::endl;
}

void HighFink::getAll(std::ifstream& fileInputRef) {
   fileInputRef >> AbstrEmp::setName()
      >> AbstrEmp::setLastName()
      >> AbstrEmp::setJob();
   fileInputRef >> setInChargeOf();
   std::getline(fileInputRef, Fink::setReportsTo());
}