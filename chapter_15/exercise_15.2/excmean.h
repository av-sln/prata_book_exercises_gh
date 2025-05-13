// excmean.h -- классы исключений для hmean() и gmean()
#ifndef EXCMEAN_H_
#define EXCMEAN_H_
#include <string>
#include <stdexcept>

class bad_hmean : public std::logic_error {
public:
  explicit bad_hmean(const std::string& what_arg = 
    "Error is in hmean(). Invalid arguments a = -b.")
    : std::logic_error(what_arg) {}
};

class bad_gmean : public std::logic_error {
public:
  explicit bad_gmean(const std::string& what_arg = 
    "Error is in gmean(). Arguments should be >= 0")
    : std::logic_error(what_arg) {}
};

#endif  // excmean.h