#include "libmainchek.h"

bool search_brecket(char*);
bool search_comma(char*);
bool search_brecket2(char*);
bool word_chek(char*, char*);
int chek(char*, char*);
int mainchek(char*, char*, char*);

int mainchek(char* MARK, char* WR, char* MARK2)
{
    int ans = 1;
    if (isalpha(*MARK) != 0) {
        while (isalpha(*MARK2) != 0)
            MARK2++;
    } //передвижение указателя на первую скобку

    if (chek(MARK, WR) == 0) {
        MARK = MARK2;
        printf("Correct\n");
        return ans;
    } else {
        printf("Uncorrect\n");
        ans = 0;
        return ans;
    } // вывод сообщения о корректности запроса
}

int chek(char* MARK, char* WR)
{
    int res = 0;
    if (search_brecket(MARK) == 0) {
        res++;
    } //поиск '('
    if (search_brecket2(MARK) == 0) {
        res++;
    } //поиск ')'
    if (search_comma(MARK) == 0) {
        res++;
    } //поиск ','
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
