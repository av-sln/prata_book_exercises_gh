// Store.hpp
// Заголовочный файл функционального объекта Store
#pragma once
#include <fstream>

class Store final {
public:
   explicit Store(std::ofstream& fileOutputRef) 
      : m_fileOutput{fileOutputRef} {}
   void operator()(const std::string& stringRef);
private:
   std::ofstream& m_fileOutput;
};

void Store::operator()(const std::string& stringRef) {
   std::size_t len{};
   len = stringRef.length();

   // Записываем длину строки 
   m_fileOutput.write((char*) &len, sizeof(std::size_t));
   // Записываем содержимое строки без нулевого символа
   m_fileOutput.write(stringRef.data(), len);  
   
}