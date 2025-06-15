#include <iostream>

int main()
{
  int count = 0;
  char ch;
  std::cout << "Enter a line:\n";
  while (std::cin.peek() != '$') {
    count++;
    std::cin.get(ch);
    std::cout << ch;
  }
  if (!std::cin.eof()) {
    std::cin.get(ch);
    std::cout << std::endl << ch << " is next input character.\n";
    std::cout << "All characters  = " << count << std::endl;
  } else {
    std::cout << "All characters = " << count << std::endl;
    std::cout << "End of file reached.\n";
  } 

  return 0;
}