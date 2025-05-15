// error153.h -- заголовочный файла исключений logic_error
#ifndef ERROR153_H_
#define ERROR153_H_
#include <iostream>
#include <string>
#include <stdexcept>

class bad_hmean : public std::invalid_argument {
private:
  double arg1;
  double arg2;
public:
  explicit bad_hmean(const std::string& what_arg, double a = 0.0, double b = 0.0)
    : std::invalid_argument(what_arg), arg1(a), arg2(b) {}
  void show() const;
};

class bad_gmean : public std::invalid_argument {
private:
  double arg1;
  double arg2;
public:
  explicit bad_gmean(const std::string& what_arg, double a = 0.0, 
    double b = 0.0)
    : std::invalid_argument(what_arg), arg1(a), arg2(b) {}
  void show() const;
};

// Встроенный метод bad_hmean
inline void bad_hmean::show() const
{
  std::cout << "Funtion is hmean(): argument 1 = " << arg1 << ", "
            << "argument 2 = " << arg2 << std::endl;
}

// Встроенный метод bad_gmean
inline void bad_gmean::show() const
{
  std::cout << "Function is gmean(): argument 1 = " << arg1 << ", "
            << "argument 2 = " << arg2 << std::endl;
}

#endif  // error153.h