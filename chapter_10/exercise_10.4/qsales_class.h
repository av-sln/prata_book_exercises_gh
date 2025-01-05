// qsales_class.h -- определение класса Sales

#ifndef QSALES_CLASS_H_
#define QSALES_CLASS_H_

namespace SALES
{
  const int QUARTERS = 4;
  
  class Sales
  {
  private:
    double sales_[QUARTERS];
    double average_;
    double max_;
    double min_;
    double Average(const double sales[], const int n); 
    double MaxElement(const double sales[], const int n);
    double MinElement(const double sales[], const int n);

  public:
    // Конструктор по умолчанию
    Sales();

    // Конструктор с параметрами
    Sales(const double sales[], const int n);

    // Деструктор
    ~Sales() {}

    // Интерактивно подсчитывает продажи за 4 квартала, сохраняет их 
    // в члене sales_ объекта класса Sales, вычисляет и сохраняет среднее 
    // арифметическое, а также максимальное и минимальное значения
    // введённых чисел
    void SetSales();

    // Отображает всю информацию из объекта класса Sales
    void ShowSales() const;

  };
}


#endif