#include "libmainchek.h"

bool search_brecket(char* MARK);
bool search_comma(char* MARK);
bool search_brecket2(char* MARK);
bool word_chek(char* WR, char* MARK);
int chek(char* MARK, int max, char* WR, char* MARK2);
int mainchek(char* MARK, int max, char* WR, char* MARK2);

int mainchek(char* MARK, int max, char* WR, char* MARK2)
{
    int res;
    res = chek(MARK, max, WR, MARK2);
    if (res == 0) {
        MARK = MARK2;
        printf("Correct\n");
    } else {
        printf("Uncorrect\n");
        return 0;
    } // вывод сообщения о корректности запроса
}

int chek(char* MARK, int max, char* WR, char* MARK2)
{
    if (isalpha(*MARK) != 0) {
        while (isalpha(*MARK2) != 0)
            *MARK2++;
    } //передвижение указателя на первую скобку

    int res = 0;
    if (search_brecket(MARK) == 0) { //поиск '('
        res++;
    }
    if (search_brecket2(MARK) == 0) { //поиск ')'
        res++;
    }
    if (search_comma(MARK) == 0) { //поиск ','
        res++;
    }
    if (word_chek(MARK, WR) == 0) {
        res++;
    }
    return res;
} //массовая проверка верности запроса

bool search_brecket(char* MARK)
{
    int flag = 0;

    while (*MARK != 10) {
        if (*MARK == '(') {
            flag = 1;
            break;
        }
        MARK++;
    }
    if (flag == 0) {
        printf("expected '('\n");
        return false;
    }
    return true;
} //проверка на наличие "("

bool search_brecket2(char* MARK)
{
    int flag = 0;

    while (*MARK != 10) {
        if (*MARK == ')') {
            flag = 1;
            break;
        }
        MARK++;
    }
    if (flag == 0) {
        printf("expected ')'\n");
        return false;
    }
    return true;
} //проверка на наличие ")"

bool search_comma(char* MARK)
{
    int flag = 0;

    while (*MARK != 10) {
        if (*MARK == ',') {
            flag = 1;
            break;
        }
        MARK++;
    }
    if (flag == 0) {
        printf("expected ','\n");
        return false;
    }
    return true;
} //проверка на наличие ","

bool word_chek(char* WR, char* MARK)
{
    int s = 6;
    if (strncmp(WR, MARK, s) == 0) {
        return true;
    }
    printf("check the spelling of the word\n");
    return false;
} //проверка на написание слова "circle"
