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
    char st1[30];
    char st2[30];
    char* mark;
    char* mark2;
    int d[3];
    char wr[] = {"circle"};
    printf("enter first circle:\n");
    fgets(st1, 30, stdin);
    mark = st1;
    mark2 = st1;
    puts(st1);
    system("pause");

    system("cls");
    printf("For first circle:\n");
    if (mainchek(mark, wr) == 0) {
        system("pause");
        return 0;
    }
    printf("work\n");
    translate(mark, d);
    calculation(d);

    printf("Go to the calculation of the second circle? 1 - yes, 2 - no");
    int answer;
    scanf("%d", answer);
    if (answer == 2) {
        printf("thank you for using the program");
        system("pause");
        return 0;
    }
    printf("work");
    system("pause");
    return 0;
}
