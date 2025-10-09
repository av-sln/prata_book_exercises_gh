// main.cpp
// Тест-драйв классов AbstrEmp, Employee, Manager, Fink и HighFink
// используя файловый ввод-вывод
#include <iostream>
#include <deque>
#include <fstream>
#include <memory>
#include "Employee.hpp"
#include "Manager.hpp"
#include "Fink.hpp"
#include "Highfink.hpp"

void showMenu(std::deque<std::unique_ptr<AbstrEmp>>& dequeRef, 
   const std::string& fileNameRef) {
   std::cout << std::format("{:<40}{:<40}\n{:<40}{:<40}\n{:<40}{:<40}\n\n",
      "1. Create a new employee", "2. Create a new manager",
      "3. Create a new fink", "4. Create a new highfink",
      "5. Display List", "q. Quit");
   
   char ch{};
   std::unique_ptr<AbstrEmp> ptr;
   std::ofstream fileOutput;
   fileOutput.open(fileNameRef, std::ios_base::out | std::ios_base::app);
   std::cout << "Enter your choice: ";
   (std::cin >> ch).get();
   while (ch != 'q') {
      switch (ch) {
      case '1':
         ptr = std::make_unique<Employee>();
         break;
      case '2':
         ptr = std::make_unique<Manager>();
         break;
      case '3':
         ptr = std::make_unique<Fink>();
         break;
      case '4':
         ptr = std::make_unique<HighFink>();
         break;
      case '5':
         std::cout << std::endl;
         for (const auto &employee : dequeRef) {
            employee->showAll();
            std::cout << std::endl;
         }
         break;
      default:
         std::cout << "Incorrect choice. Try again!\n";
         std::cout << "Enter your choice: ";
      } // end switch
      if (ptr) {
         ptr->setAll();
         ptr->writeAll(fileOutput);
         dequeRef.push_back(std::move(ptr));
      }
      std::cout << "Enter your choice: ";
      (std::cin >> ch).get();
   } // end while
   fileOutput.close();
}  // end showMenu

const std::string fileName{"employees.dat"};

int main() {
   std::deque<std::unique_ptr<AbstrEmp>> employees{};
   int classId{};
   std::ifstream fileInput;
   fileInput.open(fileName, std::ios_base::in);
   if (!fileInput.is_open()) {   // Если файл не существует
      std::cout << "File not found.\n"
         << "You need create a new list of employees.\n\n";
      fileInput.close();
      fileInput.clear();
            
      showMenu(employees, fileName);
      
   }  // end if
   else {   // Если файл существует выгружаем данные в контейнер
      std::unique_ptr<AbstrEmp> ptr{};
      while (fileInput >> classId) {
         switch (classId) {
            case eEmployee:
               ptr = std::make_unique<Employee>();
               break;
            case eManager:
               ptr = std::make_unique<Manager>();
               break;
            case eFink:
               ptr = std::make_unique<Fink>();
               break;
            case eHighFink:
               ptr = std::make_unique<HighFink>();               
         }  // end switch
         ptr->getAll(fileInput);
         employees.push_back(std::move(ptr));
      }  // end while
      fileInput.close();
   }  // end else
   for (const auto& employee : employees) {
      employee->showAll();
      std::cout << std::endl;
   }

   showMenu(employees, fileName);
}