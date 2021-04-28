#include "lib_calc_trans.h"

void translate(char* mark, double* d)
{
    int i = 0, a = 0;
    char ch[12];
    while ((int)*mark != 41) {
        while ((int)*mark < 48 || (int)*mark > 57) {
            mark++;
        }
        while ((int)*mark != 32 && (int)*mark != 44 && (int)*mark != 41) {
            ch[i] = *mark;
            i++;
            mark++;
        }

        d[a] = atoi(ch);
        i = 0;
        a++;
    }
} //преобразование чисел в строке в численный формат данных

void calculation(double* d)
{
    float pi = 3.1415;
    float s;
    float p;
    p = 2 * pi * d[2];
    s = pi * pow(d[2], 2);
    printf("Perimetr = %f\n", p);
    printf("Area = %f\n", s);
} // нахождение периметра и площади

int figure_chek(double* d1, double* d2)
{
    if (d1[0] == d2[1] && d1[1] == d2[1] && d1[2] == d2[2]) {
        printf("the circles have the same coordinates, and the same radius");
        return 0;
    }
    return 0;
}
