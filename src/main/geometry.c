#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../alllib/lib_calc_trans.h"
#include "../alllib/libmainchek.h"

int main()
{
    char ST1[30];
    char ST2[30];
    char* MARK;
    char* MARK2;
    int D[3];
    char WR[] = {"circle"};
    printf("enter first circle:\n");
    scanf("%s", &ST1);
    MARK = ST1;
    MARK2 = ST1;
    printf("enter second circle:\n");
    scanf("%s", &ST2);

    system("cls");
    printf("For first circle:");
    if (mainchek(MARK, WR, MARK2) == 0) {
        system("pause");
        return 0;
    }
    translate(MARK, D);
    calculation(D);

    printf("Go to the calculation of the second circle? 1 - yes, 2 - no");
    int answer;
    scanf("%d", answer);
    if (answer == 2) {
        printf("thank you for using the program");
        system("pause");
        return 0;
    }

    system("cls");
    printf("For second circle:");
    MARK = ST2;
    MARK2 = ST2;
    if (mainchek(MARK, WR, MARK2) == 0) {
        system("pause");
        return 0;
    }
    translate(MARK, D);
    calculation(D);
    return 0;
}
