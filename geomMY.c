#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool search_brecket(char *MARK);
bool search_comma(char *MARK);
bool search_brecket2(char *MARK);
bool word_chek(char *WR, char *MARK);
int chek(char *MARK, int max, char *WR);
void calculation(double *);
void translate(char *MARK, double *D);

int main() {
  int max = 30;
  char str[max];
  char *MARK = str;
  char *MARK2 = str;
  double D[5];
  char WR[] = {"circle"};

  fgets(str, max, stdin);

  if (isalpha(*MARK) != 0) {
    while (isalpha(*MARK2) != 0)
      MARK2++;
  } //передвижение указателя на первую скобку

  if (chek(MARK, max, WR) == 0) {
    MARK = MARK2;
    printf("Correct\n");
  } else {
    printf("Uncorrect\n");
    system("pause");
    return 0;
  } // вывод сообщения о корректности запроса

  translate(MARK, D);
  calculation(D);

  return true;
}

void translate(char *MARK, double *X) {
  char *flag;
  double a;
  int i = 0;
  while (isdigit(*MARK) == 0) {
    MARK++;
    if (isdigit(*MARK) != 0) {
      a = strtod(MARK, &flag);
      X[i] = a;
      i++;
      MARK = flag;
      if (i == 3)
        break;
    } else {
      printf("expected '<double>'\n");
      system("pause");
      break;
    }
  }
} //преобразование чисел в строке в численный формат данных

void calculation(double *D) {
  float pi = 3.1415;
  float S;
  float P;
  P = 2 * pi * D[2];
  S = pi * pow(D[2], 2);
  printf("Perimetr = %f\n", P);
  printf("Area = %f\n", S);
  system("pause");
} // нахождение периметра и площади

int chek(char *MARK, int max, char *WR) {
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

bool search_brecket(char *MARK) {
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

bool search_brecket2(char *MARK) {
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

bool search_comma(char *MARK) {
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

bool word_chek(char *WR, char *MARK) {
  int s = 6;
  if (strncmp(WR, MARK, s) == 0) {
    return true;
  }
  printf("check the spelling of the word\n");
  return false;
} //проверка на написание слова "circle"
