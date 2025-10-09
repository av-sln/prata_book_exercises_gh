// Employee.h
// Заголовочный файл для AbstrEmp и его производных классов
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Abstremp.hpp"

class Employee final : public AbstrEmp {
public:
   // Конструктор по умолчанию
   Employee() = default;
   // Выводит все данные
   void showAll() override;
   // Запрашивает значения у пользователя
   void setAll() override;
   // Записывает данные в файл
   void writeAll(std::ofstream& fileOutputRef) const override;
   // Считывает данные из файла
   void getAll(std::ifstream& fileInputRef) override;
};

void Employee::showAll() {
   std::cout << AbstrEmp::toString();
}

void Employee::setAll() {
   std::cout << "Enter Employee's name: ";
   std::getline(std::cin, AbstrEmp::setName());
   std::cout << "Enter Employee's last name: ";
   std::getline(std::cin, AbstrEmp::setLastName());
   std::cout << "Enter Employee's job: ";
   std::getline(std::cin, AbstrEmp::setJob());
}

void Employee::writeAll(std::ofstream& fileOutputRef) const {
   fileOutputRef << eEmployee << " "
      << AbstrEmp::getName() << " "
      << AbstrEmp::getLastName() << " "
      << AbstrEmp::getJob() << std::endl;
}

void Employee::getAll(std::ifstream& fileInputRef) {
   fileInputRef >> AbstrEmp::setName()
      >> AbstrEmp::setLastName();
   std::getline(fileInputRef, AbstrEmp::setJob());
}