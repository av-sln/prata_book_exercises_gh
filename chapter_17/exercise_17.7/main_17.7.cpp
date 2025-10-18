// main_17.7.cpp
// Программа записи в файл и извленчения из файла объектов string
// в бинарном формате

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cstdlib>
#include "Store.hpp"

constexpr std::string fileName{"strings.dat"};

// Отображает строку на экране
void showStr(const std::string& stringRef) {
   std::cout << stringRef << std::endl;
}

// Считывает побайтно данные из файла
void GetStrs(std::ifstream& fileInputRef, 
   std::vector<std::string>& vectorRef) {
      std::size_t len{};
      std::string temp{};
      char ch;
      while (fileInputRef.peek() != EOF ) {
         fileInputRef.read((char*) &len, sizeof(std::size_t));
         for (std::size_t i{0}; i < len; ++i) {
            fileInputRef.read(&ch, sizeof(char));
            temp.push_back(ch);
         }
         vectorRef.push_back(temp);
         temp.clear();
      }
}

int main() {
   std::vector<std::string> vostr{};
   std::string temp{};

   std::cout << std::endl;
   // Получить строки
   std::cout << "Enter strings (empty line to quit):\n";
   // Продолжаем ввод пока не встретим пустую строку
   while (std::getline(std::cin, temp) && temp[0] != '\0') {
      vostr.push_back(std::move(temp));
   }

   // Вывод полученных строк
   std::cout << std::endl;
   std::cout << "Here is your input.\n";
   std::ranges::for_each(vostr, showStr);

   // Сохранить в файле
   std::ofstream fout(fileName, std::ios_base::out | std::ios_base::binary);
   std::ranges::for_each(vostr, Store(fout));
   fout.close();

   // Восстановить содержимое файла
   std::vector<std::string> vistr{};
   std::ifstream fin(fileName, std::ios_base::in | std::ios_base::binary);
   if (!fin.is_open()) {
      std::cerr << "Could not open file for input.\n";
      std::exit(EXIT_FAILURE);
   }

   GetStrs(fin, vistr); // Читаем строки из файла

   // Выводим строки прочитанные из файла
   std::cout << "\nHere are the strings read from the file:\n";
   std::ranges::for_each(vistr, showStr);
}