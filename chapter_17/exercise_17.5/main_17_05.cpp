// main_17_05.cpp
#include <iostream>
#include <iterator>
#include <fstream>
#include <format>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Функция показывает пользовательское меню
void showMenu() {
   std::cout << "a. Display Mat's friends\tb. Display Pat's friends\n"
      << "c. Display total friends\tq. Quit\n";
}

// Функция считывает строки из файла помещает их в вектор
// и сортирует
void loadFriendsNamesToVector(const std::string& fileNameRef, 
   std::vector<std::string>& vectorNameRef) {
   std::ifstream fin{fileNameRef};
   if (!fin.is_open()) {
      std::cerr << std::format("Could not open {}\n", fileNameRef);
      std::exit(EXIT_FAILURE);
   }
   std::string line{};
   while (getline(fin, line)) {
      vectorNameRef.push_back(line);
   }
   std::ranges::sort(vectorNameRef);
   fin.close();
}

int main() {
   char choice;
   std::string fileName{};
   std::vector<std::string> mat{};
   std::vector<std::string> pat{};
   std::vector<std::string> matNpat{};
   std::ostream_iterator<std::string> output{std::cout, "\n"};
   std::cout << std::endl;
   showMenu();
   std::cout << "Enter your choice: ";
   while (std::cin >> choice && choice != 'q') {
      switch (choice) {
         // Друзья Mat
         case 'a':
            if (mat.empty()) {
               fileName = "mat.dat";
               loadFriendsNamesToVector(fileName, mat);
            }
            std::ranges::copy(mat, output);
            break;

         // Друзья Pat
         case 'b':
            if (pat.empty()) {
               fileName = "pat.dat";
               loadFriendsNamesToVector(fileName, pat);
            }
            std::ranges::copy(pat, output);
            break;

         // Общий список
         case 'c':
            if (matNpat.empty()) {
               if (mat.empty()) {
                  fileName = "mat.dat";
                  loadFriendsNamesToVector(fileName, mat);
               }
               if (pat.empty()) {
                  fileName = "pat.dat";
                  loadFriendsNamesToVector(fileName, pat);
               }
               std::ranges::merge(mat, pat, std::back_inserter(matNpat));
               auto [first, last]{std::ranges::unique(matNpat)};
               matNpat.erase(first, last);
               std::ofstream fout{"matNpat.dat"};
               std::ostream_iterator<std::string> foutput{fout, "\n"};
               std::ranges::copy(matNpat, foutput);
            }
            std::ranges::copy(matNpat, output);
            break;

         default:
            std::cout << "Incorrect choice! Try again.\n";
            showMenu();
            std::cout << "Enter your choice: ";         
      }  // switch
      std::cout << "Enter your choice: ";
   }  // while

   std::cout << "Bye!\n";
} // main