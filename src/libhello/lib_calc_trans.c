#include "lib_calc_trans.h"

void calculation(double*);
int translate(char*, double*);

int translate(char* MARK, double* D)
{
    char* flag;
    double A;
    int i = 0;
    while (isdigit(*MARK) == 0) {
        MARK++;
        if (isdigit(*MARK) != 0) {
            A = strtod(MARK, &flag);
            D[i] = A;
            i++;
            MARK = flag;
            if (i == 3) {
                break;
            } else {
                printf("expected '<double>'\n");
                system("pause");
                return 0;
            }
        }
    }
} //преобразование чисел в строке в численный формат данных

void calculation(double* D)
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
