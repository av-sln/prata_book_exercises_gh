# Упражнение по программированию 13.3  
Перепишите иерархию классов `baseDMA-lacksDMA-hasDMA` таким образом, чтобы  
все три класса были порождены от абстрактного базового класса. Протестируйте  
результат с помощью программы, подобной приведённой в листинге 13.10. То есть  
она должна использовать массив указателей на абстрактный базовый класс и  
позволять пользователю принимать во время работы программы решения о том,  
объекты какого типа создавать. Добавьте в определения классов виртуальные  
методы `View()` для управления выводом данных.  

```cpp
// Класс baseDMA
class baseDMA {
private:
  char* label;
  int rating;

public:
  baseDMA(const char* l = "null", int r = 0);
  baseDMA(const baseDMA& rs);
  ~baseDMA();
  baseDMA& operator=(const baseDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

// Класс lacksDMA
class lacksDMA {
private:
  enum {COL_LEN = 40};
  char color[COL_LEN];

public:
  lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
  lacksDMA(const char* c, const baseDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

// Класс hasDMA
class hasDMA {
private:
  char* style;
  
public:
  hasDMA(const char* s = "none", const char* l = "null", int r = 0);
  hasDMA(const char* s, const baseDMA& rs);
  hasDMA(const hasDMA& hs);
  ~hasDMA();
  hasDMA& operator=(const hasDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};
```