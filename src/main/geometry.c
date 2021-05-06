#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/lib_calc_trans.h"
#include "lib/libmainchek.h"

int main()
{
    int max = 30;
    char str[max];
    char* mark = str;
    char* mark2 = str;
    int d[3];
    char wr[] = {"circle"};

    fgets(str, max, stdin);

    if (isalpha(*mark) != 0) {
        while (isalpha(*mark2) != 0)
            mark2++;
    } //передвижение указателя на первую скобку

    if (mainchek(mark, wr) == 1)
        return 0;
    else
        mark = mark2;

    translate(mark, d);
    calculation(d);

    return 0;
}
