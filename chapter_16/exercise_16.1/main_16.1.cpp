#include <iostream>
#include <string>
#include <algorithm>

bool palindrom(const std::string& rstr);

int main()
{
  std::string word;
  std::cout << std::endl;
  std::cout << "Enter a string <quit to quit>: ";
  std::getline(std::cin, word);
  
  while (word != "quit") {
    if(palindrom(word))
      std::cout << "It's a palindrom!\n";
    else
      std::cout << "It isn't a palindrom!\n";
    std::cout << "Enter a string <quit to quit>: ";
    std::getline(std::cin, word);
  }
  std::cout << "\nBye!\n";
  
  return 0;
}

bool palindrom(const std::string& rstr)
{
  bool flag;
  std::string tmp = rstr;
  std::reverse(tmp.begin(), tmp.end());
  if (tmp == rstr)
    flag = true;
  else 
    flag = false;

  return flag;
}