#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool search_brecket(char *cursor);  //поиск '('
bool search_comma(char *cursor);    //поиск ','
bool search_brecket2(char *cursor); //поиск ')'
bool check_eof(char *cursor); //проверка до конца строки

int main() {
  int res;
  char str[30];
  char *cursor = str;
  char *cursor2 = str;
  double data[3];
  double x, y, radius;

  fgets(str, sizeof(str), stdin);

  if (search_brecket(cursor) == 0) { //поиск '('
    res = 0;
  }
  if (search_brecket2(cursor) == 0) { //поиск ')'
    res = 0;
  }
  if (res == 0) {
    printf("Correct\n");
  }
  system("pause");
}
bool search_brecket(char *cursor) {
  int flag = 0;

  while (*cursor != 10) {
    if (*cursor == '(') {
      flag = 1;
      break;
    }
    cursor++;
  }
  if (flag == 0) {
    printf("expected '('\n");
    return false;
  }
  return true;
}
bool search_brecket2(char *cursor) {
  int flag = 0;

  while (*cursor != 10) {
    if (*cursor == ')') {
      flag = 1;
      break;
    }
    cursor++;
  }
  if (flag == 0) {
    printf("expected ')'\n");
    return false;
  }
  return true;
}
