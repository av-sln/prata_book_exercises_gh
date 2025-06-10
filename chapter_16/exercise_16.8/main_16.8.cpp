// main_16.8.cpp -- использование STL
#include <iostream>
#include <string>
#include <set>

void setFriends(std::set<std::string>& rset);
void show(const std::string& rstr);

int main()
{
  // Создаём контейнеры друзей
  std::set<std::string> matFriends;
  std::set<std::string> patFriends;
  std::set<std::string> totalFriens;

  // Ввод списка друзей
  std::cout << std::endl;
  std::cout << "Enter Mat's friends:\n";
  setFriends(matFriends);
  std::cout << std::endl;
  std::cout << "Enter Pat's friends:\n";
  setFriends(patFriends);

  // Вывод списков друзей
  std::cout << std::endl;
  std::cout << "Mat's friends:\n";
  for (std::string x : matFriends) show(x);
  std::cout << "\b\b;\n\n";
  std::cout << "Pat's friends:\n";
  for (std::string x : patFriends) show(x);
  std::cout << "\b\b;\n\n";
  totalFriens.insert(begin(matFriends), end(matFriends));
  totalFriens.insert(begin(patFriends), end(patFriends));
  std::cout << "Total friends:\n";
  for (std::string x : totalFriens) show(x);
  std::cout << "\b\b;\n";
  std::cout << "Bye!\n";

  return 0;  
}

void show(const std::string& rstr)
{
  std::cout << rstr << ", ";
}

void setFriends(std::set<std::string>& rset)
{
  std::string temp;
  std::cout << "Enter your friend's name <quit to quit>: ";
  while (std::getline(std::cin, temp) && temp != "quit") {
    rset.insert(temp);
    std::cout << "Enter your next friend's name <quit to quit>: ";
  }
  std::cout << "Done!\n";
}

