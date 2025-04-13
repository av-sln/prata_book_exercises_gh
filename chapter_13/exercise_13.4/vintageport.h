// vintageport.h -- объявление производного класса VintagePort

#ifndef VINTAGEPORT_H_
#define VINTAGEPORT_H_
#include <iostream>
#include "port.h"

class VintagePort : public Port   // style обязательно = "vintage"
{
private:
  char* nickname_;                // т.е. "The Noble", "Old Velvet" и т.д.
  int   year_;                    // год сбора

public:
  VintagePort();
  VintagePort(const char* p_brd, int btl, const char* p_nn, int yr);
  VintagePort(const VintagePort& r_vp);
  ~VintagePort() { delete [] nickname_; }
  VintagePort& operator=(const VintagePort& r_vp);
  virtual void show() const;
  friend std::ostream& operator<<(std::ostream& r_os, const VintagePort& r_vp);
};

#endif // vintageport.h