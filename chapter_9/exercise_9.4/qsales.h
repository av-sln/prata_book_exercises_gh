// qsales.h -- заголовочный файл упражнения 9.4

#ifndef QSALES_H_
#define QSALES_H_

namespace SALES
{
  const int QUARTERS = 4;
  const int SIZE = 2;

  struct Sales
  {
    double sales[QUARTERS];
    double average_;
    double max_;
    double min_;
  };

  // Копирует меньшее значение из 4 или n элементов из массива ar в член
  // sales структуры s, вычисляет и сохраняет среднее арифметическое,
  // максимальное и минимальное значения введённых чисел;
  // оставшиеся элементы sales, если таковые есть, устанавливаются в 0
  void setSales(Sales& s, const double ar[], int n);

  // Интерактивно подсчитывает продажи за 4 квартала, сохраняет их в члене
  // sales структуры s, вычисляет и сохраняет среднее арифметическое, а также
  // максимальное и минимальное згачения введённых чисел
  void setSales(Sales& s);

  // Отображает всю информацию из структуры s
  void showSales(const Sales& s);
}

#endif