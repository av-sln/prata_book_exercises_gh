# Проект класса String122  
Закрытые члены:  
  - указатель на строку;  
  - длина строки;  
  - количество объектов (статическая переменная);  
  - предел ввода для `cin` (статическая константа).    

Открытый интерфейс:  
  - конструктор по умолчанию;  
  - конструктор с аргументами;  
  - конструктор копирования;  
  - деструктор.  

Методы:  
  - длина строки;  
  - метод `stringlow()` - преобразование всех буквенных символов в строке  
    в нижний регистр;  
  - метод `stringup()` - преобразование всех буквенных символов в строке  
    в верхний регистр;  
  - метод `numchar()` - возвращает количество раз, которое символ появляется  
    в строке.  

Перегруженные операции:  
  - `operator+()` - объединяет две строки в одну;  
  - `operator=()` - присваивает объект объекту;  
  - `operator=()` - присваивает объекту строку в стиле С;  
  - `operator[]()` - чтение и запись отдельных символов в неконстантном  
    объекте `String`;  
  - `operator[]()` - доступ для чтения отдельных символов в константном  
    объекте `String`.  

Друзья:  
Сравнение строк:  
  - `operator<()`;  
  - `operator>()`;  
  - `operator==()`;  
  - `operator<<()` - вывод строки;  
  - `operator<<()` - ввод строки.  
  