// Abstremp.hpp
// Заголовочный файл базового абстрактного класса Abstremp
#pragma once
#include <string>
#include <format>
enum ClassID {eEmployee, eManager, eFink, eHighFink};

class AbstrEmp
{
public:
   // Конструктор по умолчанию
   AbstrEmp() = default;
   // Деструктор
   virtual ~AbstrEmp() = default;
   // Выводит все данные
   virtual void showAll() = 0;
   // Запрашивает данные у пользователя
   virtual void setAll() = 0;
   // Записывает данные в файл
   virtual void writeAll(std::ofstream &fileOutputRef) const = 0;
   // Получает данные из файла
   virtual void getAll(std::ifstream& fileInputRef) = 0;

protected:
   // set-функции
   std::string& setName() {return m_name;}
   std::string& setLastName() {return m_lastName;}
   std::string& setJob() {return m_job;}
   // get-функции
   const std::string& getName() const { return m_name; }
   const std::string& getLastName() const { return m_lastName; }
   const std::string& getJob() const { return m_job; }
   // Преобразовать данные в строку
   std::string toString();

private:
   std::string m_name{};     // Имя
   std::string m_lastName{}; // Фамилия
   std::string m_job{};      // Должность
};

std::string AbstrEmp::toString() {
   return std::format("{} {}\nJob: {}\n",
      getName(), getLastName(), getJob());
}