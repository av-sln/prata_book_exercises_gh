#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char** argv)
{
  char ch;
  std::ifstream fin1;
  std::ifstream fin2;
  std::ofstream fout;
  fin1.open(argv[1]);
  fin2.open(argv[2]);
  fout.open(argv[3]);

  if (argc == 1 || argc == 2 || argc == 3){
    std::cerr << "Usage: " << argv[0] << " filename(s)\n";
    std::exit(EXIT_FAILURE);
  }

  if (!fin1.is_open()) {
    std::cerr << "Could not open " << argv[1] << std::endl;
    fin1.clear();
  }

  if (!fin2.is_open()) {
    std::cerr << "Could not open " << argv[2] << std::endl;
    fin2.clear();
  } 

  while (!fin1.eof() && !fin2.eof()) {
    while (fin1.get(ch) && ch != '\n') {
      fout << ch;
    }
    if (fin1.peek() != EOF)
      fout.put(' ');
    while (fin2.get(ch) && ch != '\n') {
      fout << ch;
    }
    fout.put('\n');
  }

  // Если один из файлов короче другого
  if (fin1.eof() && !fin2.eof()) {
    while (fin2.get(ch))
      fout << ch;
  } else if (!fin1.eof() && fin2.eof()) {
    fout.put('\b');
    while (fin1.get(ch)) 
      fout << ch;      
  }
  fin1.close();
  fin2.close();
  fout.close();

  std::cout << "Done!\n";

  return 0;
}
