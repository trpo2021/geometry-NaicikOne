#include "lib_calc_trans.h"

int translate(char* MARK, int* D)
{
    while (isalpha(*MARK) != 0) {
        MARK++;
    }
    MARK++;
    char num[1];
    int i = 0;
    while (i != 3) {
        *num = *(MARK + i);
        D[i] = atoi(num);
        i++;
    }
    return 0;
} //преобразование чисел в строке в численный формат данных

void calculation(int* D)
{
    float pi = 3.1415;
    float S;
    float P;
    P = 2 * pi * D[2];
    S = pi * pow(D[2], 2);
    printf("Perimetr = %f\n", P);
    printf("Area = %f\n", S);
    system("pause");
} // нахождение периметра и площади
