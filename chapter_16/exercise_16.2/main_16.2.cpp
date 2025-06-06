// main_16.2.cpp -- проверка на палиндром

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool palindrom(const std::string& rstr);


int main()
{
  std::string my_str;
  std::cout << "Enter a string <quit to quit>: ";
  while (std::getline(std::cin, my_str) && my_str != "quit") {
    if (palindrom(my_str))
      std::cout << "It's a palindrom.\n";
    else
      std::cout << "It isn't a palindrom.\n";
    std::cout << std::endl;
    std::cout << "Enter a string <quit to quit>: ";
  }
  std::cout << "Bye!\n";

  return 0;
}

bool palindrom(const std::string& rstr)
{
  std::string tmp1;
  std::string tmp2;
  bool flag;
  tmp1 = rstr;
  std::transform(tmp1.begin(), tmp1.end(), tmp1.begin(), tolower);
  tmp1.erase(std::remove_if(tmp1.begin(), tmp1.end(),
    [](char ch){return !isalpha(ch);}), tmp1.end());
  tmp2 = tmp1;
  std::reverse(tmp2.begin(), tmp2.end());
  std::cout << std::endl;
  std::cout << "Converted text: " << tmp1 << std::endl;
  std::cout << "Reversed text: " << tmp2 << std::endl;
  flag = (tmp1 == tmp2)? true : false;

  return flag;
}

