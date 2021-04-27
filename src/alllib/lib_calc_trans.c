#include "lib_calc_trans.h"

int translate(char* mark, int* d)
{
    while (isalpha(*mark) != 0) {
        mark++;
    }
    mark++;
    char num[1];
    int i = 0;
    while (i != 3) {
        *num = *(mark + i);
        d[i] = atoi(num);
        i++;
    }
    return 0;
} //преобразование чисел в строке в численный формат данных

void calculation(int* d)
{
    float pi = 3.1415;
    float s;
    float p;
    p = 2 * pi * d[2];
    s = pi * pow(d[2], 2);
    printf("Perimetr = %f\n", p);
    printf("Area = %f\n", s);
    system("pause");
} // нахождение периметра и площади
