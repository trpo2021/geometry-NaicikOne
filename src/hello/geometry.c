#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libhello/lib_calc_trans.h"
#include "../libhello/libmainchek.h"

int main()
{
    char ST[30];
    char* MARK = ST;
    char* MARK2 = ST;
    int D[3];
    char WR[] = {"circle"};

    fgets(ST, 30, stdin);

    if (mainchek(MARK, WR, MARK2) == 0) {
        system("pause");
        return 0;
    }
    translate(MARK, D);
    calculation(D);
    return 0;
}
