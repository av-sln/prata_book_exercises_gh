#include <iostream>
#include <cstdlib>
#include <fstream>

int main( int argc, char** argv)
{
  char ch;
  if (argc == 1) {
    std::cerr << "Usage: " << argv[0] << " filename(s)\n";
    std::exit(EXIT_FAILURE);
  }
  std::ofstream fout;
  fout.open(argv[1]);
  
  std::cout << "Enter a line:\n";
  while (std::cin.get(ch) && ch != EOF)
    fout << ch;
  fout.close();
  
  return 0;
}