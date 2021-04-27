#include "libmainchek.h"

int mainchek(char* mark, char* wr)
{
    if (chek(mark, wr) == 0) {
        printf("Correct\n");
        return 0;
    } else {
        printf("Uncorrect\n");
        system("pause");
        return 1;
    } // вывод сообщения о корректности запроса
}

int chek(char* mark, char* wr)
{
    int res = 0;
    if (search_brecket(mark) == 0) { //поиск '('
        res++;
    }
    if (search_brecket2(mark) == 0) { //поиск ')'
        res++;
    }
    if (search_comma(mark) == 0) { //поиск ','
        res++;
    }
    if (word_chek(mark, wr) == 0) {
        res++;
    }
    return res;
} //массовая проверка верности запроса

bool search_brecket(char* mark)
{
    int flag = 0;

    while (*mark != 10) {
        if (*mark == '(') {
            flag = 1;
            break;
        }
        mark++;
    }
    if (flag == 0) {
        printf("expected '('\n");
        return false;
    }
    return true;
} //проверка на наличие "("

bool search_brecket2(char* mark)
{
    int flag = 0;

    while (*mark != 10) {
        if (*mark == ')') {
            flag = 1;
            break;
        }
        mark++;
    }
    if (flag == 0) {
        printf("expected ')'\n");
        return false;
    }
    return true;
} //проверка на наличие ")"

bool search_comma(char* mark)
{
    int flag = 0;

    while (*mark != 10) {
        if (*mark == ',') {
            flag = 1;
            break;
        }
        mark++;
    }
    if (flag == 0) {
        printf("expected ','\n");
        return false;
    }
    return true;
} //проверка на наличие ","

bool word_chek(char* wr, char* mark)
{
    int s = 6;
    if (strncmp(wr, mark, s) == 0) {
        return true;
    }
    printf("check the spelling of the word\n");
    return false;
} //проверка на написание слова "circle"
