// classic.h -- производный класс от Cd

#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd {
private:
  char favorite[100];

public:
  Classic(const char* pf, const char* ps1, const char* ps2,
    int n, double x);
  Classic();
  virtual void Report() const;
  virtual Classic& operator=(const Classic& rcd);
};

#endif