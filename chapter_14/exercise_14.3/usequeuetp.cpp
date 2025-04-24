// usequeuetp.cpp -- использование шаблонного класса QueueTP

#include <iostream>
#include <cstring>
#include "queuetp.h"
#include "worker.h"

const int SIZE = 5;         // количество элементов в очереди

int main()
{
  QueueTP<Worker*> lolas(SIZE); 
  Worker* wr_in[SIZE];
  Worker* wr_out[SIZE];
  int ct;
  for (ct = 0; ct < SIZE; ++ct) {
    char choice;
    std::cout << "Enter the employee category:\n"
              << "w: waiter             s: singer\n"
              << "t: singing waiter     q: quit\n";
    std::cin >> choice;
    while (std::strchr("wstq", choice) == NULL) {
      std::cout << "Please enter a w, s, t, or q: ";
      std::cin >> choice;
    }
    if (choice == 'q')
      break;
    switch(choice) {
      case 'w': wr_in[ct] = new Waiter;
                break;
      case 's': wr_in[ct] = new Singer;
                break;
      case 't': wr_in[ct] = new SingingWaiter;
                break;
    }
    std::cin.get();
    wr_in[ct]->Set();
    lolas.enqueue(wr_in[ct]);
  }
  std::cout << std::endl;
  std::cout << "Queuecount = " << lolas.queuecount() << std::endl;
  std::cout << std::endl;
  std::cout << "\nHere is your staff:\n";
  int i;
  for (i = 0; i < ct; i++) {
    std::cout << std::endl;
    lolas.dequeue(wr_out[ct]);
    wr_out[ct]->Show();
    delete wr_in[i];    
  }
  
  std::cout << "Bye.\n";

  return 0;
}