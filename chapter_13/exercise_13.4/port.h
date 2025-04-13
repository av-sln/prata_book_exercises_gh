// port.h -- объявление класса Port

#ifndef PORT_H_
#define PORT_H_

#include <iostream>

class Port {                   // портвейн

private:
  char* brand_;                // бренд
  char  style_[20];            // например, tawny (золотистый),
                               // ruby (рубиновый), vintage (марочный)
  int   bottles_;              // количество бутылок

protected:
  int bottleCount() const { return bottles_; }

public:
  Port(const char* p_brd = "none", const char* p_stl = "none", int btl = 0);
  Port(const Port& r_prt);
  virtual ~Port() { delete [] brand_; }
  Port& operator=(const Port& r_prt);
  Port& operator+=(int btl);     // добавляет b к bottles
  Port& operator-=(int btl);     // вычитает b из bottles, если это возможно
  virtual void show() const;
  friend std::ostream& operator<<(std::ostream& r_os, const Port& r_prt);
};

#endif // port.h