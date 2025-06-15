#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char** argv)
{
  if (argc == 1) {
    std::cerr << "Usage: " << argv[0] << " filename(s).\n";
    std::exit(EXIT_FAILURE);
  }
  char ch;
  std::ofstream fout;
  std::ifstream fin;
  fin.open(argv[1]);
  if (!fin.is_open()) {
    std::cerr << "Could not open " << argv[1] << std::endl;
    fin.clear();
  }
  fout.open(argv[2]);
  while (fin.get(ch))
    fout << ch;
  fin.clear();
  fin.close();
  fout.close();

  return 0;
}