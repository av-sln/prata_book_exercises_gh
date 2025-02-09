# Упражнение по программированию 12.1  

Имеется следующее объявление класса:  
```cpp  
  class Cow
  {
    char name[20];
    char *hobby;
    double weight;

  public:
    Cow();
    Cow(const char *nm, const char *ho, double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow& operator=(const Cow &c);
    void ShowCow() const; // отображение всех данных Cow
  };
```  
Напишите реализацию для этого класса и короткую программу, использующую все  
функции-члены.
