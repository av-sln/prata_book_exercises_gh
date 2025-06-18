#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>

const std::string matFile = "mat.dat";
const std::string patFile = "pat.dat";
const std::string totFile = "matnpat.dat";

void menu();
void show(const std::string& rstr);

int main()
{
  char                     choice;
  std::string              temp;
  std::vector<std::string> matFriends;
  std::vector<std::string> patFriends;
  std::set<std::string>    totFriends;
  std::set<std::string>::iterator iter;
  std::ifstream fin;
  std::ofstream fout;
  std::cout << std::endl;
  menu();
  std::cout << "Your choice: ";
  while (std::cin >> choice && choice != 'q') {
    switch (choice) {
      // Друзья Мэт
      case 'a': fin.open(matFile);
                if (!fin.is_open()) {
                  std::cerr << "Could not open " << matFile << std::endl;
                  fin.clear();
                  break;
                }
                while (std::getline(fin, temp)) 
                  matFriends.push_back(temp);
                fin.clear();
                fin.close();
                std::sort(matFriends.begin(), matFriends.end());
                for (std::string x : matFriends) show(x);
                break;
      // Друзья Пэт
      case 'b': fin.open(patFile);
                if (!fin.is_open()) {
                  std::cerr << "Could not open " << patFile << std::endl;
                  fin.clear();
                  break;
                }
                while (std::getline(fin, temp))
                  patFriends.push_back(temp);
                fin.clear();
                fin.close();
                std::sort(patFriends.begin(), patFriends.end());
                for (std::string x : patFriends) show(x);
                break;
      // Общий список
      case 'c': fin.open(matFile);
                if (!fin.is_open()) {
                  std::cerr << "Could not open " << matFile << std::endl;
                  fin.clear();
                  break;
                }
                while (std::getline(fin, temp))
                  matFriends.push_back(temp);
                fin.clear();
                fin.close();
                totFriends.insert(matFriends.begin(), matFriends.end());
                fin.open(patFile);
                if (!fin.is_open()) {
                  std::cerr << "Could not open " << patFile << std::endl;
                  fin.clear();
                  break;
                }
                while (std::getline(fin, temp))
                  patFriends.push_back(temp);
                fin.clear();
                fin.close();
                totFriends.insert(patFriends.begin(), patFriends.end());
                for (std::string x : totFriends) show(x);
                fout.open(totFile);
                for (iter = totFriends.begin();
                  iter != totFriends.end(); ++iter) 
                  fout << *iter << std::endl;
                fout.close();
                break;                
                
      default: std::cout << "Incorrect choice! Try again.\n";
               menu();
               std::cout << "Your choice: ";
    }
    std::cout << "Your choice: ";
  }
  std::cout << "Bye!\n";

  return 0;
}

void menu()
{
  std::cout << "a. Display Mat's friends\tb. Display Pat's friends\n"
            << "c. Display total friends\tq. Quit\n";
}

void show(const std::string& rstr)
{
  std::cout << rstr << std::endl;
}
