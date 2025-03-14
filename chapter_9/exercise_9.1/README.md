# Упражнение по программированию 9.1  

Имеется следующий заголовочный файл:  

```cpp
    // golf.h -- для pe9-1.cpp
    const int Len  = 40;
    struct golf
    {
        char fullname[Len];
        int handicap;
    };

    // Неинтерактивная версия:
    // Функция присваивает структуре типа golf имя игрока и его гандикап (фору),
    // используя передаваемые ей аргументы
    void setgolf(golf& g, const char* name, int hc);

    // Интерактивная версия:
    // Функция предлагает полльзователю ввести имя и гандикап,
    // присваивает элементам структуры g введённые значения;
    // возвращает 1, если введено имя, и 0, если введена пустая строка
    int setgolf(golf& g);

    // Функция устанавливает новое значение гандикапа
    void handicap(golf& g, int hc);

    // Функция отображает содержимое структуры типа golf
    void showgolf(golf& g, int hc);
```  

Обратите внимание, что функция **setgolf()** перегружена. Вызов первой версии  
функции имеет следующий вид:

```cpp
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
```

Функция предоставляет информацию, которая содержится в структуре **ann**.  
Вызов второй версии функции имеет следующий вид:  

```cpp
    golf andy;
    setgolf(andy);
```

Функция предлагает пользователю ввести имя и гандикап, а затем сохраняет эти данные  
в структуре **andy**. Эта функция могла бы (но не обязательно) внутренне использовать  
первую версию.

Постройте многофайловую программу на основе этого заголовочного файла.  
Один файл по имени **golf.cpp** должен содержать определения функций, которые  
соответствуют прототипам заголовочного файла. Второй файл должен содержать  
функцию **main()** и обеспечивать реализцию всех средств прототипированных функций.  
Например, цикл должен запрашивать ввод массива структур типа **golf** и прекращать  
ввод после заполнения массива, либо когда вместо имени игрока в гольф пользователь  
вводит пустую строку. Чтобы получить доступ к структурам типа **golf**, функция **main()**  
должна использовать только прототипированные функции.
