// static.cpp -- использование статической локальной переменной

#include <iostream>
#include <string>

// Прототип функции
void strcount(const std::string& str);

int main()
{
    std::string input;
    std::cout << std::endl;
    std::cout << "Enter a line:" << std::endl;
    getline(std::cin, input);
    while (input != "") {
        strcount(input);
        std::cout << "Enter next line (empty line to quit:)" << std::endl;
        getline(std::cin, input);
    }
    std::cout << "Bye" << std::endl;
    return 0;
}

void strcount(const std::string& str)
{
    static int total = 0;                   // статическая локальная переменная
    int count = 0;                          // автоматическая локальная переменная
    std::cout << "\"" << str << "\" contains ";
    count += str.size();
    total += count;
    std::cout << count << " characters" << std::endl;
    std::cout << total << " characters total" << std::endl;
}