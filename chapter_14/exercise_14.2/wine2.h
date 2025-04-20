// wine2.h -- объявление классов Pair и Wine

#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <valarray>
#include <string>

template<typename T1, typename T2>
class Pair {
private:
	T1 first_;
	T2 second_;

public:
	Pair(const T1& r_fst, const T2& r_scd)
		: first_(r_fst), second_(r_scd) {}
	Pair() {}
	T1& setfirst() { return first_; }
	T2& setsecond() { return second_; }
	T1 first() const { return first_; }
	T2 second() const { return second_; }
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray {
private:
	int years_;  
public:
	// Конструктор по умолчанию
	Wine();
	// Конструктор #1
	Wine(const char* p_lbl, int y, const int yr[], const int btl[]);
	// Конструктор #2
	Wine(const char* p_lbl, int y);
	// Деструктор
	~Wine() {}
	// Вводит год урожая и количество бутылок
	void GetBottles();
	// Возвращает название вина
	const std::string& Label() const;
	// Возвращает общее количество бутылок
	int Sum() const;
	// Вывод всех данных
	void Show() const;
};

#endif //wine.h