// usevect_11.3.cpp -- использование класса Vector

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.hpp"

int maxSteps(int* ar, int n);
int minSteps(int* ar, int n);
double averageSteps(int* ar, int n);

int main()
{
  // Устанавливаем случайное значение для генератора случайных чисел
  srand(time(0));
  // Определяем переменные
  double direction;       // направление движения
  double target;          // расстояние
  double dstep;           // длина шага
  int N;          // количество попыток
  int steps;      // счётчик шагов
  VECTOR::Vector step;
  VECTOR::Vector result;

  // Ввод начальных значений
  std::cout << "Введите дистанцию: ";
  std::cin >> target;
  std::cout << "Введите длину шага: ";
  std::cin >> dstep;
  std::cout << "Введите количество попыток N = ";
  std::cin >> N;
  int* p_ar_steps = new int[N];     // массив попыток 
  for (int i = 0; i < N; i++) {
    steps = 0;
    while (result.magval() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, VECTOR::Vector::POL);
      result = result + step;
      steps++;
    }
    p_ar_steps[i] = steps;
    result.reset(0.0, 0.0);
  }

  // Тестовый вывод
  std::cout << std::endl;
  std::cout << "Массив количества шагов:\n";
  for (int i = 0; i < N; i++)
    std::cout << p_ar_steps[i] << ", ";
  std::cout << "\b\b" << ";" << std::endl;

  // Вывод результатов
  std::cout << std::endl;
  std::cout << "Мксимальное количество шагов из " << N << " попыток: " 
            << maxSteps(p_ar_steps, N) << " шагов.\n";
  std::cout << "Минимальное количество шагов из " << N << " попыток: "
            << minSteps(p_ar_steps, N) << " шагов.\n";
  std::cout << "Среднее кооличество шагов из " << N << " попыток: "
            << averageSteps(p_ar_steps, N) << " шагов.\n";

  delete [] p_ar_steps;

  return 0;
}

int maxSteps(int* ar, int n)
{
  int maxel = ar[0];
  for (int i = 0; i < n; i++)
    if (maxel < ar[i])
      maxel = ar[i];
  
  return maxel;
}

int minSteps(int* ar, int n)
{
  int minel = ar[0];
  for (int i = 0; i < n; i++)
    if (minel > ar[i])
      minel = ar[i];

  return minel;
}

double averageSteps(int* ar, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += ar[i];
  double average = sum / n;

  return average;
}