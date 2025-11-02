// Cpmv.hpp -- variant 1
// Загловочный файл класса Cpmv вариант 1
#pragma once
#include <string>
#include <iostream>
#include <format>

class Cpmv final {
public:
   static int objectNum;
   struct Info {
      std::string m_qcode{"none"};
      std::string m_zcode{"none"};
   };
   // Методы класса
   // Конструктор по умолчанию
   Cpmv();
   // Конструктор с аргументами
   Cpmv(const std::string& qcode, const std::string& zcode);
   // Копирующий конструктор
   Cpmv(const Cpmv& originalRef);
   // Перемещающий конструктор
   Cpmv(Cpmv&& originalRef) noexcept;
   // Деструктор
   ~Cpmv();
   // Оператор копирующего присваивания
   Cpmv& operator=(const Cpmv& rightRef);
   // Оператор перемещающего присваивания
   Cpmv& operator=(Cpmv&& rightRef) noexcept;
   // Операция конкатенации
   Cpmv operator+(const Cpmv& objectTwoRef) const;
   // Отобразить объект
   void Display() const;
private:
   int m_objectNum;
   Info* piPtr{nullptr};
};

// Инициализация статической переменной
int Cpmv::objectNum{0};

// Конструктор по умолчанию
Cpmv::Cpmv() 
   : m_objectNum{++objectNum}, piPtr{new Info} {
   std::cout << "***Default constuctor started***\n"
      << "Object_" << m_objectNum << " created.\n";      
}

// Конструктор с аргументами
Cpmv::Cpmv(const std::string& qcode, const std::string& zcode) 
   : m_objectNum{++objectNum}, piPtr{new Info{qcode, zcode}} {
   std::cout << "***Constructor with arguments started***\n"
      << "Object_" << m_objectNum << " created.\n";
}

// Копирующий конструктор
Cpmv::Cpmv(const Cpmv& originalRef) 
   : m_objectNum{++objectNum}, piPtr{new Info{originalRef.piPtr->m_qcode, 
   originalRef.piPtr->m_zcode}} {
   std::cout << "***Copy constructor started***\n"
      << "Object_" << m_objectNum << " created.\n";
}

// Оператор копирующего присваивания
Cpmv& Cpmv::operator=(const Cpmv& rightRef) {
   std::cout << "***Copy assignment operator started***\n";
   if (this != &rightRef) {
      delete piPtr;
      piPtr = new Info{rightRef.piPtr->m_qcode, rightRef.piPtr->m_zcode};
   }
   return *this;
}

// Перемещающий конструктор
Cpmv::Cpmv(Cpmv&& originalRef) noexcept
   : m_objectNum{++objectNum} {
   std::cout << "***Move constructor started***\n"
      << "Object_" << m_objectNum << " created.\n";
   piPtr = originalRef.piPtr;
   originalRef.piPtr = nullptr;
}

// Оператор перемещающего присваивания
Cpmv& Cpmv::operator=(Cpmv&& rightRef) noexcept {
   std::cout << "***Move assignment operator started***\n";
   if (this != &rightRef) {
      delete piPtr;
      piPtr = rightRef.piPtr;
      rightRef.piPtr = nullptr;
   }
   return *this;
}

// Деструктор
Cpmv::~Cpmv() {
   std::cout << "***Destructor started***\n"
      << "Object_" << m_objectNum << " deleted.\n";
   delete piPtr;
}

// Отобразить объект
void Cpmv::Display() const {
   std::cout << std::format("Argument qcode: {}\nArgument zcode: {}\n",
      piPtr->m_qcode, piPtr->m_zcode);
}

// Операция конкатенации
Cpmv Cpmv::operator+(const Cpmv& objectTwoRef) const {
   std::cout << "***Operator+() started***\n";
   // Получаем значения аргументов нового объекта
   std::string qcodeTmp = piPtr->m_qcode + objectTwoRef.piPtr->m_qcode;
   std::string zcodeTmp = piPtr->m_zcode + objectTwoRef.piPtr->m_zcode;
   // Вызываем конструктор с аргументами
   Cpmv temp{qcodeTmp, zcodeTmp};
   return temp;
}