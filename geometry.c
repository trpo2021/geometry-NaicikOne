#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_calc_trans.h"
#include "libmainchek.h"

int main()
{
    int max = 30;
    char str[max];
    char* MARK = str;
    char* MARK2 = str;
    double D[5];
    char WR[] = {"circle"};

    fgets(str, max, stdin);

    mainchek(MARK, max, WR, MARK2);
    translate(MARK, D);
    calculation(D);

    return 0;
}
