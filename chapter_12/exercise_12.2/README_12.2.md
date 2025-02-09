# Упражнение по программированию 12.2  

Усовершенствуйте объявление класса `String` (т.е. замените `string1.h` на  
`string2.h`), выполнив перечисленные ниже действия.  
  а. Перегрузите операцию `+` для объединения двух строк в одну.  
  б. Напишите функцию-член `stringlow()`, которая преобразует все буквенные  
     символы в строке в нижний регистр. (Не забудьте о семействе `cctype`  
     символьных функций).
  в. Напишите функцию-член `stringup()`, которая преобразует все буквенные  
     символы в строке в верхний регистр.  
  г. Напишите функцию-член, которая принимает аргумент типа `char` и возвращает  
     количество раз, которое символ появляется в строке.  

Проверьте работу полученного класса в следующей программе:  
```cpp
  // pe12_2.cpp
  #include <iostream>
  using namespace std;
  #include "string2.h"

  int main()
  {
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: "; // ввод имени
    String s3;
    cout << s2;           // перегруженная операция <<
    cin >> s3;            // перегруженная операция >>
    s2 = "My name is " + s3;  // перегруженные операции = и +
    cout << s2 << ". \n";
    s2 = s2 + s1;
    s2.stringup();    // преобразование строки в верхний регистр
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
         << " 'A' characters in it.\n";
    s1 = "red";       // String(const char *),
                      // тогда String& operator=(const String&)
    String rgb[3] = { String(s1), String("green"), String("blue") };
    cout << "Enter the name of a primary color for mixing light: "; 
    String ans;
    bool success = false;
    while (cin >> ans) {
      ans.stringlow();        // преобразование строки в нижний регистр
      for (int i = 0; i < 3; i++) {
        if (ans == rgb[i]) {    // перегруженная операция ==
        cout << "That`s right!\n";
        success = true;
        break;
        }
      }
      if (success)
        break;
      else
        cout << "Try again!\n";
    }
    cout << "Bye\n";

    return 0;
  }
  ```  
  Вывод программы должен выглядеть приблизительно так:  
  ```txt
    please enter your name: **Fretta Farbo**  
    My name is Fretta Farbo.  
    The string  
    MY NAME IS FRETTA FARBO AND I AM C++ STUDENT.  
    contains 6 'A' characters in it.  
    Enter the name of a primary color for mixing light: yellow  
    Try again!  
    **BLUE**  
    That's right!  
    Bye 
  ```  
  