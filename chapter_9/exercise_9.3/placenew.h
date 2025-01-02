// placenew.h -- заголловочный файл для упражнения 9.3

#ifndef PLACENEW_H_
#define PLACENEW_H_

const int ArSize = 2;
const int BUF = 512;

struct chaff
{
    char dross[20];
    int slag;
};

// Присваивает значения членам структуры
void setstruct(chaff* p_st, char* str, int n);

// Отображает содержимое структуры
void showstruct(const chaff* p_st);

#endif