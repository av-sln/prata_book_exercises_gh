// pe14-5.cpp
// useemp1.cpp -- использование классов AbstrEmp
#include <iostream>
#include "emp.h"
int main()
{
  Employee em("Trip", "Harris", "Thumper");
  std::cout << std::endl;
  std::cout << "Displaying the em object:\n";
  std::cout << em << std::endl;
  em.ShowAll();

  std::cout << std::endl;
  std::cout << "Displaying the ma object:\n";
  Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
  std::cout << ma << std::endl;
  ma.ShowAll();

  std::cout << std::endl;
  std::cout << "Displaying the fi object:\n"; 
  Fink fi("Matt", "Oggs", "Oiler", "Juno Bar");
  std::cout << fi << std::endl;
  fi.ShowAll();

  std::cout << std::endl;
  std::cout << "Displaying the hf object:\n";
  HighFink hf(ma, "Curly Kew");         // укомплектовано
  hf.ShowAll();

  std::cout << std::endl;
  std::cout << "Press a key for next phase:\n";
  std::cin.get();
  HighFink hf2;
  std::cout << "Setting the initial values of the hf2 object:\n";
  hf2.SetAll();

  std::cout << std::endl;
  std::cout << "Using an AbstrEmp* pointer:\n";
  AbstrEmp* tri[4] = {&em, &fi, &hf, &hf2};
  for (int i = 0; i < 4; ++i) {
    std::cout << std::endl;
    tri[i]->ShowAll();
  }  
  
  return 0;
}