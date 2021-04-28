#include "../lib/libmainchek.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char wr[] = {"circle"};
    char true_test[30];
    char false_test[30];
    fgets(true_test, 30, stdin);
    fgets(false_test, 30, stdin);
    char* t_mark = true_test;
    char* f_mark = false_test;
    printf("word_chek:\n");
    if (word_chek(wr, t_mark) == 1) {
        printf("correct test word_chek\n");
    }
    if (word_chek(wr, f_mark) == 1) {
        printf("correct test word_chek\n");
    }
    printf("\n\n");
    printf("search_breckets:\n");
    if (search_breckets(t_mark) == 1) {
        printf("correct test search_breckets\n");
    }
    if (search_breckets(f_mark) == 1) {
        printf("correct test search_breckets\n");
    }
    printf("\n\n");
    printf("search_comma:\n");
    if (search_comma(t_mark) == 1) {
        printf("correct test search_comma\n");
    }
    if (search_comma(f_mark) == 1) {
        printf("correct test search_comma\n");
    }
    system("pause");
}
