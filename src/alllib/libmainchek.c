#include "libmainchek.h"

int mainchek(char* MARK, char* WR)
{
    printf("mainchek work");
    system("pause");
    int ans = 1;
    if (chek(MARK, WR) == 0) {
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
    printf("chek work");
    system("pause");
    int res = 0;
    if (search_brecket(MARK) == 0) {
        res++;
        printf("1 breck work");
        system("pause");
    } //поиск '('
    if (search_brecket2(MARK) == 0) {
        res++;
        printf("1 breck work");
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

    while (*MARK != '\0') {
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

    while (*MARK != '\0') {
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

    while (*MARK != '\0') {
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
